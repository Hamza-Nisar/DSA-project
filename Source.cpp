#include<iostream>
#define N 50   //Max number of nodes
#define MAX 50 //Max size of set
using namespace std;
int q = 0;
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
	node* root;
public:
	Nary_tree(){
		root = NULL;
	}
	void Add_node(int a, node* t){
		node* p = t;
		if (root == NULL)
		{
			root = new node(a);
			root->parent = root;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{

				if (p->child[i] == NULL){
					p->child[i] = new node(a);
					p->child[i]->parent = p;
					return;
				}
			}
			if (p->child[N] != NULL)
			{
				int i = 0;
				p = p->parent;
				while (p->child[i] != NULL)
				{
					i++;
				}

				Add_node(a, p->child[i]);
			}
		}
	}
	void traverse(node * p){
		cout << p->value;

		for (int i = 0; i < N; i++)
		{
			
		}

	}
};
