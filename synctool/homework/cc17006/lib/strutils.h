#ifndef __51CC__
#define __51CC__

#include <string.h>

#include <string>
#include <vector>
using namespace std;


int startswith(string lhs, string rhs);

int endswith(string lhs, string rhs);

/*
intstr="a,bc,cc,ddd,eff", separator=","
{"a", "bc", "cc", "dd", "eff"}
*/

int split(string inputstr, string separator, 
        vector<string>& ret);

int join(vector<string> strvec, string separator,
        string& ret);

#endif
