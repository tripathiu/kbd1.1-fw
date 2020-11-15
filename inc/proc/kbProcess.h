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

  /*
   *  Start the process
   */
  void start() { _isRunning = true; }

  /*
   * Stop the process
   */
  void stop() { _isRunning = false; }

  /*
   * Should only be called as a thread
   */
  void run() {
    _isRunning = true;
    _setup();
    while (_isRunning) {
      _loop();
    }
  }

  /*
   * Filter and then push event to the event queue using _push(evt)
   */
  virtual void procEvent(const Event&) = 0;

 protected:
  void _push(const Event& evt) { _evtQ.push(evt); }

  /*
   * Overload this to load the setup
   */
  virtual void _setup() = 0;

  /*
   * Overload this to load the loop
   */
  virtual void _loop() = 0;

  EventQueue _evtQ;
  bool _isRunning = false;
};  // namespace kb

}  // namespace kb