
#include "sharedspice.h"
#include <iostream>
#include "main.h"
#if defined(USE_CUMSTOMIZED_LIB)
#include "test.h"
#endif
using namespace std;
int add(int a, int b) { return a + b; }

int main() {

  cout << add(4, 7) << endl;
  #if defined(USE_CUMSTOMIZED_LIB)
  cout << _sub(1,3) << endl;
  #endif
  return 0;
}