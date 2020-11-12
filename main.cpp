#include <queue>
#include <thread>
#include <vector>

#include "kbDebug.h"
#include "kbEventDispatcher.h"
#include "kbEvents.h"
#include "kbKeyMatrix.h"
#include "kbOutput.h"

int main() {
  using namespace kb;

  Debug::print("Hello World");

  Global::process.push_back(&Global::keySender);

  std::thread ks([&]() { Global::keySender.popQ(); });

  Event evKd = Map::getEvent(Map::XY{1, 3});
  Event evKr = Map::getEvent(Map::XY{2, 4});
  Event evKh = Map::getEvent(Map::XY{3, 6});

  std::vector<Event> list = {evKd, evKr, evKh};

  for (auto& evt : list) {
    dispatch(evt);
  }

  ks.join();

  return 0;
}