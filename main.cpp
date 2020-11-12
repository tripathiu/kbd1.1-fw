#include <queue>
#include <thread>
#include <vector>

#include "kbDebug.h"
#include "kbEvents.h"
#include "kbKeyMatrix.h"
#include "proc/kbSystem.h"

int main() {
  using namespace kb;

  Debug::print("Hello World");

  System::init();
  System::wait();

  return 0;
}