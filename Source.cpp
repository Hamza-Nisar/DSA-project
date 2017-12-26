#include<iostream>
#define N 50   //Max number of nodes
#define MAX 50 //Max size of set
using namespace std;
class node{

public:
	int value;
	node* child[N];
	node* parent;
	node(){
		value = 0;
		for (int i = 0; i < N; i++)
		{
			child[i] = NULL;
		}
		parent = NULL;
	}
	node(int a){
		value = a;
		for (int i = 0; i < N; i++)
		{
			child[i] = NULL;
		}
		parent = NULL;
	}
};
class Nary_tree{
	
public:
	node* root;
	Nary_tree(){
		root = NULL;
	}
	void Add_node(int a, node* t,node *par){
		node* p = t;
		if (root == NULL)
		{
			root = new node(a);
			root->parent = root;
		}
		else if (root!=NULL)
		{
			if (p==NULL)
			{
				p = new node(a);
				p->parent = par;
				return;
			}
			for (int i = 0; i < N; i++)
			{

				if (p->child[i] == NULL){
					Add_node(a, p->child[i],p);
				}
			}
			if (p->child[N - 1] != NULL)
			{
				int i = 0;
				p = p->parent;
				while (p->child[i] != NULL)
				{
					i++;
				}
				if (p->child[i] == NULL){
					Add_node(a, p->child[i],p);
					return;
				}
			}
		}
		else {
			while (p->child[0] != NULL){
				p = p->child[0];
			}
			Add_node(a, p->child[0],p);
		}
	}
	void traverse(node * p){
		if (p != NULL)
		{
			for (int i = 0; i < N; i++){
				
				traverse(p->child[i]);
				cout << " " << p->value << " -> ";
			}
		}
		
	}
};
void main(){
	Nary_tree N1;
	int A[1000];
	for (int i = 0; i < 1000; i++)
	{
		A[i] = i + 1;
	}
	for (int i = 0; i < 1000; i++)
	{
		int a = A[i];
		N1.Add_node(a, N1.root, N1.root);
	}
	N1.traverse(N1.root);
	system("pause");
}
