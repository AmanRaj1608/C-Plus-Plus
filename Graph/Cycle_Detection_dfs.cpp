#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define pb push_back
#define mod 1000000007
#define N 100005
vector<ll>v[N];
ll vis[N] = {0};


bool dfs(ll n,ll h)
{
	vis[n] = 1;
	for(auto xx : v[n])
	{
		if(!vis[xx]) 
		{
			if(dfs(xx,n)==true)
				return true;
		}
		else if(xx != h)
			return true;
	}
	return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,e;
		cin>>n>>e;
		for(int i=1;i<n+1;i++)
		{
			v[i].clear();
			vis[i] = 0;
		}
		ll x,y;
		for(int i=0;i<e;i++)
		{
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		if(!dfs(1,-1))
			cout<<"NO Cycle Detected\n";
		else 
			cout<<"Cycle is Detected\n";
    }
    
    return 0;
}
