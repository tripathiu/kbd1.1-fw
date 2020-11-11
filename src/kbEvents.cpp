#include "kbEvents.h"

namespace kb {

Event::Event(EvtType type, EvtCtxt ctxt) : _type(type), _ctxt(ctxt) {}

EvtType Event::getEvtType() const {
  return _type;
}

EvtCtxt Event::getEvtCtxt() const {
  return _ctxt;
}

}  // namespace kb