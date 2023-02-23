#include<iostream>
using namespace std;
class hashT
{
    public:
        long long hashtable[10];
        hashT()
        {
            for(int i=0;i<10;i++)
            {
                hashtable[i]=-1;
            }
        }
        void insert()
        {
            long long key;
            cout<<"Enter a key :";
            cin>>key;
            int loc=key%10;
            for(int i=0;i<10;i++)
            {
                if(hashtable[loc]==-1)
                {
                    hashtable[loc]=key;
                    break;
                }
                else
                {
                    loc=(loc+1)%10;
                }
            }
        }
        void display()
        {
            for(int i=0;i<10;i++)
            {
                if(hashtable[i]==-1)
                {
                    cout<<"--"<<endl;
                }
                else
                {
                    cout<<hashtable[i]<<endl;
                }
            }
        }
        void search()
        {
            long long search;
            cout<<"Enter key to search :";
            cin>>search;
            int loc=search%10;
            bool flag;
            for(int i=0;i<10;i++)
            {
                if(hashtable[loc]==-1)
                {
                    cout<<"Element Not found";
                }
                if(hashtable[loc]==search)
                {
                    flag=true;
                }
                else
                {
                    loc=(loc+1)%10;
                    if(hashtable[loc]==search)
                    {
                        flag=true;
                    }
                }
                if(flag)
                {
                    cout<<"Element Found";
                    break;
                }
                else
                {
                    cout<<"Element Not found";
                }
            }
        }
};

int main()
{
    hashT obj;
    int ch;
    while(true)
    {
        cout<<"\n1.Insert\n2.Display\n3.Search";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch (ch)
        {
        case 1:
            obj.insert();
            break;
        case 2:
            obj.display();
            break;
        case 3:
            obj.search();
            break;
            false;
        default:
            cout<<"Thank You!!!";
            break;
        }
    }
}
