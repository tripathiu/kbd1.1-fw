#pragma once

#include <queue>

#include "kbEvents.h"

namespace kb {

/*
 Each Process class contains an event queue and a proc event fcn
 */
class Process {
 public:
  virtual ~Process(){};
  virtual void procEvent(const Event&) = 0;
};


}  // namespace kb