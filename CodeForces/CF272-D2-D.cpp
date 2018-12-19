#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef bitset<15>mask;
#define F first
#define S second
ll n,m,x,y,z,k,sol,sum,ans,l,r,xx,yy,a[1000000],b[1000000];
ll MOD;
vector<ll>v;
vector<ll>v2;
pair<ll,pair<ll,ll> >pp[1000000];
pair<ll,ll>p[1000000];
map<ll,vector<ll>>ma;
set<ll>s;
string s1,s2;
char c;
int main()
{
//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>x;
        s.insert(x);
        ma[x].push_back(i);
    }
     for(ll i=1;i<=n;i++)
    {
        cin>>x;
        s.insert(x);
        ma[x].push_back(i);
    }
    cin>>MOD;
    ans=1;
    for(auto i:s)
    {
        v=ma[i];
        sort(v.begin(),v.end());
        for(int q=1;q<v.size();q++)
        {
            if(v[q]==v[q-1])sum++;
        }
        for(ll q=0;q<v.size();q++)
        {
            if(sum>0&&(q+1)%2==0)
            {
                sum--;
                ans*=(q+1)/2;
                ans%=MOD;
                continue;
            }
          ans*=(q+1);
          ans%=MOD;
        }

    }
    cout<<ans<<endl;


    return 0;
}
