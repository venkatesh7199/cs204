#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

struct point
{
	int x;
	int y;
};

struct node
{
	struct point p;
	struct node* next;
};

struct node* createnode (){

	struct node* newnode =(struct node*)malloc(sizeof(struct node));
	return newnode;
}

void addFirst(struct node** head, int x, int y ){

	struct node* newnode=createnode();
	newnode->p.x=x;
	newnode->p.y=y;
	newnode->next=*head;
	*head=newnode;

}

void delFirst(struct node** head){

	struct node*temp;

	temp=*head;
	*head=(*head)->next;
	free(temp);
}

int search (struct node* head, int x, int y){

	struct node* temp;
	temp=head;
	int cnt=0;
	while(temp!=NULL){
		if (temp->p.x==x && temp->p.y==y)cnt++;
		temp=temp->next;

	}

	return cnt;
}

void del(struct node** head, int x, int y){

	if (search(*head, x, y)==0)return;
	else{

		struct node* temp;
		struct node* prev;
		temp=*head;
		prev=temp;

		while(temp!=NULL){
			prev=temp;
			temp=temp->next;
			if (temp->p.x==x && temp->p.y==y){
				prev->next=temp->next;
				free(temp);
				break;
			}
		}

	}

}

void searchd (struct node* head, int d){

	struct node* temp;
	temp=head;
	while(temp!=NULL){

		if((temp->p.x)*(temp->p.x)+(temp->p.y)*(temp->p.y)<=(d*d)){
			cout<<"("<<temp->p.x<<","<<temp->p.y<<")"<<" ";
		}
		temp=temp->next;
	}
	cout<<endl;

}

int length (struct node*head){

	struct node* temp;
	temp=head;
	int l=0;

	while (temp!=NULL){
		l++;
		temp=temp->next;
	}
 return l;
}

int main(){

	long long q;

	cin >>q;

	int f, x, y, d;

	struct node* head=NULL;


	for(long long i=0; i<q; i++ ){

		cin>>f;
		switch (f){
			case 1: {
				cin>>x>>y;
				addFirst(&head, x ,y);
				break;
			}

			case 2: {
				delFirst(&head);
				break;
			}

			case 3:{
				cin>>x>>y;
				del(&head, x, y);
				break;
			}

			case 4:{
				cin>>d;
				searchd(head, d);
				break;
			}

			case 5: {
				cin>>x>>y;
				cout<<search(head, x, y)<<endl;
				break;
			}

			case 6:{
				cout <<length(head)<<endl;
				break;
			}

		}

	}

	return 0;
}
