#include "output/kbKeySender.h"

#include "kbDebug.h"

namespace kb {

KeySender::KeySender() {}

void KeySender::procEvent(const Event& evt) {
  auto type = evt.getEvtType();
  if (type == KeyRelease || type == KeyDown || type == KeyHold) {
    _pushQ(evt);
  }
}

void KeySender::_setup() {}

void KeySender::_loop() {
  if (_sizeQ() > 0) {
    // get first event
    std::cout << "[kbOUT] Event[" << _sizeQ() << "] = ";

    Event evt = _popQ();

    // here is how the events are processed
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

}  // namespace kb
