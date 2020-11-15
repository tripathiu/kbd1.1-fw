#pragma once

#include <iostream>

#include "kbKeyMatrix.h"
#include "proc/kbProcess.h"
#include "proc/kbSystemFcns.h"

namespace kb {

class KeyInput : public Process {
 public:
  KeyInput();
  void procEvent(const Event&) final;

 private:
  void _sendEvent(EvtType, Map::XY);
  void _setup() final;
  void _loop() final;
};

}  // namespace kb