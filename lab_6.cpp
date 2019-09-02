#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main(){

	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int q;
    cin>>q;

    int c1[q];
    int c2[q];
    int c3[q];
    int user[q];
    ll money[q];
    int max =0;
    ll maxamt=0;

    REP(i, 0, q){

    	cin>>c1[i];
    	if(c1[i]==2){
    		c2[i]=-1;
    		user[i]=-1;
    		c3[i]=-1;
    	}
    	else{
    		cin>>c2[i];
    		user[i]=c2[i];
    		cin>>c3[i];
    	}

    }

    sort(user, user + q);

  /*  REP(i, 0, q){

    	cout<<user[i]<<endl;

    }
*/
    REP(i, 0, q){

    	money[i]=0;

    }

    REP(i, 0, q){

    	if(c1[i]==1){
    		int*pos=lower_bound(user, user+q, c2[i]);
    		money[pos-user]+=c3[i];
    		if(money[pos-user]>maxamt){
    			max=user[pos-user];
    			maxamt=money[pos-user];
    		}
    	}

    	else{
    		cout<<max<<endl;
    	}

    }

   /* REP(i, 0, q){

    	cout<<money[i]<<endl;

    }
*/



return 0;
}