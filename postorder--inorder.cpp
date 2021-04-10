#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class node{
	public:
		char data;
		node *left,*right;
		node(int data)
		{
			this->left=NULL;
			this->right=NULL;
			this->data=data;
		}
};
class tree{
	public:
		node *root;
		tree()
		{
			root=NULL;
		}
	 void display(node *temp)
	 {
	 	if(temp==NULL)
	 	{
	 		return;
		 }
		 display(temp->left);
		 cout<<temp->data<<" ";
		 display(temp->right);
	 }	
	 int search(string inorder,int start,int end,char data)
	 {
	 	for(int i=start;i<=end;i++)
	 	{
	 		if(inorder[i]==data)
	 		{
	 			return i;
			 }
		 }
	 }
	 node* build(string inorder,string postorder,int start,int end)
	 {
	 	static int scan=0;
	 	if(start>end)
	 	{
	 		return NULL;
		 }
		 node *root=new node(postorder[scan++]);
		 if(start==end)
		 {
		 	return root;
		 }
		 int srch=search(inorder,start,end,root->data);
		 root->right=build(inorder,postorder,srch+1,end);
		 root->left=build(inorder,postorder,start,srch-1);
		 return root;
	 }
};

int main()
{
	string postorder,inorder;
	cout<<"enter postorder-";
	cin>>postorder;
	reverse(postorder.begin(), postorder.end());
	cout<<"enter inorder-";
	cin>>inorder;
	tree A;
	A.root=A.build(inorder,postorder,0,inorder.size()-1);
	A.display(A.root);
}
