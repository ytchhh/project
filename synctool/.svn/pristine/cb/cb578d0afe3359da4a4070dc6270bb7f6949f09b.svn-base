#ifndef __LOGUTILS__
#define __LOGUTILS__

#include "singletontemplate.h"
#include <ostream>


class logutils: public LASingletonTemplateBase<logutils>
{
    public:
        logutils(){};
        int log(int priority, const char *format, ...);
        int infolog(const char *format, ...);
        int errlog(const char *format, ...);
        int warnlog(const char *format, ...);
        int debuglog(const char *format, ...);

        logutils& operator<<(char* str);
        logutils& operator<<(string str);
        logutils& operator<<(int lhs);
        
        typedef ostream&  (*eoltype)(ostream&);
        logutils& operator<<(eoltype eol)
        {
            return *this;
        }
};

static logutils& glogger = logutils::get_instance_ref();
#endif
