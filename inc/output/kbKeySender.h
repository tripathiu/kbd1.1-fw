#pragma once

#include <vector>

#include "sys/kbEventQueue.h"
#include "sys/kbProcess.h"

namespace kb {

class KeySender : public Process, public EventQueue {
 public:
  KeySender();
  void procEvent(const Event&) final;

 private:
  void _setup() final;
  void _loop() final;
};

}  // namespace kb