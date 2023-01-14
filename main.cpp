#include <iostream>
#include "sharedspice.h"
#include "test/test.h"
using namespace std;
int add(int a, int b) { 
  return a + b;
  }

  int main(){
    
    cout << add(4, 7) << endl;
    cout << add(4, 7) << endl;
    cout << _sub(1, 4) << endl;
    return 0;
  }