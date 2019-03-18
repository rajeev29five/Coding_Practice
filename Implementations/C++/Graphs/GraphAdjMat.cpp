//
// Code Contributor(s): Rajeev Ranjan
//

#include <iostream>

using namespace std;

int main()
{
	int v;
	cin>>v;
	int adjMat[v+1][v+1]={0}, e1, e2;
	for(int i = 1; i<v ; i++)
	{
		cin>>e1>>e2;
		adjMat[e1][e2] = 1;
		adjMat[e2][e1] = 1;
	}

	for(int i = 1; i<=v; i++)
	{
		for(int j = 1; j<=v; j++)
		{
			cout<<adjMat[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
//program ends
