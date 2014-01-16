// Print longest common subsequence of two strings

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string lcs(string s1, string s2)
{
	int l1=s1.length();
	int l2=s2.length();

	string res="";

	int** aux = new int*[l1+1];

	for(int i=0; i<l1+1; i++)
		aux[i] = new int[l2+1];

	for(int i=0; i<=l1; i++)
		aux[i][0]=0;

	for(int i=0; i<=l2; i++)
		aux[0][i]=0;

	for(int i=1; i<=l1; i++)
	{
		for(int j=1; j<=l2; j++)
		{
			if(s1[i-1] == s2[j-1])
				aux[i][j] = aux[i-1][j-1] + 1;
			else
				aux[i][j] = max(aux[i-1][j], aux[i][j-1]);
		}
	}

	for(int i=l1, j=l2; aux[i][j]>0;)
	{
		if(aux[i][j-1] == aux[i][j])
			j--;
		else if(aux[i-1][j] == aux[i][j])
			i--;
		else
		{
			res+=s1[i-1];
			i--;
			j--;
		}
	}

	reverse(res.begin(), res.end());

	return res;
}

int main()
{
	string s1, s2;
	s1="XMJYAUZ";
	s2="MZJAWXU";

	cout<<lcs(s1, s2)<<endl;
}
