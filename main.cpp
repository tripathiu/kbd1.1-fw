#include <queue>
#include <thread>
#include <vector>

#include "kbDebug.h"
#include "kbEvents.h"
#include "kbKeyMatrix.h"
#include "proc/kbSystem.h"

int main() {
  using namespace kb;

  Debug::print("Hello World");

  System::init();

  Event evKd = Map::getEvent(Map::XY{1, 3});
  Event evKr = Map::getEvent(Map::XY{2, 4});
  Event evKh = Map::getEvent(Map::XY{3, 6});

  std::vector<Event> list = {evKd, evKr, evKh};

  for (auto& evt : list) {
    System::dispatchEvt(evt);
  }

  System::wait();
  return 0;
}