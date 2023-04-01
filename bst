#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node(int d){
			data=d;
			left=NULL;
			right=NULL;
		}
};
class BST{
	public:
		Node* insertToBST(Node* root,int d){
			if(root == NULL){
				root = new Node(d);
				return root;
			}
			if(d > root->data){
				root->right=insertToBST(root->right,d);
				return root;
			}
			else{
				root->left=insertToBST(root->left,d);
				return root;
			}
		}
		void create(Node*&root){
			int key;
			cout<<"Enter element in  BST(if not enter -1) :"<<" ";
			cin >> key;
			while (key!=-1) {
				root = insertToBST(root,key);
				cin >> key;
			}
		}
		void inOrder(Node* root){
			if(root == NULL)
			{
				return;
			}
			inOrder(root->left);
			cout<<root->data<<" ";
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
		Node* mirror(Node* root)
		{
			if(root == NULL)
			{
				return root;
			}
			else
			{
				Node* temp;
				mirror(root->left);
				mirror(root->right);
				temp = root->left;
				root->left=root->right;
				root->right=temp;
			}
		}
		int height(Node* root)
		{

			if(root == NULL)
			{
				return 0;
			}
			else
			{
				int lh = 1 + height(root->left);
				int rh = 1 + height(root->right);
				
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
		switch(ch)
        {
            case 1:
                b.create(root);
                break;
            case 2:
                b.inOrder(root);
                break;
            case 3:
                cout<<"Enter key to be search(if not enter -1) :";
                cin>>key;
                p=b.search(root,key);
                if(p==NULL)
                    cout<<"Element not found";
                else
                    cout<<"Element found :"<<p->data;
                break;
            case 4:
                b.minvalue(root);
                break;
            case 5:
                b.maxvalue(root);
                break;
            case 6:
                b.mirror(root);
                break;
            case 7:
                cout<<"Height of the tree :"<<b.height(root);
                break;
            case 8:
                exit(1);

        }
	}
	return 0;
}
