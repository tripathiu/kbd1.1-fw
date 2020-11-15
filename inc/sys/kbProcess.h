#pragma once

#include <thread>

#include "kbEvents.h"

namespace kb {

/*
 Each Process class contains an event queue and a proc event fcn
 */
class Process {
 public:
  virtual ~Process(){};

  /*
   *  Start the process
   */
  void start() {
    _isRunning = true;
    _setup();
    while (1) {
      if (_isRunning) {
        _loop();
      }
      else {
        std::this_thread::sleep_for(std::chrono::seconds(1));
      }
    }
  }

  /*
   * Stop the process
   */
  void pause() { _isRunning = false; }

  /*
   * Should only be called as a thread
   */
  void run() {}

  /*
   * Filter and then do something with the events
   */
  virtual void procEvent(const Event&) = 0;

 protected:
  /*
   * Overload this to load the setup
   */
  virtual void _setup() = 0;

  /*
   * Overload this to load the loop
   */
  virtual void _loop() = 0;

  bool _isRunning = false;
};

}  // namespace kb