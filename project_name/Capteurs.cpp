#include <iostream> 
#include "string.h"
#include "math.h"

#include "Capteurs.h"
#include "Peripheriques.h"

using namespace std;

class Capteurs : public Peripheriques{
  protected : 
    int pin;
  public : 
    Capteurs(int p) {p=pin};
    virtual int getValue() {};
}