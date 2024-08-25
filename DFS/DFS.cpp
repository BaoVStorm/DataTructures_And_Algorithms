#include<bits/stdc++.h>
using namespace std;
int t=0, n, m ,dd[10000];
vector<int> Ke[10000];
void doc()
{
	freopen("DFS.inp", "r", stdin);
	cin >> n >> m;
	for(int i=1; i<=m; i++)
	{
		int u, v;
		cin >> u >> v;
		Ke[u].push_back(v);
		Ke[v].push_back(u);
	}
}
void dfs(int x)
{
    t++;
	dd[x] = t;
	for(int i = 0; i < Ke[x].size(); i++)
	{
		int v = Ke[x][i];
		if(dd[v] == 0)
			dfs(v);
	}
}
int main()
{
	int res = 0;
	freopen("DFS.out", "w", stdout);
	doc();
		for(int i = 1; i <= n; i++)
		if(dd[i] == 0)
		{
			dfs(i);
			res++;
	    }
	    cout << res;
	return 0;
}
