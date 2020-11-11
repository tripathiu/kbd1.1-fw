#include "kbEventDispatcher.h"

#include "kbDebug.h"

namespace kb {

bool EvtDispatcher::addToQueue(Event evt) {
  if (evt.getEvtType() == KeyDown)
    Debug::print("Key Down");
  else if (evt.getEvtType() == KeyRelease)
    Debug::print("Key Release");
  else if (evt.getEvtType() == KeyHold)
    Debug::print("Key Hold");
  else
    Debug::print("Unrecognized Event");
  return true;
}

}  // namespace kb