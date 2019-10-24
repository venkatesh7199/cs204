#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

ll fn(ll x,ll rn[])
{
      if(rn[x]==x) return x;
      else rn[x]=fn(rn[x],rn);
}

void un(ll x,ll y,ll rn[],ll sz[])
{
      x=fn(x,rn);
      y=fn(y,rn);
      if(x==y) return;
      if(sz[x]<sz[y]) swap(x,y);
      sz[x]+=sz[y];
      rn[y]=x;
      return;
}

int main()
{
      ll n,m;
      cin>>n>>m;
      ll k;
      cin>>k;
      map<pair<ll,ll>,ll> mp;
      ll rn[k];
      ll sz[k];
      REP(i,0,k)
      {
            ll x,y;
            cin>>x>>y;
            mp[make_pair(x,y)]=i;
            rn[i]=i;
            sz[i]=1;
      }
      for(auto it:mp)
      {
            if(mp.count(make_pair((it.first).first+1,(it.first).second))==1) un(it.second,mp[make_pair((it.first).first+1,(it.first).second)],rn,sz);
            if(mp.count(make_pair((it.first).first-1,(it.first).second))==1) un(it.second,mp[make_pair((it.first).first-1,(it.first).second)],rn,sz);
            if(mp.count(make_pair((it.first).first,(it.first).second+1))==1) un(it.second,mp[make_pair((it.first).first,(it.first).second+1)],rn,sz);
            if(mp.count(make_pair((it.first).first,(it.first).second-1))==1) un(it.second,mp[make_pair((it.first).first,(it.first).second-1)],rn,sz);
      }
      ll max_siez=0;
      REP(i,0,k)
      {
            if(sz[i]>max_siez)
            {
                  max_siez=sz[i];
            }
      }
      cout<<max_siez;

      return 0;
}
