#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

static bool hashing[num][M];
static ll prime[num];

ll order(char c)
{
    if(c>='a'&&c<='z')
    {
        return (ll)(c-'a'+1);
    }
    else
        return (ll)(c-'A'+27);
}

ll func(string &s,ll p,ll m)
{
    ll n=s.size();
    ll r=1;
    ll ans=0;
    REP(i,0,n)
    {
        ans+=(r*order(s[i]))%m;
        ans%=m;
        r*=p;
        r%=m;
    }
    return ans;
}

int main()
{
    prime[0]=53;
    prime[1]=2311;
    prime[2]=13331;
    prime[3]=123457;
    prime[4]=446141;
    ll n;
    cin>>n;
    vector<string> v;
    while(n--)
    {
        string s;
        cin>>s;
        string t=s;
        reverse(t.begin(),t.end());
        if(s!=t)
        {
            v.push_back(s);
            REP(j,0,num)
            {
                hashing[j][func(t,prime[j],M)]=true;
            }
        }
    }
    for(auto s:v)
    {
        bool flag=true;
        REP(j,0,num)
        {
            if(hashing[j][func(s,prime[j],M)]==false) flag=false;
        }
        if(flag==true)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";

    return 0;
}
