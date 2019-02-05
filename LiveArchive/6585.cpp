/* in this i run Bfs algorithm on grid to know the maximum sum */
#include <bits/stdc++.h>
using namespace std;
typedef int  ll;
typedef bitset<10>mask;
#define F first
#define S second
ll n,m,x,y,z,k,sol,sum,ans,l,r,xx,yy,a[1000000],b[1000000],dx[]={1,1,-1,-1},dy[]={1,-1,1,-1};
vector<pair<ll,ll>>v;
vector<ll>v2;
pair<ll,pair<ll,ll> >pp[1000000];
pair<ll,ll>p[1000000];
map<ll,ll>ma;
string s1,s2,s;
char c[11][11];
bool valid1(ll i,ll q)
{
    return (i>=0&&i<10&&q>=0&&q<10&&c[i][q]=='B');
}
bool valid2(ll i,ll q)
{
    return (i>=0&&i<10&&q>=0&&q<10&&c[i][q]=='#');
}
void Bfs(ll i ,ll j)
{
    for(int q=0;q<4;q++)
    {
        if(!valid1(i+dx[q],j+dy[q]))continue;
        if(!valid2(i+dx[q]*2,j+dy[q]*2))continue;
        c[i+dx[q]][j+dy[q]]='#';
        c[i+dx[q]*2][j+dy[q]*2]='W';
        c[i][j]='#';
        sum++;
        dfs(i+dx[q]*2,j+dy[q]*2);
        c[i+dx[q]][j+dy[q]]='B';
        c[i+dx[q]*2][j+dy[q]*2]='#';
        c[i][j]='W';
        sum--;
    }
 // cout<<sum<<endl;
    ans=max(sum,ans);
    return;
}

int main()
{
//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 cin>>n;
 for(int tt=0;tt<n;tt++)
 {
     k=0;
     for(int i=0;i<10;i++)
     {
         for(int q=0;q<10;q++)
         {
             cin>>c[i][q];
             if(c[i][q]=='W')v.push_back({i,q});
         }
     }
     for(int i=0;i<v.size();i++)
     {
         ans=0;
         sum=0;
         dfs(v[i].F,v[i].S);
         k=max(ans,k);
     }
     v.clear();
     cout<<k<<endl;
 }

    return 0;
}
