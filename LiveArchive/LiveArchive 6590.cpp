/*
First i need path and each two adjacent character are not in  digraphs list  and the path maybe cycle or not ,to get the path ,create a map of vector
(m) and in each character we store has adjacent character for it  ( are not in  digraphs list ) then run dfs on this map to get the path
if the path become cycle we can  print a square of character (20*20) if is not a cycle we can print a square of character from ((path length /2)*(path length/2)).
*/
#include <bits/stdc++.h>
using namespace std;
typedef int  ll;
typedef bitset<15>mask;
#define F first
#define S second
ll n,x,y,z,k,sol,sum,ans,l,r,xx,yy,a[1000000],b[1000000],t=0;
vector<string>v;
vector<char>v2;
vector<char>v3;
vector<char>anss;
vector<char>anss2;
pair<ll,pair<ll,ll> >pp[1000000];
pair<ll,ll>p[1000000];
map<string,ll>ma;
map<char,vector<char>>m;
map<char,bool>bol;
string s1,s2,s;
char c;
bool b1=0;
void dfs(char cc,char target)
{
    if(b1==1)return ;
    bol[cc]=1;
    v2.push_back(cc);
    v3.push_back(cc);
    for(int i=0; i<m[cc].size(); i++)
    {
        char cx=m[cc][i];
        if(bol[cx]&&cx!=target)continue;
        if(cx==target)
        {
            anss=v2;
            b1=1;
        }
        dfs(cx,target);
        bol[cx]=0;
    }
    v2.pop_back();
    if(v3.size()>anss2.size())anss2=v3;
    v3.pop_back();
}
int main()
{
//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>t;
    while(t--)
    {
        b1=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            ma[s]=1;
        }
        s="";
        for(char i='a'; i<='z'; i++)
        {
            for(char q='a'; q<='z'; q++)
            {
                s+=i;
                s+=q;
                if(ma[s]==0)
                {
                    v.push_back(s);
                    m[i].push_back(q);

                }
                s="";
            }
        }
        for(char i='a'; i<='z'; i++)
        {
            b1=0;
            dfs(i,i);
            v2.clear();
            v3.clear();
            for(char q='a'; q<='z'; q++)bol[q]=0;
            if(anss.size()>0)
                break;
        }
        if(anss.size()>0)
        {
            int lenp=anss.size();
            for (int i = 0; i < 20; ++i)
            {
                int ss = i % lenp;
                for (int j = 0; j < 20; ++j)
                {
                    printf("%c",anss[(ss+j)%lenp]);
                }
                puts("");
            }
        }
        else
        {
            xx=(anss2.size()+1)/2;
            for(int i=0; i<xx; i++)
            {
                for(int q=0; q<xx; q++)
                {
                    cout<<anss2[q+i];
                }
                cout<<endl;
            }
        }
        for(char q='a'; q<='z'; q++)bol[q]=0;
        for(char q='a'; q<='z'; q++)m[q].clear();
        for(char i='a'; i<='z'; i++)
        {
            for(char q='a'; q<='z'; q++)
            {
                s="";
                s+=i;
                s+=q;
                ma[s]=0;
            }
        }
        v2.clear();
        anss.clear();
        v.clear();
        anss2.clear();
        v3.clear();
    }
    return 0;
}
