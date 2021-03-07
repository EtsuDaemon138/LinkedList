#include <iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
	node *head = NULL;
	node *tail = NULL;
node *CreateNode(int data){ // tao node 
	node *cnode = new node;
	cnode->data = data;
	cnode->next = NULL;
	return cnode;
}
void addHead(node* cnode){
	if(head == NULL)
		head = tail = cnode;
	else{
		cnode->next = head;
		head= cnode;
	}
}
void addTail(node *cnode){
	if(head == NULL)
		head = tail = cnode;
	else{
		tail ->next = cnode;
		tail = cnode;
	}
}
void printLinkedlist(){
	node *cnode= head;
	while(cnode != NULL){
		cout<< cnode -> data <<" ";
		cnode =cnode ->next;
	}
}
node *findNodeQ(int n){
	node *cnode = head;
	int dem= 0;
	while(cnode != NULL){
		dem++;
		if(dem == n)
			return cnode;
		cnode = cnode->next;
	}
	return cnode;
}
void insertAfterQ(node *q,node *p){
	if(q != NULL){
		p->next = q->next;
		q-> next = p;
		if(tail == q)
			tail = p; 
	}
	else
		addHead(p);
}
int deleteHead (){
	node *head= head;
	head = head -> next;
	delete head;
	if(head == NULL)
		tail = NULL;
	return 0;
}
int deleteAfterQ( node *q){
	if(q != NULL){
		node *nqnode = q->next;
		if(nqnode != NULL){
			if(nqnode == tail)
				tail = q;
			q->next = nqnode -> next; 
			delete nqnode;
		}
		return 0;
	}
	return 0;
}
int main(){

	for(int i =1; i<= 1000	;i++){
		//addHead(l,CreateNode(i));
		addTail( CreateNode(i));
	}
	printLinkedlist();
}
