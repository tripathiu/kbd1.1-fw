#pragma once

#include <vector>

#include "kbOutput.h"
#include "kbProcess.h"

namespace kb {
namespace Global {

extern std::vector<kb::Process*> process;

// processes
extern kb::KeySender keySender;

}  // namespace Global
}  // namespace kb
