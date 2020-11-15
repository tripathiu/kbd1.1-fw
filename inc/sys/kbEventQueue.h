#pragma once

#include <queue>

#include "kbEvents.h"

namespace kb {

class EventQueue {
 protected:
  void _pushQ(const Event& evt) { _evtQ.push(evt); }

  Event _popQ() {
    if (_sizeQ() > 0) {
      Event front = _evtQ.front();
      _evtQ.pop();
      return front;
    }
    return Event(EvtType::Error, 10);
  }

  size_t _sizeQ() { return _evtQ.size(); }

 private:
  using Queue = std::queue<Event>;
  Queue _evtQ;
};

}  // namespace kb