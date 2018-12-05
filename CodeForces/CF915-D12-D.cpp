/*
First i need the path has a cycle to do this i use (dfs) and create three  variable white if node in current path  ( in vector (v) ) and
blue if i visit the node but now out of vector (v) and black if node has not visited yet and after get the path we should try find the edge
has create this cycle and i change the value of variable to avoid reset the visit array (vis[]) in each once.
*/
#include <bits/stdc++.h>
using namespace std;
typedef int  ll;
typedef bitset<15>mask;
#define F first
#define S second
ll n,m,x,y,z,k,sol,sum,l,r,xx,yy,a[1000000],b[1000000];
ll black =0,white=1,blue=2,startt,endd;
vector<ll>v,path;
vector<ll>adj[1000000];
pair<ll,pair<ll,ll> >pp[1000000];
pair<ll,ll>p[1000000];
map<ll,ll>ma;
string s1,s2,s;
ll vis[1000000];
bool cycle,in;
void dfs(ll no)
{
    vis[no]=white;
    v.push_back(no);
    for(int i=0; i<adj[no].size(); i++)
    {
        ll cx =adj[no][i];
        if(no==startt&&cx==endd) continue;
        if(vis[cx]!=white&&vis[cx]!=blue)
            dfs(cx);
        else if(vis[cx]==white)
        {
            if(in==true)
            {
                v.push_back(cx);
                path=v;
            }
            cycle=true;
        }
        if(cycle==true)return ;
    }
    vis[no]=blue;
    v.pop_back();
}
int main()
{
//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
    }
    in =1;
    for(int i=1; i<=n; i++)
    {
        if(cycle==true)break;
        if(vis[i]!=white&&vis[i]!=blue)
            dfs(i);
    }
    if(cycle==false)
    {
        cout<<"YES"<<endl;
        return 0;
    }
    in =false;
    for(int i=0; i<path.size()-1; i++)
    {
        startt=path[i];
        endd=path[i+1];
        white+=2;
        blue+=2;
        cycle=false;
        for(int q=1; q<=n; q++)
        {
            if(vis[q]!=white&&vis[q]!=blue)
                dfs(q);
            if(cycle==true) break;
        }
        if(cycle==false)
        {
            cout<<"YES"<<endl;
            return 0;
        }

    }
    cout<<"NO"<<endl;
    return 0;
}
