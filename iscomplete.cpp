#include<iostream>

using namespace std;

bool iscomplete(string s, bool chk[])
{
	int l = s.length();

	if(l==0)
		return false;

	for(int i=0; i<l; i++)
		chk[s[i]-'a']=1;

	bool f=1;

	for(int i=0; i<26; i++)
	{
		if(!chk[i])
		{
			f=0;
			break;
		}
	}

	return f;
}

int main()
{
	bool chk[26]={};
	string s;

	getline(cin, s);

	bool f=iscomplete(s, chk);

	if(f)
		cout<<"Complete"<<endl;
	else
		cout<<"Incomplete"<<endl;
}
