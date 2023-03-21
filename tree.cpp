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
class stack2
{
    public:
        node *arr[20];
        int top;
        stack2()
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
class queue1{
    public:
        int r,f;
        node* arr[10];
        queue1(){
            r=f=-1;
        }
        int empty()
        {
            if(r==-1 && f==-1){
                return 1;
            }
            else{
                return 0;
            }
        }
        void insert(node* p)
        {
            if(empty()==1){
                r=f=0;
                arr[r]=p;
            }
            else{
                r=r+1;
                arr[r]=p;
            }
        }
        node* remove()
        {
            node* temp=arr[f];
            if(r==f)
            {
                r=f=-1;
            }
            else{
                f=f+1;
            }
            return temp;
        }
};
class tree
{
    public:
        node *root;
        node *create()
        {
            string key;
            cout<<"\nEnter a book(if not write NULL) :";
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
                cout<<root->data<<" ";
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
                cout<<root->data<<" ";
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
                cout<<root->data<<" ";
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
                cout<<t->data<<" ";
                t=t->right;
            }
        }
        void nonrec_preorder(node *t)
        {
            stack1 s;
            while(t!=NULL || s.empty()!=1)
            {
                while(t!=NULL){
                    cout<<t->data<<" ";
                    s.push(t);
                    t=t->left;
                }
                t=s.pop();
                t=t->right;
            }
        }
        void nonrec_postorder(node* t){
            stack1 s;
            stack2 s1;
            node* temp;
            if(t==NULL)
            {
                return;
            }
            s.push(t);
            while(s.empty()!=1){
                temp=s.pop();
                s1.push(temp);
                if(temp->left!=NULL)
                    s.push(temp->left);
                if(temp->right!=NULL)
                    s.push(temp->right);
            }
            while(s1.empty()!=1){
                temp=s1.pop();
                cout<<temp->data<<" ";
            }
        }
        void BFS(node* t)
        {
            queue1 q;
            q.insert(t);
            cout<<t->data<<" ";
            while(q.empty()!=1)
            {
                t=q.remove();
                if(t->left!=NULL)
                {
                    cout<<t->left->data<<" ";
                    q.insert(t->left);
                }
                if(t->right!=NULL)
                {
                    cout<<t->right->data<<" ";
                    q.insert(t->right);
                }
            }
        }
        void menu()
        {
            cout<<"\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Non-Rec Inorder\n6.Non-Rec Preorder\n7.Non-Rec Postorder\n8.BFS"<<endl;
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
            case 7:
                t.nonrec_postorder(t.root);
                break;
            case 8:
                t.BFS(t.root);
                break;
            default:
                exit(1);
        }
    }
    return 0;
}
