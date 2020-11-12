#include "kbOutput.h"

#include "kbDebug.h"

namespace kb {

KeySender::KeySender() {}

void KeySender::procEvent(const Event& evt) {
  std::cout << "[kbOUT] ";
  if (evt.getEvtType() == KeyDown) {
    std::cout << "Key Down: " + std::to_string(evt.getEvtCtxt());
  } else if (evt.getEvtType() == KeyRelease) {
    std::cout << "Key Release: " + std::to_string(evt.getEvtCtxt());
  } else if (evt.getEvtType() == KeyHold) {
    std::cout << "Key Hold: " + std::to_string(evt.getEvtCtxt());
  } else {
    std::cout << "Unrecognized Event";
  }
  std::cout << std::endl;
}

namespace Global {

std::vector<kb::Process*> process;
kb::KeySender keySender;

}  // namespace Global

}  // namespace kb
