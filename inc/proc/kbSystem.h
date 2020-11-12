#pragma once

#include <vector>

#include "output/kbKeySender.h"
#include "proc/kbProcess.h"

namespace kb {
namespace System {

// processes
extern std::vector<kb::Process*> process;
extern kb::KeySender keySender;

// functions
void init();
bool dispatchEvt(const Event&);
void wait();

}  // namespace System
}  // namespace kb
