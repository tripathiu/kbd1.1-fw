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

 protected:
  virtual void pushToQ(const Event& evt) { _evtQ.push(evt); }
  virtual void popQ(){};

  EventQueue _evtQ;
};

}  // namespace kb