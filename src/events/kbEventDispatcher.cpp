#include "kbEventDispatcher.h"

#include <queue>

#include "kbDebug.h"
#include "kbOutput.h"

namespace kb {

bool dispatch(Event evt) {
  for (auto& proc : Global::process) {
    proc->procEvent(evt);
  }
  return true;
}

}  // namespace kb