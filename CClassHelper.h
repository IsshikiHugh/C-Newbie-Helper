#ifndef __C_CLASS_HELPER__
#define __C_CLASS_HELPER__

/****************************************************
 * C Class Helper 0.0.1                             *
 * ------------------------------------------------ *
 * Github Repository Address:                       *
 * - https://github.com/IsshikiHugh/C-Class-Helper  *
 ***************************************************/

#include <stdio.h>
#include <string.h>

#define SHOW_LOGS 1

// This part is used to print debug messages with a format like 'printf' needs.
#define PRINT_LINE() if(1){ printf("--------------------------------\n"); }
#define PRINT_DOUBLE_LINE() if(1){ printf("================================\n"); }
#define PRINT_BEGAIN() if(1){ printf("\n[:CCH:] >>>> >>>> >>>> >>>>\n"); PRINT_DOUBLE_LINE(); }
#define PRINT_LOCATION() if(1){ printf(":|: File @ [ %s ]\n:|: Line @ [ %d ] & Func @ [ %s ]\n", __FILE__, __LINE__, __FUNCTION__); PRINT_LINE(); }
#define PRINT_CONTANT(...) if(1){ printf(__VA_ARGS__); printf("\n"); }
#define PRINT_END() if(1){ PRINT_DOUBLE_LINE(); printf("<<<< <<<< <<<< <<<< [:CCH:]\n\n"); }
#define LOG(...) if(SHOW_LOGS){ PRINT_BEGAIN(); PRINT_LOCATION(); PRINT_CONTANT(__VA_ARGS__); PRINT_END(); }

#define SHOW_VAR(CCH_TYPE, CCH_VAR) if(SHOW_LOGS){ PRINT_BEGAIN(); PRINT_LOCATION(); PRINT_CONTANT("< Variable Monitor >"); PRINT_CONTANT("%s = "CCH_TYPE, #CCH_VAR, CCH_VAR); PRINT_END(); }

#define PRINT_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_BEGIN, CCH_ARR_END) if(1){ int CCH_IT; for(CCH_IT = CCH_ARR_BEGIN; CCH_IT < CCH_ARR_END; ++CCH_IT) printf("%s[%d] = "CCH_TYPE"\n", #CCH_ARR_NAME, CCH_IT, CCH_ARR_NAME[CCH_IT]); }
#define SHOW_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_BEGIN, CCH_ARR_END) if(SHOW_LOGS){ PRINT_BEGAIN(); PRINT_LOCATION(); PRINT_CONTANT("< Array Monitor >"); PRINT_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_BEGIN, CCH_ARR_END); PRINT_END(); }

#endif