#ifndef __C_CLASS_HELPER__
#define __C_CLASS_HELPER__

/****************************************************
 * C Class Helper 0.0.6                             *
 * ------------------------------------------------ *
 * Github Repository Address:                       *
 * - https://github.com/IsshikiHugh/C-Class-Helper  *
 ****************************************************/


/*** Config Part ************************************/

// Set 0 if you don't want to see logs.
// Set 1 if you want to see logs.
#define SHOW_LOGS 1

// MODE 0 : Logs will be write to 'CCH_log.txt' file.
// MODE 1 : Logs will be print to console (colorful for normal terminal).
// MODE 2 : Logs will be print to console (colorless but fine for CMD).
#define CCH_MODE 1

// Set 0 if you want to see normal format.
// Set 1 if you want it to be brief.
#define CCH_BRIEF 1

/****************************************************/

#include <stdio.h>
#include <string.h>

// This part is used to customize the 'OUTPUT'.
#if CCH_MODE == 0
    #define CCH_BLACK         ""
    #define CCH_RED           ""
    #define CCH_GREEN         ""
    #define CCH_YELLOW        ""
    #define CCH_BLUE          ""
    #define CCH_PURPLE        ""
    #define CCH_CYAN          ""
    #define CCH_WHITE         ""
    #define CCH_DEFAULT_COLOR ""
    
    #define OUTPUT(...) \
    do{ \
        if(1){ \
            FILE * CCH_fp = fopen("CCH_log.txt", "a"); \
            fprintf(CCH_fp, __VA_ARGS__); \
            fclose(CCH_fp); \
        } \
    }while(0)
#endif
#if CCH_MODE == 1
    #define CCH_BLACK           "\033[0;30m" 
    #define CCH_RED             "\033[0;31m" 
    #define CCH_GREEN           "\033[0;32m" 
    #define CCH_YELLOW          "\033[0;33m" 
    #define CCH_BLUE            "\033[0;34m" 
    #define CCH_PURPLE          "\033[0;35m" 
    #define CCH_CYAN            "\033[0;36m" 
    #define CCH_WHITE           "\033[0;37m"
    #define CCH_DEFAULT_COLOR   "\033[0m" 
    #define OUTPUT(...) \
    do{ \
        if(1){ \
            fprintf(stderr, __VA_ARGS__); \
        } \
    }while(0)
#endif
#if CCH_MODE == 2
    #define CCH_BLACK           ""
    #define CCH_RED             ""
    #define CCH_GREEN           ""
    #define CCH_YELLOW          ""
    #define CCH_BLUE            ""
    #define CCH_PURPLE          ""
    #define CCH_CYAN            ""
    #define CCH_WHITE           ""
    #define CCH_DEFAULT_COLOR   "" 
    #define OUTPUT(...) \
    do{ \
        if(1){ \
            fprintf(stderr, __VA_ARGS__); \
        } \
    }while(0)
#endif


// This part is used to print debug messages with a format like 'OUTPUT' needs.
#define PRINT_LINE() \
do{ \
    if(!CCH_BRIEF){ \
        OUTPUT(CCH_YELLOW "--------------------------------------------------------\n" CCH_DEFAULT_COLOR); \
    } \
}while(0)

// This part is used to print the head of the logs message.
#define PRINT_BEGAIN() \
do{ \
    if(!CCH_BRIEF){ \
        OUTPUT(CCH_YELLOW "\n=== >>" CCH_BLUE " [:CCH:] " CCH_YELLOW ">> ======================================\n" CCH_DEFAULT_COLOR); \
    } else { \
        OUTPUT(CCH_YELLOW "[CCH]"); \
    } \
}while(0)

// This part is used to print the location of the code printing the logs.
#define PRINT_LOCATION() \
do{ \
    if(!CCH_BRIEF){ \
        OUTPUT(CCH_YELLOW "+ +" CCH_BLUE " File @ [ " CCH_CYAN "%s" CCH_BLUE " ]\n" CCH_DEFAULT_COLOR, __FILE__); \
        OUTPUT(CCH_YELLOW "+ +" CCH_BLUE " Func @ [ " CCH_CYAN "%s()" CCH_BLUE " ] & Line @ [ " CCH_CYAN "%d" CCH_BLUE " ]\n" CCH_DEFAULT_COLOR, __FUNCTION__, __LINE__); \
        PRINT_LINE(); \
    } else { \
        OUTPUT(CCH_YELLOW " @ " CCH_BLUE "{" CCH_CYAN "%s" CCH_BLUE "}[" CCH_CYAN "%d" CCH_BLUE "]/" CCH_CYAN "%s()" CCH_BLUE ": ", __FILE__, __LINE__, __FUNCTION__); \
    } \
}while(0)


// This part is used to print the content of the logs.
#define PRINT_CONTENT(...) \
do{ \
    if(1){ \
        OUTPUT(CCH_GREEN __VA_ARGS__); \
        OUTPUT("\n" CCH_DEFAULT_COLOR); \
    } \
}while(0)

// This part is used to print the tail of the logs.
#define PRINT_END() \
do{ \
    if(!CCH_BRIEF){ \
        OUTPUT(CCH_YELLOW "====================================== << " CCH_BLUE "[:CCH:]" CCH_YELLOW " << ===\n\n" CCH_DEFAULT_COLOR); \
    } \
}while(0)

// The normal LOG macro function.
#define LOG(...) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        PRINT_CONTENT(__VA_ARGS__); \
        PRINT_END(); \
    } \
}while (0)

// The LOG macro function specially for variable.
#define SHOW_VAR(CCH_TYPE, CCH_VAR) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        if(!CCH_BRIEF) PRINT_CONTENT(CCH_BLUE "< Variable Monitor >" CCH_DEFAULT_COLOR); \
        PRINT_CONTENT("%s" CCH_BLUE " = " CCH_GREEN CCH_TYPE, #CCH_VAR, CCH_VAR); \
        PRINT_END(); \
    } \
}while(0)

// This part is uesd to print 1-d array.
#define PRINT_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_BEGIN, CCH_ARR_END) \
do{ \
    if(1){ \
        int CCH_IT; \
        OUTPUT(CCH_GREEN "%s" CCH_BLUE " = ", #CCH_ARR_NAME); \
        OUTPUT(CCH_RED "[");\
        for(CCH_IT = CCH_ARR_BEGIN; CCH_IT < CCH_ARR_END; ++CCH_IT){ \
            if(CCH_IT == CCH_ARR_END -1 ){ \
                OUTPUT(CCH_GREEN CCH_TYPE, CCH_ARR_NAME[CCH_IT]); \
                break; \
            } \
            OUTPUT(CCH_GREEN CCH_TYPE ", ", CCH_ARR_NAME[CCH_IT]); \
        } \
        OUTPUT(CCH_RED "]\n"); \
    } \
}while(0)

// This part is used to print N-d array.
#define PRINT_N_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ELEMENT_SIZE, CCH_SIZE) \
do{ \
    if(1){ \
        int CCH_IT; \
        char* CCH_BEGIN = (char*)CCH_ARR_NAME; \
        OUTPUT(CCH_GREEN "%s" CCH_BLUE " = ", #CCH_ARR_NAME); \
        OUTPUT(CCH_RED "["); \
        for(CCH_IT = 0; CCH_IT < CCH_SIZE; CCH_IT+=CCH_ELEMENT_SIZE){ \
            if(CCH_IT == CCH_SIZE - CCH_ELEMENT_SIZE ) {OUTPUT(CCH_GREEN CCH_TYPE, CCH_BEGIN[CCH_IT]); break;} \
            OUTPUT(CCH_GREEN CCH_TYPE ", ", CCH_BEGIN[CCH_IT]);} \
        OUTPUT(CCH_RED "]\n"); \
    } \
}while(0)

// This part is used to print 2-d array/
#define PRINT_2_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_ROW_NUM, CCH_ARR_COL_NUM) \
do{ \
    if(1){ \
        int CCH_IT_ROW; \
        OUTPUT(CCH_GREEN "%s" CCH_BLUE " = \n", #CCH_ARR_NAME); \
        OUTPUT(CCH_RED "[");\
        for(CCH_IT_ROW = 0; CCH_IT_ROW < CCH_ARR_ROW_NUM; ++CCH_IT_ROW){             \
            int CCH_IT_COL; \
            if(CCH_IT_ROW == 0 ) OUTPUT(CCH_RED "["); \
            else OUTPUT(CCH_RED " ["); \
            for(CCH_IT_COL = 0; CCH_IT_COL < CCH_ARR_COL_NUM; ++CCH_IT_COL){ \
                if(CCH_IT_COL == CCH_ARR_COL_NUM - 1 ) {OUTPUT(CCH_GREEN CCH_TYPE, CCH_ARR_NAME[CCH_IT_ROW][CCH_IT_COL]); break;} \
                OUTPUT(CCH_GREEN CCH_TYPE ", ", CCH_ARR_NAME[CCH_IT_ROW][CCH_IT_COL]); \
            } \
            if(CCH_IT_ROW == CCH_ARR_ROW_NUM - 1 ) {OUTPUT(CCH_RED "]");break;} \
            OUTPUT(CCH_RED "],\n"); \
        } \
        OUTPUT(CCH_RED "]\n"); \
    } \
}while(0)

// The LOG macro function specially for 1-d array.
#define SHOW_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_BEGIN, CCH_ARR_END) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        if(!CCH_BRIEF) PRINT_CONTENT(CCH_BLUE "< Array Monitor >" CCH_DEFAULT_COLOR); \
        PRINT_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_BEGIN, CCH_ARR_END); \
        PRINT_END(); \
    } \
}while(0)

// The LOG macro function specially for N-d array.
#define SHOW_N_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ELEMENT_SIZE, CCH_SIZE) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        if(!CCH_BRIEF) PRINT_CONTENT(CCH_BLUE "< Array Monitor >" CCH_DEFAULT_COLOR); \
        PRINT_N_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ELEMENT_SIZE, CCH_SIZE); \
        PRINT_END(); \
    } \
}while(0)

// The LOG macro function specially for 2-d array.
#define SHOW_2_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_ROW_NUM, CCH_ARR_COL_NUM) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        if(!CCH_BRIEF) PRINT_CONTENT(CCH_BLUE "< Array Monitor >" CCH_DEFAULT_COLOR); \
        PRINT_2_ARR(CCH_TYPE, CCH_ARR_NAME, CCH_ARR_ROW_NUM, CCH_ARR_COL_NUM); \
        PRINT_END(); \
    } \
}while(0)

#endif
