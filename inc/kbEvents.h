#pragma once

namespace kb {
/*
 * Type of event, add more if required
 */
enum EvtType {
  KeyDown,
  KeyHold,
  KeyRelease,
  Unknown,
};

/*
 * Context of event, meaning depends on event type
 */
using EvtCtxt = int;

/*
 * Type for events
 */
struct Event {
  Event(EvtType, EvtCtxt = 0);
  EvtType getEvtType() const;
  EvtCtxt getEvtCtxt() const;

 private:
  EvtType _type;
  EvtCtxt _ctxt;
};

}  // namespace kb
