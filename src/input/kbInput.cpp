#include "input/kbInput.h"

namespace kb {

KeyInput::KeyInput() {}

void KeyInput::procEvent(const Event& evt) {}

void KeyInput::run() {
  while (std::cin) {
    int x, y;
    std::cin >> x >> y;
    _sendEvent(KeyDown, Map::XY{x, y});
  }
}

void KeyInput::_sendEvent(EvtType type, Map::XY pos) {
  Key currentKey = Map::keyAtPos(pos);
  currentKey.setState( KeyState::Down);
  Event ev = currentKey.getEvent();
  System::dispatchEvt(ev);
}

}  // namespace kb