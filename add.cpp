#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

string reverse(string a){

      string b;
      for(int i=a.length()-1; i>=0; i--)b+=a[i];

      return b;


}

int main()
{
      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);


      string a;
      string b;
      string res;
      int carry=0;
      string ans;

      int t;
      cin>>t;

      for(int g=0; g<t; g++){
            ans="";
            carry=0;
            cin >> a >> b;

            if(a.length()<b.length())swap(a,b);

            for(int i=0; i<b.length(); i++){

                  int sum=a[a.length()-i-1]-'0'+b[b.length()-i-1]-'0'+carry;
                  ans+=sum%10+'0';
                  carry=sum/10;
            }

             for(int i=b.length(); i<a.length(); i++){

                        int sum=a[a.length()-i-1]+carry-'0';
                        ans+=sum%10+'0';
                        carry=sum/10;

             }
             if(carry)ans+=carry+'0';
            ans=reverse(ans);

            cout<<ans<<endl;

      }

      return 0;
}
