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
  void run() final;

 private:
  void _sendEvent(EvtType, Map::XY);
};

}  // namespace kb