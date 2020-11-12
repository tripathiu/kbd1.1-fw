#include "kbOutput.h"

#include "kbDebug.h"

namespace kb {

KeySender::KeySender() {}

void KeySender::procEvent(const Event& evt) {
  auto type = evt.getEvtType();
  if (type == KeyRelease || type == KeyDown || type == KeyHold) {
    pushToQ(evt);
  }
}

void KeySender::popQ() {
  while (1) {
    if (_evtQ.size() > 0) {
      // here is how the events are processed
      Event evt = _evtQ.front();
      _evtQ.pop();
      std::cout << "[kbOUT] Event Popped: ";
      if (evt.getEvtType() == KeyDown) {
        std::cout << "Key Down: " + std::to_string(evt.getEvtCtxt());
      } else if (evt.getEvtType() == KeyRelease) {
        std::cout << "Key Release: " + std::to_string(evt.getEvtCtxt());
      } else if (evt.getEvtType() == KeyHold) {
        std::cout << "Key Hold: " + std::to_string(evt.getEvtCtxt());
      } else {
        std::cout << "Unrecognized Event";
      }
      std::cout << std::endl;
    }
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100ms);
  }
}

}  // namespace kb
