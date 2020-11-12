#pragma once

#include <vector>

#include "kbProcess.h"

namespace kb {

class KeySender : public Process {
 public:
  KeySender();
  void procEvent(const Event&) final;

  void popQ() final;

 private:
};

namespace Global {

extern std::vector<kb::Process*> process;
extern kb::KeySender keySender;

}  // namespace Global

}  // namespace kb