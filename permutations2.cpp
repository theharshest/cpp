//All permuations of a string
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> perm(string s)
{
	int l = s.length();

	vector<string> res;

	if(l==2)
	{
		res.push_back(s);
		swap(s[0], s[1]);
		res.push_back(s);
		return res;
	}

	string first = s.substr(0, 1);
	string left = s.substr(1);

	vector<string> remain = perm(left);

	for(int i=0; i<remain.size(); i++)
	{
		for(int j=0; j<=remain[i].length(); j++)
		{
			string tmp = remain[i];
			tmp.insert(j, first);
			res.push_back(tmp);
		}
	}

	return res;
}

int main()
{
	string s = "abc";
	vector<string> v;

	v = perm(s);

	for(int i=0; i<v.size(); i++)
		cout<<v[i]<<endl;
}
