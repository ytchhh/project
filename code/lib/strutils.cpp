#include <vector>
using namespace std;

#include "strutils.h"

int startswith(string lhs, string rhs)	//判断rhs是否是lhs的开头
{
	if(lhs == NULL || rhs == NULL || strlen(rhs) <= strlen(lhs))
		return -1;
	
	int i = 0;
	while(rhs[i] == lhs[i] && rhs[i] != '\0' && lhs[i] != '\0')
		++i;
	if(rhs[i] != '\0')
		return -1;
    return 0;
}

int endswith(string lhs, string rhs)	//判断rhs是否是lhs的结尾
{
	if(lhs == NULL || rhs == NULL || strlen(rhs) <= strlen(lhs))
		return -1;
	int i = strlen(lhs) - strlen(rhs);
	int j = 0;
	while(lhs[i] == lhs[j] && rhs[i] != '\0' && lhs[i] != '\0')
	{
		++i;
		++j;
	}
	if(rhs[j] != '\0')
		return -1;
    return 0;
}

/*
intstr="a,bc,cc,ddd,eff", separator=","
{"a", "bc", "cc", "dd", "eff"}
*/

int split(string inputstr, string separator,
        vector<string>& ret) 			//将字符串分离
{
    //do something...
    //
	if(inputstr.size() == 0)
		return -1;
	
	string temp;
	int i = 0;
	while(inputstr[i] != '\0')
	{
		while(inputstr[i] != separator[0] && inputstr[i] != '\0')
    	{
   			temp += inputstr[i];
			++i;
		}
		ret.push_back(temp);
		++i;
	}
	
    return 0;
}

int join(vector<string> strvec, string separator, 
        string& ret)
{
    int i = 0;
	while(strvec[i] != '\0')
	{
		while(strvec[i] != separator[0] && strvec[i] != '\0')
		{
			ret += strvec[i];
			++i;
		}
		++i;
	}
	return 0; 
}
