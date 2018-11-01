
// Code Contributor(s) : Rajeev Ranjan

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int * computePrefix(string pat)
{
	int len = pat.length();
	int * prefix = new int[len];
	for(int i = 1, j = 0; i<pat.length(); i++)
	{
		while(j > 0 && pat[j] != pat[i])
		{
			j = prefix[j-1];
		}
		if(pat[j] == pat[i])
		{
			prefix[i] = ++j;
		}
		else
		{
			prefix[i] = j;
		}
	}
	return prefix;
}

void KMP(string s, string pat)
{
	int lenOfOrg = s.length();
	int lenOfPat = pat.length();
	int * prefix = computePrefix(pat);
	for(int i = 0, j = 0; i<lenOfOrg; i++)
	{
		while(j > 0 && s[i] != pat[j])
		{
			j = prefix[j-1];
		}
		if(s[i] == pat[j])
		{
			j++;
		}
		if(j == lenOfPat)
		{
			cout<<"Pattern starts at "<<i-lenOfPat+1<<" ends at "<<i<<endl;
			j = prefix[j-1];
		}
	}
}

int main()
{
	string s, pat;
	cin>>s>>pat;
	KMP(s, pat);
	return 0;
}
