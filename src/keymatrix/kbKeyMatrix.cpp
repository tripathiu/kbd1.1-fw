#include "kbKeyMatrix.h"

namespace kb {
namespace Mapping {

Event getEvent(int row, int col) {
  if (row == 1)
    return Event(KeyDown, col);
  else if (row == 2)
    return Event(KeyHold, col);
  else
    return Event(KeyRelease, col);
}

}  // namespace Mapping
}  // namespace kb