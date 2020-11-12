#include "kbKeyMatrix.h"

namespace kb {
namespace Map {

Event getEvent(XY pos) {
  if (pos.row == 1)
    return Event(KeyDown, pos.col);
  else if (pos.row == 2)
    return Event(KeyHold, pos.col);
  else
    return Event(KeyRelease, pos.col);
}

}  // namespace Map
}  // namespace kb