#pragma once

#include <vector>

#include "proc/kbProcess.h"

namespace kb {

class KeySender : public Process {
 public:
  KeySender();
  void procEvent(const Event&) final;

  void popQ() final;

 private:
};

}  // namespace kb