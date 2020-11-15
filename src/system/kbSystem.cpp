#include "sys/kbSystem.h"

#include "kbDebug.h"
#include "sys/kbSystemFcns.h"

namespace kb {
namespace System {

std::vector<Process*> process;
KeySender keySender;
KeyInput keyInput;

void init() {
  System::process.push_back(&System::keySender);
  System::process.push_back(&System::keyInput);
  std::thread ks([&]() { System::keySender.run(); });
  std::thread ki([&]() { System::keyInput.run(); });
  ks.detach();
  ki.detach();
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
    // the main thread has nothing to do
    std::this_thread::sleep_for(1s);
  }
}

}  // namespace System
}  // namespace kb
