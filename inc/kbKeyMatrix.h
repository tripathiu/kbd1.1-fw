#pragma once

#include <iostream>
#include <vector>

#include "kbEvents.h"

namespace kb {
namespace Map {

struct XY {
  char row;
  char col;

  bool operator==(const XY& other) const {
    return (row == other.row && col == other.col);
  }
};

}  // namespace Map

using KeyCode = unsigned int;

enum class KeyState {
  Down,
  Up,
  Held,
};

class Key {
 public:
  Key(KeyCode);

  constexpr KeyCode getKeyCode() const;
  constexpr KeyState getState() const;

  Event getEvent() const;

 private:
  friend class KeyInput;
  void setState(KeyState);

  KeyCode _keyCode;
  Map::XY _pos;
  KeyState _state = KeyState::Up;
};

namespace Map {
/*
 *  Type to search all the keyz
 *  Find a better way to search algorithms
 */
using KeyMatrix = std::vector<std::pair<XY, Key>>;

/*
 * List of all the keys contained as a map of XY -> Keys
 * In later stages, use define statements for KeyCodes
 */

// clang-format off
static KeyMatrix keyMtx = {
                          {XY{1, 1}, Key(1)},
                          {XY{1, 2}, Key(2)},
                          {XY{1, 3}, Key(3)},
                          {XY{2, 1}, Key(4)},
                          {XY{2, 2}, Key(5)}, 
                          {XY{2, 3}, Key(6)},
                          {XY{3, 1}, Key(7)},
                          {XY{3, 2}, Key(8)},
                          {XY{3, 3}, Key(9)},
                          };
// clang-format on

kb::Key keyAtPos(XY);

}  // namespace Map

}  // namespace kb