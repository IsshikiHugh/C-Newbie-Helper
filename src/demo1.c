#include "CNewbieHelper.h"

int main(){
    LOG("(QWQ) I can be seen!");

    SET_CNH_SHOW(0);
    LOG("(QAQ) I can't be seen!");

    SET_CNH_SHOW(1);
    LOG("(QWQ) I can be seen!");
    return 0;
}