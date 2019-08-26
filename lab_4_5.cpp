#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

struct tree
{
	char data;
	string var;
	int num;
	struct tree* left;
	struct tree* right;
};

struct tree* createnode (){

	struct tree * newnode =(struct tree*)malloc(sizeof(struct tree));
	return newnode;
}

int convert (string dig){

	int i=0;
	int num=0;
	while((dig[i]-'0')>=0 && (dig[i]-'0')<10){
		num*=10;
		num+=dig[i]-'0';
		i++;
	}

	return num;
}

struct tree* maketree ( string  expr){

	struct tree * newnode=createnode();

	int brac=0;
	int opflg=0;

	//cout<<expr<<" "<<"rttTH"<<endl;

	/*for (int i=0; i<expr.length(); i++ ){
		if(expr[i]=='('){
			brac++;
		}
		if(expr[i]==')'){
			brac--;
		}
		if(brac>0){
			continue;
		}
		brac=0;
		if(expr[i]=='+' || expr[i]=='-'){
			opflg=1;
			newnode->data=expr[i];
			//cout<<"ADD"<<endl;

			newnode->left=maketree(expr.substr(0, i));

			newnode->right=maketree(expr.substr(i+1));

			return newnode;
		}

	}

	*/

	if(expr[0]=='-'){

            newnode=maketree("0"+expr);
            return newnode;

      }

	for (int i=expr.length()-1; i>=0; i-- ){

		if(expr[i]==')'){
			brac++;
		}

		if(expr[i]=='('){
			brac--;
		}

		if(brac>0){
			continue;
		}
		brac=0;

		if(expr[i]=='-' || expr[i]=='+'){

			opflg=1;
			newnode->data=expr[i];
			//cout<<"SUB"<<endl;
			newnode->left=maketree(expr.substr(0, i));
			newnode->right=maketree(expr.substr(i+1));

			return newnode;
		}


	}




	/*for (int i=0; i<expr.length(); i++ ){
		if(expr[i]=='('){
			brac++;
		}
		if(expr[i]==')'){
			brac--;
		}
		if(brac>0){
			continue;
		}
		brac=0;
		if(expr[i]=='*'){
			opflg=1;
			newnode->data=expr[i];
			//cout<<"MUL"<<endl;
			newnode->left=maketree(expr.substr(0, i));
			newnode->right=maketree(expr.substr(i+1));
			return newnode;
		}


	}

*/

	for (int i=expr.length()-1; i>=0; i-- ){

		if(expr[i]==')'){
			brac++;
		}

		if(expr[i]=='('){
			brac--;
		}

		if(brac>0){
			continue;
		}
		brac=0;

		if(expr[i]=='/' || expr[i]=='*'){

			opflg=1;
			newnode->data=expr[i];
			//cout<<"DIV"<<endl;
			newnode->left=maketree(expr.substr(0, i));
			newnode->right=maketree(expr.substr(i+1));

			return newnode;
		}


	}

	for (int i=0; i<expr.length(); i++ ){

		if(expr[i]=='('){
			brac++;
		}

		if(expr[i]==')'){
			brac--;
		}

		if(brac>0){
			continue;
		}
		brac=0;

		if(expr[i]=='^'){

			opflg=1;
			newnode->data=expr[i];
			//cout<<"POW"<<endl;
			newnode->left=maketree(expr.substr(0, i));
			newnode->right=maketree(expr.substr(i+1));

			return newnode;
		}


	}

	if(opflg==0){

		if(expr[0]=='('){
			newnode=maketree(expr.substr(1, expr.length()-2));
		}


		else{
                  if(expr[0]<='9' && expr[0]>='0'){
                        newnode->data='n';
                        newnode->num=convert(expr);
                        newnode->left=NULL;
                        newnode->right=NULL;
                  }
                  else{
                        newnode->data='v';
                        newnode->var=expr;
                        newnode->left=NULL;
                        newnode->right=NULL;

                  }
		}
	}

return newnode;

}

int* eval(tree* node, string a[], int arr[], int* err){

	int *val;
	val=(int*)malloc(sizeof(int));

	if(node->data !='n' && node->data !='v' )

	switch (node->data){

		case '+' : *val= *(eval(node->left, a, arr, err))+(*eval(node->right, a, arr, err));
					break;
		case '*' : *val= *(eval(node->left, a, arr, err))*(*eval(node->right, a, arr, err));
					break;
		case '-' : *val= *(eval(node->left, a, arr, err))-(*eval(node->right, a, arr, err));
					break;
		case '/' : *val= *(eval(node->left, a, arr, err))/(*eval(node->right, a, arr, err));
					break;
		case '^' : *val= (int)pow((int)*(eval(node->left, a, arr, err)),((int)*eval(node->right, a, arr, err)));
					break;

	}

	else if (node->data !='v'){
		*val=node->num;
	}
	else{
            ll i=0;

            while(arr[i]!=-1){

                  if (a[i]==node->var){
                        *val=arr[i];
                        break;
                  }
                  i++;
            }
            if(arr[i]==-1){
                  *err=1;
            }

	}

return val;

}

int main(){

	long long q;

	cin >>q;

	long double d;

	struct tree* root=NULL;


	for(long long i=0; i<q; i++ ){

		long long n;
		cin>>n;
		string a[n];
		ll ctr=-1;
		int arr[n];
		REP(j, 0, n){
		      arr[j]=-1;
		}
		while(n--){

                  int flag=0;
                  int err=0;
                  int asf=0;
                  int pos=-1;
                  string expr;
                  cin>>expr;

                  REP(k, 0, expr.length()){

                        if(expr[k]=='='){

                              asf=1;

                              REP(j, 0, ctr+1){
                                    if(expr.substr(0, k)==a[j]){
                                          flag=1;
                                          pos=j;
                                          break;
                                    }
                              }

                              if(flag==0){
                                    ctr++;
                                    a[ctr]=expr.substr(0, k);
                                    pos=ctr;
                              }

                              root=maketree(expr.substr(k+1));

                              break;
                        }

                  }

                  if(asf==1){
                        arr[pos]=*(eval(root, a, arr, &err));
                        if(err==1){
                              arr[ctr]=-1;
                              ctr--;

                        }
                        //cout<<pos<<" "<<a[pos]<<" "<<arr[pos]<<endl;
                  }

                  else{

                        root=maketree(expr);
                        int* val=eval(root, a, arr, &err);

                        if(err==1)cout<<"CANT BE EVALUATED"<<endl;
                        else cout<<*val<<endl;

                  }
            }

	}

	return 0;
}
