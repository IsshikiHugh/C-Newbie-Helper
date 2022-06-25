#include "CClassHelper.h"


int main(){
    int a[10];
    int i = 0;
    for(i=0;i<10;++i){
        a[i] = i;
    }
    SHOW_ARR("%d",a,0,10);
    // #define SHOW_LOGS 0
}
