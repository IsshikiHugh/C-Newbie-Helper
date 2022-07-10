#include "CNewbieHelper.h"

int main(){
    SET_CNH_BRIEF_MODE(0);
    LOG("Normal mode here!");
	BRIEF(
		LOG("Brief mode here!");
        LOG("Multiline is ok!");
	);
    LOG("Normal mode here!");

    SET_CNH_BRIEF_MODE(1);
	LOG("Brief mode here!");
    NORMAL(
		LOG("Normal mode here!");
        LOG("Multiline is ok!");
    );
	LOG("Brief mode here!");
    
    return 0;
}