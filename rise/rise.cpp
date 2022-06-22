#include "rise.h"

#include <thorin/config.h>
#include <thorin/pass/pass.h>

#include <thorin/dialects.h>

extern "C" THORIN_EXPORT thorin::DialectInfo thorin_get_dialect_info() {
    return {"rise", [](thorin::PipelineBuilder&) {}, nullptr, nullptr};
}
