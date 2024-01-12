#include "thorin/plug/rise/rise.h"

#include <thorin/plugin.h>

using namespace thorin;

extern "C" THORIN_EXPORT Plugin thorin_get_plugin() {
    return {"rise", [](Normalizers& normalizers) { plug::rise::register_normalizers(normalizers); }, nullptr, nullptr};
}
