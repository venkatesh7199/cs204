#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define N 100001
#define MP make_pair
#define PB push_back

ll colour [1000][1000]={0};
ll marked [1000][1000]={0};


ll dfs(ll x,ll y){

	if(marked[x][y])return 0;
	ll size=1;
	marked[x][y]=1;

	if(x>0 && colour[x-1][y]==colour[x][y]){
		size+=dfs(x-1,y);
	}

	if(y<1000 && colour[x][y+1]==colour[x][y]){
		size+=dfs(x,y+1);
	}
	
	if(x<1000 && colour[x+1][y]==colour[x][y]){
		size+=dfs(x+1,y);
	}
	
	if(y>0 && colour[x][y-1]==colour[x][y]){
		size+=dfs(x,y-1);
	}

return size;
	
}



int main(){

IOS

	ll n,m,k;
	cin>>n>>m;
	cin>>k;

	ll x,y;

	REP(i,0,k){

		cin>>x>>y;
		colour[x-1][y-1]=1;

	}

	/*REP(i,0,n){

		REP(j,0,m){
			
			cout<<colour[i][j]<<" ";
			
		}
		cout<<endl;

	}*/

	ll msize=0;

	ll csize=0;

	REP(i,0,n){

		REP(j,0,m){
			
			if(marked[i][j]==0 && colour[i][j]==1){

				csize=dfs(i,j);
				msize=max(csize,msize);
			}
			
		}

	}

	cout <<msize<<endl;

return 0;
}
