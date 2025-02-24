/*************************************************
 **  Created by Vad Nik on 29-Sep-18.
 *************************************************/

#include "IllegalStateException.h"

const char *IllegalStateException::what() const noexcept
{
    return ILLEGAL_STATE_EXCEPTION;
}
