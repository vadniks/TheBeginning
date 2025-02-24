/*************************************************
 **  Created by Vad Nik on 29-Sep-18.
 *************************************************/

#ifndef NOTES_ILLEGALSTATEEXCEPTION_H
#define NOTES_ILLEGALSTATEEXCEPTION_H

#include <exception>
#include "consts.h"

using namespace std;

class IllegalStateException: public exception
{

public:
    const char * what() const noexcept override;
};


#endif //NOTES_ILLEGALSTATEEXCEPTION_H
