#include "proc/kbSystem.h"

#include "kbDebug.h"

namespace kb {
namespace System {

std::vector<Process*> process;
KeySender keySender;

void init() {
  System::process.push_back(&System::keySender);
  std::thread ks([&]() { System::keySender.run(); });
  ks.detach();
}

bool dispatchEvt(const Event& evt) {
  for (auto& proc : process) {
    proc->procEvent(evt);
  }
  return true;
}

void wait() {
  while (1) {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1s);
  }
}

}  // namespace System
}  // namespace kb
