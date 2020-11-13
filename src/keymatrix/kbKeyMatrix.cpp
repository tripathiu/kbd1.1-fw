#include "kbKeyMatrix.h"

namespace kb {

Key::Key(KeyCode kc) : _keyCode(kc) {}

constexpr KeyCode Key::getKeyCode() const {
  return _keyCode;
}

Event Key::getEvent() const {
  if (_state == KeyState::Down) {
    return Event(KeyDown, _keyCode);
  } else if (_state == KeyState::Up) {
    return Event(KeyRelease, _keyCode);
  } else if (_state == KeyState::Held) {
    return Event(KeyHold, _keyCode);
  }
  return Event(Unknown, 0);
}

void Key::setState(KeyState state) {
  _state = state;
}

namespace Map {

kb::Key keyAtPos(XY xy) {
  for (auto& item : keyMtx) {
    if (item.first == xy) {
      return item.second;
    }
  }
  return Key(0);
}

}  // namespace Map

}  // namespace kb