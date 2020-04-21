#include "customErrorClass.h"


/**************************** PUBLIC: constructor ****************************/
myException::myException(void){
    this->p_ErrString = "ERROR: Program failed to execute correctly.";
    this->p_ErrCode = SYSTEM_FAILURE;
}

/**************************** PUBLIC: constructor ****************************/
myException::myException(const char* p_ErrString, e_CODES p_ErrCode){
    this->p_ErrString = p_ErrString;
    this->p_ErrCode = p_ErrCode;
}

/**************************** PUBLIC: constructor ****************************/
myException::myException(const string &p_ErrString, e_CODES p_ErrCode){
    this->p_ErrString = p_ErrString;
    this->p_ErrCode = p_ErrCode;
}

const e_CODES myException::increaseError(void){
    
    e_CODES retValue;
    
    if( INFORMATIONAL == this->p_ErrCode){
        retValue = WARNING;
    } else if( WARNING == this->p_ErrCode){
        retValue = ERROR;
    } else {
        retValue = SYSTEM_FAILURE;
    }
    return retValue;
}

/**************************** PRIVATE: retrieveError ****************************/
string myException::p_RetrieveError(void){
    if(this->p_ErrCode == INFORMATIONAL ){
        this->p_ErrString = GREY + string("INFO: ") +this->p_ErrString + CLOSE;
    } else if( this->p_ErrCode == WARNING ){
        this->p_ErrString = YELLOW + string("WARNING: ") +this->p_ErrString + CLOSE;
    } else if (this->p_ErrCode == ERROR ){
        this->p_ErrString = MAGENTA + string("ERROR: ") +this->p_ErrString + CLOSE;
    } else if (this->p_ErrCode == SYSTEM_FAILURE ){
        this->p_ErrString = RED + string("SYSTEM FAILURE: ") +this->p_ErrString + CLOSE;
    }

    return this->p_ErrString;
}