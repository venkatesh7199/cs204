#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

bool Cmpr(string a, string b){

	string f =a+b;
	string s = b+a;

	return (f>s);

}

int main(){

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    int n;

 	cin >>q;

 	REP (i, 0, q){

 		cin>>n;
 		string arr[n];

 		REP(j, 0, n){

 			cin>>arr[j];

 		}

 		sort (arr, arr+n, Cmpr);

 		REP(j, 0, n){

 			cout<<arr[j];

 		}
 		cout<<endl;

 	}
    

return 0;
}