#include "kbEventDispatcher.h"

#include "kbDebug.h"

namespace kb {

bool EvtDispatcher::addToQueue(Event evt) {
  if (evt.getEvtType() == KeyDown) {
    Debug::print("Key Down: " + std::to_string(evt.getEvtCtxt()));
  } else if (evt.getEvtType() == KeyRelease) {
    Debug::print("Key Release: " + std::to_string(evt.getEvtCtxt()));
  } else if (evt.getEvtType() == KeyHold) {
    Debug::print("Key Hold: " + std::to_string(evt.getEvtCtxt()));
  } else {
    Debug::print("Unrecognized Event");
  }
  return true;
}

}  // namespace kb