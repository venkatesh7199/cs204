#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

string reverse(string a){

      string b;
      for(int i=a.length()-1; i>=0; i--)b+=a[i];

      return b;


}

string add (string a, string b)
{
      int carry=0;
      string ans;

      if(a.length()<b.length())swap(a,b);

      for(int i=0; i<b.length(); i++){

            int sum=a[a.length()-i-1]-'0'+b[b.length()-i-1]-'0'+carry;
            ans+=sum%10+'0';
            carry=sum/10;
      }

       for(int i=b.length(); i<a.length(); i++){

                  int sum=a[a.length()-i-1]+carry-'0';
                  ans+=sum%10+carry+'0';
                  carry=sum/10;

       }
       if(carry)ans+=carry+'0';
      ans=reverse(ans);



      return ans;
}

int main(){

      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      string a;
      string b;
      int carry=0;
      string ans;
      string tans;

      int t;

      cin>>t;

      for(int g=0; g<t; g++){
            ans="";
            carry=0;
            tans="";
            cin >> a >> b;

            if(a.length()<b.length())swap(a,b);

            for(int i=0; i<b.length(); i++){
                  tans="";
                  carry=0;

                  for(int j=0; j<a.length(); j++){

                        int prod=(a[a.length()-j-1]-'0')*(b[b.length()-i-1]-'0')+carry;
                        tans+=prod%10+'0';
                        carry=prod/10;
                  }

                  tans=reverse(tans);

                  string t="0";
                  t[0]+=carry;
                  if(carry) tans =t+tans;

                  for (int j=0; j<i; j++){
                        tans+="0";
                  }

                  //cout<<tans<<endl;
                  ans=add(tans, ans);

            }

             cout<<ans<<endl;

      }
      return 0;
}
