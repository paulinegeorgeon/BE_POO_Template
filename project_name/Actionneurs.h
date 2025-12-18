#include <iostream> 
#include "string.h"
#include "math.h"

#include "Peripheriques.h"

using namespace std;

class Actionneurs : public Peripheriques{
  protected : 
    int pin;
  public : 
    Actionneurs(int p) {p=pin};
    virtual void initialiser() =0;
    virtual void eteindre() =0;
}