# include <bits/stdc++.h>

using namespace std;

# define ll long long
# define REP(i,a,b) for (ll i = a; i < b; i++)

int main(){

	ll n, q;

	cin>>n;

	ll dp[2*n+1];

	REP(i, 0, n){

		dp[i]=0;

	}

	dp[n]=1;

	REP (i, n+1, 2*n+1){

		dp[i]=(dp[i-3]+dp[i-6]+dp[i-7])%10000001;

	}

	cin>>q;

	int a;
	ll b, x;

	REP (i, 0, q){
		cin>>a;
		cin>>b;

		if(a==1){

			x=n-b;
		}
		else{
			x=b-1;
		}

		cout<<dp[x+n]<<endl;

	}

}