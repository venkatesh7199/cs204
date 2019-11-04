#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 1000001
#define HOLE 1000000007

ll power(ll x,ll y)
{
      ll res = 1; // Initialize result

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x)%HOLE;

        // n must be even now
        y = y >> 1; // y = y/2
        x = (x * x)%HOLE; // Change x to x^2
    }
    return res;
}

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
      ll t=1;

    REP(i,0,m){
      ll v3;
    	cin>>v1>>v2>>v3;
    	if(v3%2){
    	v[v1].push_back(v2);
    	v[v2].push_back(v1);
    	} else{

        v[n+t].push_back(v1);
        v[v1].push_back(n+t);
        v[v2].push_back(n+t);
        v[n+t].push_back(v2);

      t++;
    	}
    }

    REP(i,1,n+t+1){
        dfs(i);
    }

    //cout<<flag<<" flag"<<endl;


    if(flag){
    	cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;




return 0;
}
