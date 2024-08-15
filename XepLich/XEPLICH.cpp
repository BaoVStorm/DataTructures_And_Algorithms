#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
long long a[maxn][maxn],f[maxn][maxn],n,m,d=0;
int main()
{
	freopen("abc.inp","r",stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		cin>>a[i][j]; 
	}
	for(int i=1;i<=n;i++)
	{
	for(int j=1;j<=m;j++)
	{
	if(i>j) f[i][j]=0;
	else if(i==j) f[i][j]=f[i-1][j-1]+a[i][j];
	
	else f[i][j]=max(f[i-1][j-1]+a[i][j],f[i][j-1]);
//	cout<<f[i][j]<<" ";
	}	
//	cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<f[i][j]<<"\t";
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++) d=max(d,f[n][i]); cout<<d;
}
