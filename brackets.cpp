#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack <char> st;

    ll n;
    cin >> n;

    REP(i, 0, n){

    	int flag=0;
    	string s;

    	cin >> s;

    	REP (i, 0, (s.length()+1)){
    		
    		char c=s[i];
    		//cout<<c<<endl;
    		
    		if(i==(s.length())){
    			if(st.empty()==1){
    				cout<<"YES"<<endl;
    				break;
    			}
    			else{
    				cout<<"NO"<<endl;
    				break;
    			}
    		}

    		if(c=='(' || c=='{' || c=='[' || c=='<'){
    			st.push(c);
    		}

    		else if (c==')' || c=='}' || c==']' || c=='>'){

    			switch (c) {

    				case ')' : if(st.empty() ==0){
    								if(st.top()=='('){
    									st.pop();
    									break;
    								}

    								else {
    									flag=1;
    									break;
    								}

    							}

    							else{
    								flag=1;
    								break;
    							} 

    				case '}' : if(st.empty() ==0){
    								if(st.top()=='{'){
    									st.pop();
    									break;
    								}

    								else {
    									flag=1;
    									break;
    								}

    							}
    							
    							else{
    								flag=1;
    								break;
    							} 

    				case '>' : if(st.empty() ==0){
    								if(st.top()=='<'){
    									st.pop();
    									break;
    								}

    								else {
    									flag=1;
    									break;
    								}

    							}
    							
    							else{
    								flag=1;
    								break;
    							} 

    				case ']' : if(st.empty() ==0){
    								if(st.top()=='['){
    									st.pop();
    									break;
    								}

    								else {
    									flag=1;
    									break;
    								}

    							}
    							
    							else{
    								flag=1;
    								break;
    							} 

    			} 


  

    		}


    		else if(st.empty() ==0 && st.top()=='|'){
    			st.pop();
    		}	

    		else {
    			st.push(c);
    		}

    		if(flag==1){
    			cout<<"NO"<<endl;
    			break;
    		}

    	}

    }


	return 0;
}
