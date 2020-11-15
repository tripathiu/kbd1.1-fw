#pragma once

#include <vector>

#include "proc/kbProcess.h"

namespace kb {

class KeySender : public Process {
 public:
  KeySender();
  void procEvent(const Event&) final;

 private:
  void _setup() final;
  void _loop() final;
};

}  // namespace kb