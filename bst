#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		string key;
		string mean;
		Node* left;
		Node* right;
		Node(string k,string m){
			key=k;
			mean=m;
			left=NULL;
			right=NULL;
			
		}
};

class BST{
	public:
		Node* insertToBST(Node* root,string k,string m){
			if(root == NULL){
				root = new Node(k,m);
				return root;
			}
			if(k > root->data){
				root->right=insertToBST(root->right,k);
				return root;
			}
			else{
				root->left=insertToBST(root->left,k);
				return root;
			}
		}
		void create(Node*&root){
			string key;
			string mean;
			cout<<"Enter element in  BST(if not enter -1) :"<<" ";
			cin >> key >> mean;
			while (key!=-1) {
				root = insertToBST(root,key,mean);
				cin >> key >> mean;
			}
		}
		void inOrder(Node* root){
			if(root == NULL)
			{
				return;
			}
			inOrder(root->left);
			cout<<root->key<<" ";
			inOrder(root->right);
		}
		Node* search(Node* root,int key){
		
        if (root == NULL || root->data == key)
            return root;
   
        if (root->data < key)
        
            return search(root->right, key);
 
        else
            return search(root->left, key);
    	}
    	
    	
    	void minvalue(Node* root)
    	{
    		while(root->left != NULL)
    		{
    			root=root->left;
			}
			cout<<"Min value ="<<root->data<<" ";
		}
		
		void maxvalue(Node* root)
    	{
    		while(root->right != NULL)
    		{
    			root=root->right;
			}
			cout<<"Max value ="<<root->data<<" ";
		}
		Node* swap(Node* root)
		{
			if(root == NULL)
			{
				return root;
			}
			else
			{
				Node* temp;
				swap(root->left);
				swap(root->right);
				temp = root->left;
				root->left=root->right;
				root->right=temp;
			}
		}
		void height(Node* root)
		{
			if(root == NULL)
			{
				return;
			}
			else
			{
				int lh=1 + height(root->left);
				int rh=1 + height(root->right);
				
				if(lh > rh)
				{
					return lh;
				}
				else{
					return rh;
				}
			}
		}
};

int main(){
	BST b;
	Node* root=NULL;
	Node* p;
	int ch;
	int key;
	while(1)
	{
		cout<<"\nEnter choice :";
		cin>>ch;
		if(ch==1)
		{
			b.create(root);
		}
		else if(ch==2){
			b.inOrder(root);
		}
		else if(ch==3){
			cout<<"Enter element to be search :";
			cin>>key;
			p=b.search(root,key);
			if(p==NULL)
			{
				cout<<"Element not found";
			}
			else
			{
				cout<<"Element found :"<<p->data;
			}
		}
		else if(ch==4){
			
			b.minvalue(root);
		}
		else if(ch==5)
		{
			b.maxvalue(root);
		}
		else if(ch==6)
		{
			b.swap(root);
		}
		else if(ch==7){
			
		}
		else{
			exit(1);
		}
	}
	return 0;
}
