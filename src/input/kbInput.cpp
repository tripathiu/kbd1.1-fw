#include "input/kbInput.h"

namespace kb {

KeyInput::KeyInput() {}

void KeyInput::procEvent(const Event& evt) {}

void KeyInput::run() {
  while (std::cin) {
    int type, x, y;
    std::cin >> type >> x >> y;
    switch (type) {
      case 0:
        _sendEvent(KeyDown, Map::XY{x, y});
        break;
      case 1:
        _sendEvent(KeyRelease, Map::XY{x, y});
        break;
      case 2:
        _sendEvent(KeyHold, Map::XY{x, y});
        break;
      default:
        _sendEvent(Unknown, Map::XY{x, y});
        break;
    }
  }
}

void KeyInput::_sendEvent(EvtType type, Map::XY pos) {
  int fakeCtxt = pos.row + pos.col;
  Event ev(type, fakeCtxt);
  System::dispatchEvt(ev);
}

}  // namespace kb