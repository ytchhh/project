#include <vector>
using namespace std;

#include "strutils.h"

int strutils::startswith(string lhs, string rhs)
{
    if(lhs.size()==0 && rhs.size()==0 && rhs.size()>=lhs.size())
    {
        return 0;
    }
    int i = 0;
    while(lhs[i]!='\0' && rhs[i]==lhs[i] && rhs[i]!='\0')
    {
        ++i;
    }

    if(rhs[i] != '\0')
    {
        return 0;
    }
    return 1;
}

int strutils::endswith(string lhs, string rhs)
{
    if(lhs.size()==0 && rhs.size() && rhs.size()>=lhs.size())
    {
        return 0;
    }
    int i = 0;
    int j = lhs.size()-rhs.size();
    while(lhs[j]!='\0' && rhs[i]!='\0' && lhs[j]==rhs[i])
    {
        ++i;
        ++j;
    }
    if(rhs[i] != '\0')
    {
        return 0;
    }
    return 1;
}

/*
   intstr="a,bc,cc,ddd,eff", separator=","
   {"a", "bc", "cc", "dd", "eff"}
   */

int strutils::split(string inputstr, string separator, vector<string>& ret)
{
    if(inputstr.size()==0 && separator.size()==0)
    {
        return -1;
    }
    char *token;
    string temp;
    char *str = (char*)inputstr.data();
    token = strtok(str,separator.c_str());
    temp = token;
    ret.push_back(temp);
    while(token != NULL)
    {
        token = strtok(NULL,separator.c_str());
        if(token != NULL)
        {
            temp = token;
            ret.push_back(temp);
        }
    }
    return 0;
}

int strutils::join(vector<string>& strvec, string separator, string& ret)
{
    if(strvec.size()==0)
    {
        return -1;
    }
    int i;
    string temp;
    for(i = 0; i < strvec.size(); ++i)
    {
        temp = strvec[i];
        ret += temp;
        ret += separator;
    }
    return 0; 
}

bool strutils::inlist(vector<string>& strlist, string& key)
{
    if(strlist.empty())
    {
        return 0;
    }
    for(vector<string>::iterator it = strlist.begin();
            it != strlist.end(); ++it)
    {
        if(key == (*it))
        {
            return 1;
        }
    }
    return 0;
}
