#pragma once

#include <vector>

#include "kbOutput.h"
#include "kbProcess.h"

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
