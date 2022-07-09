#include "CClassHelper.h"

void main(){
  double doubleArrayY[5] = {1.2, 2.3, 3.4, 4.5, 5.6};
  // Print the whole array.
  SHOW_ARR("%.2lf", doubleArrayY, 0, 5);
  // You can also print part of it.
  SHOW_ARR("%.2lf", doubleArrayY, 2, 4);
}