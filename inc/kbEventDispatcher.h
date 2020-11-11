#pragma once

#include "kbEvents.h"

namespace kb {

/*
 *  Singleton Event Dispatcher
 */
class EvtDispatcher {
 public:
  static EvtDispatcher& get() {
    static EvtDispatcher inst;
    return inst;
  }

  /*
   * Returns true is dispatch successful
   */
  bool addToQueue(Event);

 private:
  EvtDispatcher(){};
};

}  // namespace kb