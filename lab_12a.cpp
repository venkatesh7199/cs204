#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MP make_pair
#define PB push_back
#define N 100001
#define HOLE 1000000007

int main(){

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;
    bool flag=0;

    string s[n];
    string c;

    REP(i,0,n){
    	cin>>c;
    	s[i]=c;
    }

    sort(s,s+n);

    REP(i,0,n){

    	string str = s[i];

    	reverse(str.begin(), str.end()); 

    	if(str == s[i]) continue;

    	if(binary_search(s, s+n, str)){
    		cout<<"YES"<<endl;
    		flag=1;
    		break;
    	} 

    }

    if(!flag){
    	cout<<"NO"<<endl;
    }

return 0;
}