#pragma once

#include "kbEvents.h"

namespace kb {
namespace System {

// functions
void init();
bool dispatchEvt(const Event&);
void wait();

}  // namespace System
}  // namespace kb