/*
first i need to know the distance between (TAG) and all chocolates and (AWSN), distance between each chocolate and other chocolate,
i store this values in (array path) , to know this i use (bfs) ,
then  i run (next_permutation)To experience all possibilities and know the minimum distance.
*/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef bitset<15>mask;
#define F first
#define S second
ll n,m,x,y,z,c=1,k,sol,t,sum,ans,l,r,xx,yy,b[1000000],path[106][106],dis[106][106];
vector<pair<ll,ll>>vp;
vector<ll>v;
pair<ll,pair<ll,ll> >pp[1000000];
pair<ll,ll>ap[100];
map<ll,ll>ma;
string s1,s2,s;
char cx,a[106][106];
ll dx[]= {1,-1,0,0},dy[]= {0,0,1,-1};
bool valid(ll x,ll y)
{
    return (x>=1&&x<=n&&y>=1&&y<=m&&a[x][y]!='#');
}
void bfs(ll x,ll y,ll id)
{

    queue<pair<ll,ll>>q;
    q.push({x,y});
    while(!q.empty())
    {
        xx=q.front().F,yy=q.front().S;
        q.pop();
        for(int i=0; i<4; i++)
        {
            ll ux=xx+dx[i],uy=yy+dy[i];
            if(dis[ux][uy]>0||!valid(ux,uy))continue;
            dis[ux][uy]=dis[xx][yy]+1;
            q.push({ux,uy});
            if(a[ux][uy]=='.'||a[ux][uy]=='T')continue;
            else if(a[ux][uy]=='W')
                path[id][15]=dis[ux][uy];
            else
            {
                int ss=a[ux][uy]-'C';
                path[id][ss]=dis[ux][uy];
            }
        }
    }
}
int main()
{
//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1; i<=n; i++)
            for(int q=1; q<=m; q++)
                cin>>a[i][q];
        for(int i=1; i<=n; i++)
        {
            for(int q=1; q<=m; q++)
            {
                if(a[i][q]=='T')
                    ap[0]= {i,q};
                if(a[i][q]=='C')
                {
                    ap[c]= {i,q};
                    a[i][q]+=c;
                    c++;
                }
                if(a[i][q]=='W')
                    ap[15]= {i,q};
            }
        }
        for(int i=0; i<c; i++)
        {
            memset(dis,0,sizeof dis);
            bfs(ap[i].F,ap[i].S,i);
        }
        for(int i=1; i<c; i++)
            v.push_back(i);
        ans=1e8;
        bool ansbol=0;
        if(v.size()==0)
        {
            if(path[0][15]==0)
                ansbol=1;
            ans=path[0][15];
        }
        else
        {
            do
            {
                sum=0;
                for(int i=0; i<v.size(); i++)
                {
                    if(i==0)
                    {
                        if(path[0][v[i]]==0&&ansbol==0)
                            ansbol=1;
                        sum+=path[0][v[i]];
                    }
                    else
                    {
                        if(path[v[i-1]][v[i]]==0&&ansbol==0)
                            ansbol=1;
                        sum+=path[v[i-1]][v[i]];
                    }
                }
                if(path[v[v.size()-1]][15]==0)
                    ansbol=1;
                sum+=path[v[v.size()-1]][15];
                ans=min(ans,sum);
                if(ansbol==1)break;
            }
            while(next_permutation(v.begin(),v.end()));
        }
        if(ansbol==0)
            cout<<ans<<endl;
        else
            cout<<"Mission Failed!"<<endl;
        v.clear();
        memset(ap,0,sizeof ap);
        memset(path,0,sizeof path);
        c=1;
    }
    return 0;
}
