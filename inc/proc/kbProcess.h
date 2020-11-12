#pragma once

#include <queue>
#include <thread>

#include "kbEvents.h"

namespace kb {

/*
 Each Process class contains an event queue and a proc event fcn
 */
class Process {
  using EventQueue = std::queue<Event>;

 public:
  virtual ~Process(){};
  virtual void procEvent(const Event&) = 0;
  virtual void run(){};

 protected:
  void _push(const Event& evt) { _evtQ.push(evt); }

  EventQueue _evtQ;
};

}  // namespace kb