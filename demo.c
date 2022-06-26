#include <stdio.h>
#include "CClassHelper.h"

int main(){
    LOG("Program Start!");

    int myIntVar = 114514;
    double myDoubleVar = 1919.810;
    char myCharArr[] = "A test char arrary.";
    int myInt2Arr[3][4] = {{1,2,3,11},
                           {4,5,6,12},
                           {7,8,9,10}};

    LOG("This is a demo.");
    
    LOG("Display SHOW_VAR(): ");
    SHOW_VAR("%d", myIntVar);           // value
    SHOW_VAR("%p", &myIntVar);          // address
    SHOW_VAR("%.2lf", myDoubleVar);     // value
    SHOW_VAR("%p", &myDoubleVar);       // address
    
    LOG("Display SHOW_ARR: ");
    SHOW_ARR("%c", myCharArr, 0, 10);   // value
    SHOW_ARR("%d", myCharArr, 10, 20);  // ASCII
    
    LOG("Display SHOW_N_ARR: ");
    SHOW_N_ARR("%c", myCharArr, sizeof(char), sizeof(myCharArr));   // value
    SHOW_N_ARR("%d", myInt2Arr, sizeof(int), sizeof(myInt2Arr));  // ASCII
    
    LOG("Display SHOW_2_ARR: ");
    SHOW_2_ARR("%d", myInt2Arr, 3, 4);

    LOG("Program Finished!");
    return 0;
}
