#include <iostream> 
#include "string.h"
#include "math.h"

using namespace std;

class peripheriques{
  protected : 
    int pin;
  public: 
    peripheriques(int p){p=pin;};
    virtual ~peripheriques() {};
    virtual void initialiser () =0;
};