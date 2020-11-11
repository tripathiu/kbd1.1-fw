#include <vector>

#include "kbDebug.h"
#include "kbEventDispatcher.h"
#include "kbEvents.h"
#include "kbKeyMatrix.h"

int main() {
  kb::Debug::print("Hello World");

  kb::Event evKd = kb::Mapping::getEvent(1, 10);
  kb::Event evKr = kb::Mapping::getEvent(2, 10);
  kb::Event evKh = kb::Mapping::getEvent(3, 10);

  std::vector<kb::Event> list = {evKd, evKr, evKh};

  for (auto& evt : list) {
    kb::EvtDispatcher::get().addToQueue(evt);
  }

  return 0;
}