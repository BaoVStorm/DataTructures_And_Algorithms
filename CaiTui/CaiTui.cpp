#include<bits/stdc++.h>
using namespace std;
int m,n,W[100000],V[100000], L[10000][10000];
void doc()
{
	freopen("abc.inp","r",stdin);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>W[i]>>V[i];
	}
}
void xuly()
{
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(W[i]<=j)
		{
			L[i][j]=max(L[i-1][j],L[i-1][j-W[i]]+V[i]);
		}
		else
		{
			L[i][j]=L[i-1][j];
		}
	}
	cout<<L[m][n];
}
int main()
{
	doc();
	xuly();
	return 0;
}
