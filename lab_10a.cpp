#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define N 1000001

int ctr=-1;
int flag=0;

vector <ll> v[N];
ll marked [N]={0};
ll part [N]={0}; 

void dfs(ll x){

	if(marked[x])return;
	marked[x]=1;
	part[x]=ctr;
	
	if(ctr==1)ctr=-1;
	else ctr=1;

	REP(i,0,v[x].size()){

		if(part[v[x][i]]==part[x]){
			flag=1;
			return;
		}
		else{
			dfs(v[x][i]);
		}

	}

}


int main(){

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin>>n>>m;

    ll v1,v2;

    REP(i,0,m){

    	cin>>v1>>v2;
    	v[v1].push_back(v2);
    	v[v2].push_back(v1);

    }

    REP(i,1,n+1){
        dfs(i);
    }

    //cout<<flag<<" flag"<<endl;

    REP(i,1,n+1){
    	if(marked[i]==0){
    		flag=1;
    	}
        //cout<<marked[i]<<endl;
    }

    if(flag){
    	cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;




return 0;
}
