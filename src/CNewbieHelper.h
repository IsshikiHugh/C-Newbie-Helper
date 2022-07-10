#ifndef __C_NEWBIE_HELPER__
#define __C_NEWBIE_HELPER__

/****************************************************
 * C Newbie Helper 1.0                              *
 * ------------------------------------------------ *
 * Github Repository Address:                       *
 * - https://github.com/IsshikiHugh/C-Newbie-Helper *
 ****************************************************/

/*** Config Part ************************************/

// MODE 0 : Logs will be write to 'CNH_log.txt' file.
// MODE 1 : Logs will be print to console (colorful for normal terminal).
// MODE 2 : Logs will be print to console (colorless but fine for CMD).
#define CNH_MODE 1

/*** Source Code Part *******************************/

#include <stdio.h>

/*** Show Setting Part ******************************/

#define SHOW_LOGS CNH_SHOW_LOGS
static int CNH_SHOW_LOGS = 1;

// Be used to set whether the CNH will show or not.
// CNH will show by default.
#define SET_CNH_SHOW(CNH_SHOW_FLAG) \
do{ \
    CNH_SHOW_LOGS = CNH_SHOW_FLAG; \
}while(0)

/*** Mode Setting Part ******************************/

#define CNH_BRIEF CNH_USE_BRIEF_MODE
static int CNH_USE_BRIEF_MODE = 0;
static int CNH_TMP_USE_BRIEF_MODE = 0;

// Be used to set the default mode CNH will use while printing logs.
// CNH will use normal mode by default.
#define SET_CNH_BRIEF_MODE(CNH_BRIEF_FLAG) \
do{ \
    CNH_USE_BRIEF_MODE = CNH_TMP_USE_BRIEF_MODE = CNH_BRIEF_FLAG; \
}while(0)

// Force to use brief mode.
#define BRIEF(...) \
do{ \
    CNH_USE_BRIEF_MODE = 1;\
    __VA_ARGS__ \
    CNH_USE_BRIEF_MODE = CNH_TMP_USE_BRIEF_MODE;\
}while(0)

// Force to use normal mode.
#define NORMAL(...) \
do{ \
    CNH_USE_BRIEF_MODE = 0; \
    __VA_ARGS__; \
    CNH_USE_BRIEF_MODE = CNH_TMP_USE_BRIEF_MODE; \
}while(0)

// This part is used to customize the 'OUTPUT'.
#if CNH_MODE == 0
    #define CNH_BLACK         ""
    #define CNH_RED           ""
    #define CNH_GREEN         ""
    #define CNH_YELLOW        ""
    #define CNH_BLUE          ""
    #define CNH_PURPLE        ""
    #define CNH_CYAN          ""
    #define CNH_WHITE         ""
    #define CNH_DEFAULT_COLOR ""
    
    #define OUTPUT(...) \
    do{ \
        if(1){ \
            FILE * CNH_fp = fopen("CNH_log.txt", "a"); \
            fprintf(CNH_fp, __VA_ARGS__); \
            fclose(CNH_fp); \
        } \
    }while(0)
#endif
#if CNH_MODE == 1
    #define CNH_BLACK           "\033[0;30m" 
    #define CNH_RED             "\033[0;31m" 
    #define CNH_GREEN           "\033[0;32m" 
    #define CNH_YELLOW          "\033[0;33m" 
    #define CNH_BLUE            "\033[0;34m" 
    #define CNH_PURPLE          "\033[0;35m" 
    #define CNH_CYAN            "\033[0;36m" 
    #define CNH_WHITE           "\033[0;37m"
    #define CNH_DEFAULT_COLOR   "\033[0m" 
    #define OUTPUT(...) \
    do{ \
        if(1){ \
            fprintf(stderr, __VA_ARGS__); \
        } \
    }while(0)
#endif
#if CNH_MODE == 2
    #define CNH_BLACK           ""
    #define CNH_RED             ""
    #define CNH_GREEN           ""
    #define CNH_YELLOW          ""
    #define CNH_BLUE            ""
    #define CNH_PURPLE          ""
    #define CNH_CYAN            ""
    #define CNH_WHITE           ""
    #define CNH_DEFAULT_COLOR   "" 
    #define OUTPUT(...) \
    do{ \
        if(1){ \
            fprintf(stderr, __VA_ARGS__); \
        } \
    }while(0)
#endif

/*** Functional Part ********************************/

// This part is used to print debug messages with a format like 'OUTPUT' needs.
#define PRINT_LINE() \
do{ \
    if(!CNH_BRIEF){ \
        OUTPUT(CNH_YELLOW "--------------------------------------------------------\n" CNH_DEFAULT_COLOR); \
    } \
}while(0)

// This part is used to print the head of the logs message.
#define PRINT_BEGAIN() \
do{ \
    if(!CNH_BRIEF){ \
        OUTPUT(CNH_YELLOW "\n=== >>" CNH_BLUE " [:CNH:] " CNH_YELLOW ">> ======================================\n" CNH_DEFAULT_COLOR); \
    } else { \
        OUTPUT(CNH_YELLOW "[CNH]"); \
    } \
}while(0)

// This part is used to print the location of the code printing the logs.
#define PRINT_LOCATION() \
do{ \
    if(!CNH_BRIEF){ \
        OUTPUT(CNH_YELLOW "+ +" CNH_BLUE " File @ [ " CNH_CYAN "%s" CNH_BLUE " ]\n" CNH_DEFAULT_COLOR, __FILE__); \
        OUTPUT(CNH_YELLOW "+ +" CNH_BLUE " Func @ [ " CNH_CYAN "%s()" CNH_BLUE " ] & Line @ [ " CNH_CYAN "%d" CNH_BLUE " ]\n" CNH_DEFAULT_COLOR, __FUNCTION__, __LINE__); \
        PRINT_LINE(); \
    } else { \
        OUTPUT(CNH_YELLOW " @ " CNH_BLUE "{" CNH_CYAN "%s" CNH_BLUE "}[" CNH_CYAN "%d" CNH_BLUE "]/" CNH_CYAN "%s()" CNH_BLUE " : ", __FILE__, __LINE__, __FUNCTION__); \
    } \
}while(0)


// This part is used to print the content of the logs.
#define PRINT_CONTENT(...) \
do{ \
    if(1){ \
        OUTPUT(CNH_GREEN __VA_ARGS__); \
        OUTPUT("\n" CNH_DEFAULT_COLOR); \
    } \
}while(0)

// This part is used to print the tail of the logs.
#define PRINT_END() \
do{ \
    if(!CNH_BRIEF){ \
        OUTPUT(CNH_YELLOW "====================================== << " CNH_BLUE "[:CNH:]" CNH_YELLOW " << ===\n\n" CNH_DEFAULT_COLOR); \
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
#define SHOW_VAR(CNH_TYPE, CNH_VAR) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        if(!CNH_BRIEF) PRINT_CONTENT(CNH_BLUE "< Variable Monitor >" CNH_DEFAULT_COLOR); \
        PRINT_CONTENT("%s" CNH_BLUE " = " CNH_GREEN CNH_TYPE, #CNH_VAR, CNH_VAR); \
        PRINT_END(); \
    } \
}while(0)

// This part is uesd to print 1-d array.
#define PRINT_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ARR_BEGIN, CNH_ARR_END) \
do{ \
    if(1){ \
        int CNH_IT; \
        OUTPUT(CNH_GREEN "%s" CNH_BLUE " = ", #CNH_ARR_NAME); \
        OUTPUT(CNH_RED "[");\
        for(CNH_IT = CNH_ARR_BEGIN; CNH_IT < CNH_ARR_END; ++CNH_IT){ \
            if(CNH_IT == CNH_ARR_END -1 ){ \
                OUTPUT(CNH_GREEN CNH_TYPE, CNH_ARR_NAME[CNH_IT]); \
                break; \
            } \
            OUTPUT(CNH_GREEN CNH_TYPE ", ", CNH_ARR_NAME[CNH_IT]); \
        } \
        OUTPUT(CNH_RED "]\n"); \
    } \
}while(0)

// This part is used to print N-d array.
#define PRINT_N_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ELEMENT_SIZE, CNH_SIZE) \
do{ \
    if(1){ \
        int CNH_IT; \
        char* CNH_BEGIN = (char*)CNH_ARR_NAME; \
        OUTPUT(CNH_GREEN "%s" CNH_BLUE " = ", #CNH_ARR_NAME); \
        OUTPUT(CNH_RED "["); \
        for(CNH_IT = 0; CNH_IT < CNH_SIZE; CNH_IT+=CNH_ELEMENT_SIZE){ \
            if(CNH_IT == CNH_SIZE - CNH_ELEMENT_SIZE ) {OUTPUT(CNH_GREEN CNH_TYPE, CNH_BEGIN[CNH_IT]); break;} \
            OUTPUT(CNH_GREEN CNH_TYPE ", ", CNH_BEGIN[CNH_IT]);} \
        OUTPUT(CNH_RED "]\n"); \
    } \
}while(0)

// This part is used to print 2-d array/
#define PRINT_2_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ARR_ROW_NUM, CNH_ARR_COL_NUM) \
do{ \
    if(1){ \
        int CNH_IT_ROW; \
        OUTPUT(CNH_GREEN "%s" CNH_BLUE " = \n", #CNH_ARR_NAME); \
        OUTPUT(CNH_RED "[");\
        for(CNH_IT_ROW = 0; CNH_IT_ROW < CNH_ARR_ROW_NUM; ++CNH_IT_ROW){             \
            int CNH_IT_COL; \
            if(CNH_IT_ROW == 0 ) OUTPUT(CNH_RED "["); \
            else OUTPUT(CNH_RED " ["); \
            for(CNH_IT_COL = 0; CNH_IT_COL < CNH_ARR_COL_NUM; ++CNH_IT_COL){ \
                if(CNH_IT_COL == CNH_ARR_COL_NUM - 1 ) {OUTPUT(CNH_GREEN CNH_TYPE, CNH_ARR_NAME[CNH_IT_ROW][CNH_IT_COL]); break;} \
                OUTPUT(CNH_GREEN CNH_TYPE ", ", CNH_ARR_NAME[CNH_IT_ROW][CNH_IT_COL]); \
            } \
            if(CNH_IT_ROW == CNH_ARR_ROW_NUM - 1 ) {OUTPUT(CNH_RED "]");break;} \
            OUTPUT(CNH_RED "],\n"); \
        } \
        OUTPUT(CNH_RED "]\n"); \
    } \
}while(0)

// The LOG macro function specially for 1-d array.
#define SHOW_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ARR_BEGIN, CNH_ARR_END) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        if(!CNH_BRIEF) PRINT_CONTENT(CNH_BLUE "< Array Monitor >" CNH_DEFAULT_COLOR); \
        PRINT_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ARR_BEGIN, CNH_ARR_END); \
        PRINT_END(); \
    } \
}while(0)

// The LOG macro function specially for N-d array.
#define SHOW_N_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ELEMENT_SIZE, CNH_SIZE) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        if(!CNH_BRIEF) PRINT_CONTENT(CNH_BLUE "< Array Monitor >" CNH_DEFAULT_COLOR); \
        PRINT_N_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ELEMENT_SIZE, CNH_SIZE); \
        PRINT_END(); \
    } \
}while(0)

// The LOG macro function specially for 2-d array.
#define SHOW_2_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ARR_ROW_NUM, CNH_ARR_COL_NUM) \
do{ \
    if(SHOW_LOGS){ \
        PRINT_BEGAIN(); \
        PRINT_LOCATION(); \
        if(!CNH_BRIEF) PRINT_CONTENT(CNH_BLUE "< Array Monitor >" CNH_DEFAULT_COLOR); \
        PRINT_2_ARR(CNH_TYPE, CNH_ARR_NAME, CNH_ARR_ROW_NUM, CNH_ARR_COL_NUM); \
        PRINT_END(); \
    } \
}while(0)

#endif
