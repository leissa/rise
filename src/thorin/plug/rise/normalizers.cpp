#include <thorin/normalize.h>
#include <thorin/world.h>

#include "thorin/plug/rise/rise.h"

namespace thorin::plug::rise {

template<map op>
Ref normalize_map(Ref type, Ref callee, Ref arg) {
    auto& world = type->world();
    auto [f, xs] = arg->projs<2>();

    // map (n, T2, T3) (f, map (n, T1, T2) (g, ys)) -> map (n, T1, T3) (λx:T1.(f g x) ys)
    if constexpr (op == map::Pure) {
        if (auto map = match(map::Pure, xs)) {
            auto [g, ys] = map->args<2>();
            auto [n, T1, T2] = map->decurry()->args<3>();
            auto T3 = g->type()->as<Pi>()->dom();

            auto pi = world.pi(T1, T3);
            auto lam = world.mut_lam(pi);
            lam->app(true, f, world.app(g, lam->var())); // true filter: always inline

            return world.app(world.app(world.annex(map::Pure), {n, T1, T3}), {lam, ys});
        }
    }

    return world.raw_app(type, callee, arg);
}

THORIN_rise_NORMALIZER_IMPL

} // namespace thorin::rise
