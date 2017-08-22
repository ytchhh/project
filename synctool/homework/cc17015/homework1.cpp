#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;


int startswitch(string lhs,string rhs)
{
	if(lhs.length()<rhs.length())
		return 0;
	string::iterator lit=lhs.begin();
	string::iterator rit=rhs.begin();
	for(;rit!=rhs.end();++rit,++lit)
	{
		if(*lit!=*rit)
			return 0;
	}
	if(*lit!=' ')
		return 0;
	return 1;
}
int endswitch(string lhs,string rhs)
{
	reverse(lhs.begin(), lhs.end());
	reverse(rhs.begin(), rhs.end());
	if(!startswitch(lhs,rhs))
		return 0;
	return 1;

}
int split(string inputstr,string separator,vector<string> &ret)
{
	string tmp;
	string::iterator init=inputstr.begin();
	string::iterator seit=separator.begin();
	for(;init!=inputstr.end();++init)
	{
		for(seit=separator.begin();seit!=separator.end();++seit)
		{
			if(*init==*seit)
			{
				if(tmp.length()!=0)
					ret.push_back(tmp);
				tmp.clear();
				break;
			}
		}
		if(seit==separator.end())
			tmp+=*init;	
	}
	ret.push_back(tmp);
	return 1;
}
int join(vector<string> strvec,string separator,string &ret)
{
	string str;
	vector<string>::iterator it;
	for(it=strvec.begin();it!=strvec.end();++it)
	{
		str=*it;
		ret+=str+separator;

	}
}
int main()
{

	cout<<startswitch("this is a test","this")<<endl;;
	cout<<endswitch("this is a test","test")<<endl;

	vector<string> vt;
	split("this, is     a test",", ;",vt);
	vector<string>::iterator it;
	for(it=vt.begin();it!=vt.end();++it)
        {
		cout<<*it<<endl;
	}


	string str;
	join(vt," ",str);
	cout<<str<<endl;


	
	
}	
