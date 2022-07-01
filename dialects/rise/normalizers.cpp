#include "thorin/normalize.h"

#include "dialects/rise/rise.h"

namespace thorin::rise {

template<map op>
const Def* normalize_map(const Def* type, const Def* callee, const Def* arg, const Def* dbg) {
    auto& world = type->world();
    auto [f, xs] = arg->projs<2>();

    // map (n, T2, T3) (f, map (n, T1, T2) (g, ys)) -> map (n, T1, T3) (λx:T1.(f g x) ys)
    if constexpr (op == map::Pure) {
        if (auto map = match(map::Pure, xs)) {
            auto [g, ys] = map->args<2>();
            auto [n, T1, T2] = map->decurry()->args<3>();
            auto T3 = g->type()->as<Pi>()->dom();

            auto pi = world.pi(T1, T3);
            auto lam = world.nom_lam(pi, dbg);
            lam->app(true, f, world.app(g, lam->var()), dbg); // true filter: always inline

            return world.app(world.app(world.ax(map::Pure), {n, T1, T3}, dbg), {lam, ys}, dbg);
        }
    }

    return world.raw_app(callee, arg, dbg);
}

THORIN_rise_NORMALIZER_IMPL

} // namespace thorin::rise
