#ifndef __CUSTOM_ERROR_CLASS__H__
#define __CUSTOM_ERROR_CLASS__H__

#include <exception>
#include <iostream>

using namespace std;

typedef enum CODES{
    INFORMATIONAL,
    WARNING,
    ERROR,
    SYSTEM_FAILURE
}e_CODES;

#define         RED         "\033[1;31m"
#define         MAGENTA     "\033[1;35m"
#define         YELLOW      "\033[1;33m"
#define         GREY        "\033[1;37m"
#define         CLOSE       "\033[0m"


class myException : public exception {
    public:
        myException(void);
        myException(const char*, e_CODES=INFORMATIONAL);
        myException(const string&, e_CODES=INFORMATIONAL);
        const string what(){
            return this->p_RetrieveError();
        }
        const e_CODES retrieveCode(){
            return this->p_RetrieveCode();
        }
        const e_CODES increaseError();
    private:
        string p_ErrString;
        e_CODES p_ErrCode;

        string p_RetrieveError(void);
        e_CODES p_RetrieveCode(void){
            return this->p_ErrCode;
        }

};

#endif