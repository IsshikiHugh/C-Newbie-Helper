#include <stdio.h>
#include "CClassHelper.h"

int main(){
    LOG("Program Start!");

    int myIntVar = 114514;
    double myDoubleVar = 1919.810;
    char myCharArr[] = "A test char arrary.";
    
    LOG("This is a demo.");
    SHOW_VAR("%d", myIntVar);           // value
    SHOW_VAR("%p", &myIntVar);          // address
    SHOW_VAR("%.2lf", myDoubleVar);     // value
    SHOW_VAR("%p", &myDoubleVar);       // address
    SHOW_ARR("%c", myCharArr, 0, 10);   // value
    SHOW_ARR("%d", myCharArr, 10, 20);  // ASCII

    LOG("Program Finished!");
    return 0;
}
