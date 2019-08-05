#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

string reverse(string a){

      string b;
      for(int i=a.length()-1; i>=0; i--)b+=a[i];

      return b;


}

string truncate(string a){

      int t=0;
      int jock = 0;
            for(int i=0; i<a.length()-1; i++){

                        if(a[i]>'0'){jock=i;t=1; break;}

            }
            if(t==0)jock=a.length()-1;

      a=a.substr(jock, a.length()-jock);

      return a;

}

int stringCompare(string a, string b){

      a=truncate(a);
      b=truncate(b);

      if(a.length()>b.length())return 1;
      else if(a.length()<b.length())return 0;
      else {

            for(int i=0; i<a.length(); i++){

                  if(a[i]>b[i])return 1;
                  else if(b[i]>a[i])return 0;

            }


      }

      return 0;

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
      int flag=0;
      string ans;
      int sign=0;

      int t;
      cin>>t;

      for(int g=0; g<t; g++){

            cin >> a >> b;
            a=truncate(a);
            b=truncate(b);
            //cout<<a<<b<<endl;
            ans="";
            sign=0;
            carry=0;
            //cout<<stringCompare(a,b)<<endl;
            //if(a==b)cout<<"a=b"<<endl;

            label:
            if(stringCompare(a,b) || a==b){
            for(int i=0; i<b.length(); i++){
                  flag=0;
                  int diff=a[a.length()-i-1]-'0'-(b[b.length()-i-1]-'0')+carry;

                  if(diff<0){diff+=10;flag=1;}
                  ans+=diff+'0';
                  if (flag==1)diff-=10;
                  if(diff<0)carry=-1;
                  else carry=0;

            }



             for(int i=b.length(); i<a.length(); i++){
                  flag=0;
                  int diff=a[a.length()-i-1]+carry-'0';

                  if(diff<0){diff+=10;flag=1;}
                  ans+=diff+'0';
                  if (flag==1)diff-=10;
                  if(diff<0)carry=-1;
                  else carry=0;
             }
             if(carry)ans+=carry+'0';
            ans=reverse(ans);

            ans=truncate(ans);
            }

            else{

                  string swp=a;
                  a=b;
                  b=swp;
                  sign++;
                  goto label;

            }

            if(sign) ans='-'+ans;
            cout<<ans<<endl;

      }

      return 0;
}
