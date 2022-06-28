#include "rise/rise.h"

#include <thorin/config.h>
#include <thorin/dialects.h>

extern "C" THORIN_EXPORT thorin::DialectInfo thorin_get_dialect_info() {
    return {"rise", [](thorin::PipelineBuilder&) {}, nullptr, nullptr};
}

namespace thorin::rise {

const Def* map_fusion(const Def* def) {
    World& world = def->world();

    if (auto map_f = match(map::Pure, def)) {
        auto [f, xs] = map_f->args<2>();
        if (auto map_g = match(map::Pure, xs)) {
            auto [g, ys] = map_g->args<2>();

            auto pi = world.pi(f->type()->as<Pi>()->dom(), g->type()->as<Pi>()->codom());
            auto lam = world.nom_lam(pi, nullptr);
            lam->app(false, f, world.app(g, lam->var()));
            return world.app(world.ax(map::Pure), {lam, xs});
        }
    }
    return def;
}

} // namespace thorin::rise
