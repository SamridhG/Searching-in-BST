//AVL tree with new insertion tech which inspire from BST insertion
#include<iostream>
#include<math.h>
using namespace std;
class node{
	public:
	int data;// storing value
	int height;// storing height of each node
	node *left,*right;// pointer
	node(int data)
	{
		this->data=data;
		this->height=0;// temperary zero
		this->left=this->right=NULL;
	}
};
class AVL{
	public:
	node *root;
	int height(node *rt)
	{
		return rt==NULL?-1:rt->height;// null return zero cause if there is only root no height after return one is added there so it become zero
	}
	int max(int a,int b)
	{
		return a>=b?a:b;
	}
	AVL()
	{
		this->root=NULL;
	}
	node* left_left_rotation(node *rt)//draw tree 
	{
		node *temp=rt->left;
		rt->left=temp->right;
		temp->right=rt;
		rt=temp;
		rt->right->height=max(height(rt->right->left),height(rt->right->right))+1;
		rt->height=max(height(rt->left),height(rt->right))+1;
		return rt;
	}
	node* right_right_rotation(node *rt)// draw tree
	{
		node *temp=rt->right;
		rt->right=temp->left;
		temp->left=rt;
		rt=temp;
		rt->left->height=max(height(rt->left->left),height(rt->left->right))+1;
		rt->height=max(height(rt->left),height(rt->right))+1;
		return rt;
	}
	node* left_right_rotation(node *rt)
	{
		rt->left=right_right_rotation(rt->left);
		rt=left_left_rotation(rt);
		return rt;
	}
	node *right_left_rotation(node *rt)
	{
		rt->right=left_left_rotation(rt->right);
		rt=right_right_rotation(rt);
		return rt;
	}
	node* insertAVL(node *rt,int key)// return type full updated tree + (data to insert)
	{
		if(rt==NULL)
		{
			rt=new node(key);
		}
		else
		{
			if(key<rt->data)
			{
				rt->left=insertAVL(rt->left,key);// inserting on left
				if(abs(height(rt->left)-height(rt->right))==2)
				{
					if(key<rt->left->data)//if tree is unbalance by insertion of left of left
					{
						rt=left_left_rotation(rt);
					}
					else// left of right
					{
						rt=left_right_rotation(rt);
					}
				}
			}
			else
			{
				rt->right=insertAVL(rt->right,key);// inserting right
					if(abs(height(rt->left)-height(rt->right))==2)
				{
					if(key>rt->right->data)// right of right
					{
						rt=right_right_rotation(rt);
					}
					else// right of left
					{
						rt=right_left_rotation(rt);
					}
				}
			}
		}
		rt->height=max(height(rt->left),height(rt->right))+1;// height of current node 
		return rt;
	}
/*	void inorder(node *rt)
	{
		if(rt==NULL)
		{
			return;
		}
		inorder(rt->left);
		cout<<"data -"<<rt->data<<" height- "<<rt->height<<endl;
		inorder(rt->right);	
	}*/
};
int main()
{
	AVL A;
	A.root=A.insertAVL(A.root,5);
	A.root=A.insertAVL(A.root,9);
		A.root=A.insertAVL(A.root,11);
			A.root=A.insertAVL(A.root,0);
				A.root=A.insertAVL(A.root,7);
					A.root=A.insertAVL(A.root,8);
				//	A.inorder(A.root);
}
