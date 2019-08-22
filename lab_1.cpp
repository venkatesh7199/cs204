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

string subtract(string a, string b){


      a=truncate(a);
      b=truncate(b);
      int carry=0;
      int flag=0;
      string ans;
      int sign=0;

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

            /*int jock = 0;
            for(int i=0; i<ans.length(); i++){

                        if(ans[i]>'0'){jock=i; break;}

            }

            ans=ans.substr(jock, a.length()-jock);
            */
      }

      else{

            string swp=a;
            a=b;
            b=swp;
            sign++;
            goto label;

      }
      ans=truncate(ans);

      if(sign) {
            cout<<ans<<endl;
            ans='-'+ans;
            cout<<ans<<endl;
      }

      return ans;
}

string multiply(string a, string b){


      int carry=0;
      string ans;
      string tans;

      int t;

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

       return ans;

}

string quotient(string a, string b){


      string quo;
      string rem;
      string tb;
      string ta;

      ta=a;

      for(int i=0; i<=a.length()-b.length(); i++){

            tb=b;

            for(int j=0; j<a.length()-b.length()-i; j++){

                  tb+='0';

            }
            int q=0;
            string tpro="0";
            for(int j=0; j<10; j++){

                  q=j;
                  if(q==9){string x="9"; tpro=multiply(x, tb);}
                  else {string x;
                  x+=q+1+'0';

                  tpro=multiply(tb, x);
                  string y;
                  y+=(q)+'0';

                  if(stringCompare(tpro,ta)){tpro=multiply(tb, y);break;}
                  }
            }

            quo+=q+'0';
            //cout<<"black"<<endl;
            //cout<<ta<<" "<<tpro<<" bang"<<quo<<endl;
            ta=subtract(ta, tpro);
            //cout<<ta<<" "<<tpro<<" "<<quo<<endl;

      }


      rem=ta;

      quo=truncate(quo);
      rem=truncate(rem);

      return quo;
}

string remainder(string a, string b){


      string quo;
      string rem;
      string tb;
      string ta;

      ta=a;

      for(int i=0; i<=a.length()-b.length(); i++){

            tb=b;

            for(int j=0; j<a.length()-b.length()-i; j++){

                  tb+='0';

            }
            int q=0;
            string tpro="0";
            for(int j=0; j<10; j++){

                  q=j;
                  if(q==9){string x="9"; tpro=multiply(x, tb);}
                  else {string x;
                  x+=q+1+'0';

                  tpro=multiply(tb, x);
                  string y;
                  y+=(q)+'0';

                  if(stringCompare(tpro,ta)){tpro=multiply(tb, y);break;}
                  }
            }

            quo+=q+'0';
            //cout<<"black"<<endl;
            //cout<<ta<<" "<<tpro<<" bang"<<quo<<endl;
            ta=subtract(ta, tpro);
            //cout<<ta<<" "<<tpro<<" "<<quo<<endl;

      }


      rem=ta;

      quo=truncate(quo);
      rem=truncate(rem);

      return rem;
}

string sqrot(string a){

      string left;
      string right;
      string middle;
      string divisor;
      divisor="2";

      left="0";
      right=a;

      while(stringCompare(right, left)){

            middle=add(left, right);
            middle=quotient(middle, divisor);
            if(truncate(left)==truncate(middle) || truncate(right)==truncate(middle))break;
            if(stringCompare(multiply(middle, middle), a)){
                  right=middle;
            }
            else if (truncate(multiply(middle, middle))!= truncate(a)){
                  left=middle;
            }
            else return middle;


      }

      return right;

}
string prime (string a){


      string counter;
      string incr;
      incr="1";

      string root=sqrot(a);

      if(truncate(multiply(root, root))==a){
            return "Not a Prime";

      }
      for (counter="2";stringCompare(root, counter); counter=add(counter, incr)){

            if(remainder(a, counter)=="0") {
                  return "Not a Prime";

            }
      }

      if (stringCompare(root, counter)==0 ){
            return "Prime";
      }

}

int main(){


      ios::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);

      string a;
      string b;
      string res;

      int t;
      cin>>t;

      int op;

      for(int g=0; g<t; g++){

            cin>>op;
            cin>>a;

            string quo;

            if(op==5){

                 res=prime(a);
            }
            else{

                  cin>>b;

                  switch (op){
                        case 1: res=add(a, b);
                                res=truncate(res);
                                break;
                        case 2: res=subtract(a, b);
                                break;
                        case 3: res=multiply(a, b);
                                res=truncate(res);
                                break;
                        case 4: quo=quotient(a, b);
                                res= remainder(a, b);
                                cout<<quo<<" ";
                                break;
                  }

            }

            cout<<res<<endl;
      }
}
