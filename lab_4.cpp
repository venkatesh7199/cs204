#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

struct tree
{
	char data;
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
			//cout<<"BRAC"<<" "<<expr<<endl;
			newnode=maketree(expr.substr(1, expr.length()-2));
		}

		else{
			newnode->data='n';
				

			newnode->num=convert(expr);
	
			newnode->left=NULL;
			newnode->right=NULL;		
		}
	}

	

return newnode;

}

int* eval(tree* node){

	int *val;
	val=(int*)malloc(sizeof(int));

	if(node->data !='n' )

	switch (node->data){

		case '+' : *val= *(eval(node->left)) + (*eval(node->right));
					break;
		case '*' : *val= *(eval(node->left))*(*eval(node->right));
					break;
		case '-' : *val= *(eval(node->left))-(*eval(node->right));
					break;
		case '/' : *val= *(eval(node->left))/(*eval(node->right));
					break;
		case '^' : *val= (int)pow((int)*(eval(node->left)),((int)*eval(node->right)));
					break; 

	}

	else{
		*val=node->num;
		//cout<<"set"<<endl;
	}
	//char o=node->data;
//cout <<*val<<endl;

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
		while(n--){

		string expr;
		cin>>expr;

		root=maketree(expr);
		//cout<<"yippee"<<endl;
		int* val=eval(root);
		
		cout<<*val<<endl;
		}
            

	}

	return 0;
}