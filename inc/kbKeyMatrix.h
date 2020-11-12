#pragma once

#include "kbEvents.h"

namespace kb {
namespace Map {

struct XY {
  char row;
  char col;
};

Event getEvent(XY);

}  // namespace Map
}  // namespace kb