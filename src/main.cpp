#include <vector>

#include "kbDebug.h"
#include "kbEventDispatcher.h"
#include "kbEvents.h"

int main() {
  kb::Debug::print("Hello World");

  kb::Event evKd(kb::KeyDown);
  kb::Event evKr(kb::KeyRelease);
  kb::Event evKh(kb::KeyHold);

  std::vector<kb::Event> list = {evKd, evKr, evKh};

  for (auto& evt : list) {
    kb::EvtDispatcher::get().addToQueue(evt);
  }

  return 0;
}