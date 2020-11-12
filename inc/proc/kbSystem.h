#pragma once

#include <vector>

#include "input/kbInput.h"
#include "output/kbKeySender.h"
#include "proc/kbProcess.h"

namespace kb {
namespace System {

// processes
extern std::vector<kb::Process*> process;
extern KeySender keySender;
extern KeyInput keyInput;

}  // namespace System
}  // namespace kb
