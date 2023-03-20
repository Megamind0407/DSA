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
class stack1
{
    public:
        node *arr[20];
        int top;
        stack1()
        {
            top=-1;
        }
        void push(node *temp){
            top++;
            arr[top]=temp;
        }
        int empty()
        {
            if(top==-1)
            {
                return 1;
            }
            else{
                return 0;
            }
        }
        node *pop()
        {
            node *p=arr[top];
            top--;
            return p;
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
        void nonrec_inorder(node *t)
        {
            stack1 s;
            while(t!=NULL || s.empty()!=1)
            {
                while(t!=NULL){
                    s.push(t);
                    t=t->left;
                }
                t=s.pop();
                cout<<t->data<<endl;
                t=t->right;
            }
        }
        void nonrec_preorder(node *t)
        {
            stack1 s;
            while(t!=NULL || s.empty()!=1)
            {
                while(t!=NULL){
                    cout<<t->data<<endl;
                    s.push(t);
                    t=t->left;
                }
                t=s.pop();
                t=t->right;
            }
        }
        void menu()
        {
            cout<<"1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Non-Rec Inorder\n6.Non-Rec Preorder"<<endl;
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
            case 5:
                t.nonrec_inorder(t.root);
                break;
            case 6:
                t.nonrec_preorder(t.root);
                break;
            default:
                cout<<"Invalid choice";
                exit(1);
        }
    }
    return 0;
}