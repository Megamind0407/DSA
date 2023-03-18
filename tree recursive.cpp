#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        node *left;
        node *right;
        string data;
        node(string d)
        {
            data=d;
            left=NULL;
            right=NULL;
        }
};
class tree
{
    public:
        node *root;
        node *create()
        {
            string key;
            cout<<"Enter a book(if not write NULL) :";
            cin>>key;

            if(key=="NULL")
            {
                return NULL;
            }
            node *root=new node(key);
            cout<<"Enter left part of (if not write NULL) :"<<key;
            root->left=create();
            cout<<"Enter right part of (if not write NULL) :"<<key;
            root->right=create();

            return root; 

        }
        void preorder(node *root)
        {
            if(root!=NULL)
            {
                cout<<root->data<<endl;
                preorder(root->left);
                preorder(root->right);
            }
            else{
                return;
            }
        }

        void inorder(node *root)
        {
            if(root!=NULL)
            {
                inorder(root->left);
                cout<<root->data<<endl;
                inorder(root->right);
            }
            else{
                return ;
            }
        }


        void postorder(node *root)
        {
            if(root==NULL)
            {
                return;
            }
            else{
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<endl;
            }
        }
        void menu()
        {
            cout<<"1.Insert\n2.Preorder\n3.Inorder\n4.Postorder"<<endl;
        }
};
int main()
{
    tree t;
    int ch;
    while(1)
    {
        t.menu();
        cout<<"\nEnter your choice :";
        cin>>ch;
        switch(ch)
        {
            case 1:
                t.root=t.create();
                break;
            case 2:
                t.inorder(t.root);
                break;
            case 3:
                t.preorder(t.root);
                break;
            case 4:
                t.postorder(t.root);
                break;
            default:
                cout<<"Invalid choice";
                exit(1);
        }

    }
    return 0;
}