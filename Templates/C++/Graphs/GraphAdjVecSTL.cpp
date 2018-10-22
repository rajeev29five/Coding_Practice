//
// Code Contributor(s) : Rajeev Ranjan
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int v;
	cin>>v;
	vector<vector<int>> vec(v+1);
       	int start, end;
	for(int i = 1; i<v; i++)
	{
		cin>>start>>end;
		vec[start].push_back(end);
		vec[end].push_back(start);
	}
	for(int i = 1; i<=v; i++)
	{
		for(int j = 0; j<vec[i].size()-1; j++)
		{
			cout<<vec[i][j]<<"->";
		}
		cout<<vec[i][vec[i].size()-1]<<"->NULL"<<endl;
	}	
	return 0;
}
//program ends
