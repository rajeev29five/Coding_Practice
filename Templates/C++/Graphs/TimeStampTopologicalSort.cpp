//
// Code Contributor(s): Rajeev Ranjan
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int TIME;

void dfs(vector<vector<int>> v, int i,bool visited[], vector<pair<int ,pair<int, int>>> &time)
{
	visited[i] = true;
	int st = TIME++;
	for(auto j: v[i])
	{
		if(!visited[j])
			dfs(v, j, visited, time);
	}
	int ft = TIME++;
	// cout<<st<<"|"<<ft<<"|"<<i<<endl;
	time.push_back(make_pair(ft,make_pair(st, i)));
	// cout<<time[0].first<<"|"<<time[0].second.first<<"|"<<time[0].second.second<<endl;
}

int main(int argc, char const *argv[])
{
	int vertices, edges;
	cin>>vertices>>edges;
	vector<vector<int>> v(vertices+1);
	bool visited[vertices+1] = {false};
	vector<pair<int, pair<int, int>>> time;
	int start, end;
	for(int i = 1; i<=edges; i++)
	{
		cin>>start>>end;
		v[start].push_back(end);
	}
	for(int i = 1; i<=vertices; i++)
	{
		if(!visited[i])
		{
			dfs(v, i, visited, time);
		}
	}
	// for(int i = 0; i<time.size(); i++)
	// {
	// 	cout<<time[i].first<<"<-finishTime|"<<time[i].second.first<<"<-startTime|node->"<<time[i].second.second<<endl;
	// }
	sort(time.begin(),time.end(), greater<>());

	// for(int i = 0; i<time.size(); i++)
	// {
	// 	cout<<time[i].first<<"<-finishTime|"<<time[i].second.first<<"<-startTime|node->"<<time[i].second.second<<endl;
	// }

	for(int i = 0; i<time.size(); i++)
	{
		cout<<time[i].second.second<<" ";
	}
	cout<<endl;
	return 0;
}
//program ends
