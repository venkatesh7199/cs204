#include <bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;
#define INF std::numeric_limits<long long>::max()

struct tree {

      string val;
      struct tree *left;
      struct tree *right;

};

map<string, ll> var;
int flag=0;
ll stolla(string a){
      if(a[0]=='0'||a[0]=='1'||a[0]=='2'||a[0]=='3'||a[0]=='4'||a[0]=='5'||a[0]=='6'||a[0]=='7'||a[0]=='8'||a[0]=='9')return stoll(a);
      else if(var.find(a)==var.end() || var[a]==INF){flag=1;return INF;}
      else return var[a];
}

vector<string> postfix(string s){
      vector<string> output;
      stack<char> signs;
      REP(i,0,s.length()){

            if(s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='^'&&s[i]!='('&&s[i]!=')'){

                        string a;
                        ll j;
                        for(j=i; j<s.length(); j++){
                              if(s[j]!='+'&&s[j]!='-'&&s[j]!='*'&&s[j]!='/'&&s[j]!='^'&&s[j]!='('&&s[j]!=')')a+=s[j];
                              else break;
                        }
                        output.push_back(a);
                        i=j-1;

            } else if(s[i]=='+'||s[i]=='-'){
                  if((i==0&&s[i]=='-')||(i!=0&&s[i]=='-'&&(s[i-1] =='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='^'||s[i-1]=='('))){
                        signs.push('$');
                  } else{
                        if(signs.empty())signs.push(s[i]);
                        else {
                              while(!signs.empty()&&signs.top()!='('){
                                    string a;
                                    a+=signs.top();
                                    signs.pop();
                                    output.push_back(a);
                              }
                              signs.push(s[i]);
                        }
                  }
            } else if(s[i]=='*'||s[i]=='/'){
                  if(signs.empty())signs.push(s[i]);
                  else{
                        while(!signs.empty()&&signs.top()!='+'&&signs.top()!='-'&&signs.top()!='('){
                              string a;
                              a+=signs.top();
                              signs.pop();
                              output.push_back(a);
                        }
                        signs.push(s[i]);
                  }
            } else if(s[i]=='^'){
                  if(signs.empty())signs.push(s[i]);
                  else{
                        while(!signs.empty()&&(signs.top()=='$')){
                              string a;
                              a+=signs.top();
                              signs.pop();
                              output.push_back(a);
                        }
                        signs.push(s[i]);
                  }
            } else if(s[i]=='(')signs.push(s[i]);
            else if(s[i]==')'){
                  while(signs.top()!='('){
                              string a;
                              a+=signs.top();
                              signs.pop();
                              output.push_back(a);
                  }signs.pop();
            } else if(s[i]=='^'){
                  while(!signs.empty()&&signs.top()=='$'){
                        string a;
                        a+=signs.top();
                        signs.pop();
                        output.push_back(a);
                  }signs.push(s[i]);
            }
      }
      while(!signs.empty()){
            string a;
            a+=signs.top();
            signs.pop();
            output.push_back(a);
      }
      return output;
}

struct tree* createTree(){
      struct tree *temp=(struct tree*)malloc(sizeof(struct tree));
      temp->left=NULL;
      temp->right=NULL;
      return temp;
}

void makeTree(struct tree **root, vector<string> s){
      stack<struct tree *> a;
      REP(i,0,s.size()){
            if(s[i][0]!='+'&&s[i][0]!='-'&&s[i][0]!='*'&&s[i][0]!='/'&&s[i][0]!='^'&&s[i][0]!='$'){
                  struct tree *temp=createTree();
                  temp->val=s[i];
                  a.push(temp);
            } else {
                  if(s[i]!="$"){
                        struct tree *temp=createTree();
                        temp->val=s[i];
                        temp->right=a.top();
                        a.pop();
                        temp->left=a.top();
                        a.pop();
                        a.push(temp);
                  } else{
                        if(((a.top())->val)[0]=='$')(a.top())->val=(((a.top())->val).substr(1));

                        else (a.top())->val="$"+((a.top())->val);



                  }
            }
      }

      *root=a.top();

      return;


}

void inorder(struct tree*root){


      if(root==NULL)return;
      cout<<"lol"<<endl;
      inorder(root->left);
      cout<<root->val<<endl;
      inorder(root->right);
}

ll powe(ll a, ll b){
      if(b==0)return 1;
      else if(b<0)return 0;
      else return a*powe(a,b-1);
}

ll evaluate(struct tree *root){
      if(root->val=="+"){
            ll x=evaluate(root->left);
            if(flag)return INF;
            ll y=evaluate(root->right);
            if(flag)return INF;
            return x+y;
      }
      else if(root->val=="-"){
            ll x=evaluate(root->left);
            if(flag)return INF;
            ll y=evaluate(root->right);
            if(flag)return INF;
            return x-y;
      }
      else if(root->val=="*"){
            ll x=evaluate(root->left);
            if(flag)return INF;
            ll y=evaluate(root->right);
            if(flag)return INF;
            return x*y;
      }
      else if(root->val=="/"){
            ll x=evaluate(root->left);
            if(flag)return INF;
            ll y=evaluate(root->right);
            if(flag)return INF;
            return x/y;
      }
      else if(root->val=="^"){
            ll x=evaluate(root->left);
            if(flag)return INF;
            ll y=evaluate(root->right);
            if(flag)return INF;
            return powe(evaluate(root->left), evaluate(root->right));

      }
      else{

            if((root->val)[0]=='$'){
                        ll x=-1*stolla((root->val).substr(1));
                        return x;
            }
            else return stolla(root->val);
      }
}

int main(){
      ll n;
      cin>>n;
      while(n--){
            ll t;
            cin>>t;
            while(t--){
                  flag=0;
                  string s;
                  cin>>s;
                  ll f=0;
                  REP(i,0,s.length()){
                        if(s[i]=='='){
                              f=1;
                              struct tree *root=createTree();
                              vector<string> kel=postfix(s.substr(i+1));
                              makeTree(&root, kel);
                              if(flag==1)var[s.substr(0,i)]=INF;
                              else var[s.substr(0,i)]=evaluate(root);
                              break;
                        }
                  }
                  if(f==1)continue;
                  vector<string> post =postfix(s);
                  struct tree *root=createTree();
                  makeTree(&root,post);
                  ll ans=evaluate(root);
                  if(flag==1){cout<<"CANT BE EVALUATED"<<endl;continue;}
                  cout<<ans<<'\n';
            }
            var.clear();
      }
}
