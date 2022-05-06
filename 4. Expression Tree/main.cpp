#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node *left=NULL,*right=NULL;
};

class stack
{
    Node *arr[20];
    int top;
    public:
        stack()
        {
            top=-1;
        }
        
        bool isempty()
        {
            return top==-1;
        }
        bool isfull()
        {
            return top==19;
        }
        
        void push(Node *nd)
        {
            if(!isfull())
                arr[++top]=nd;
        }
        
        Node* pop()
        {
            if(!isempty())
                return arr[top--];
            return NULL;
        }
};


class Tree
{
    public:
    stack stk;
    Node *root;
    Tree()
    {
        root=NULL;
    }
        void expression(string prefix)
        {
            deletetree(root);
            for(int i=prefix.length()-1;i>=0;i--)
            {
                Node *nd=new Node;
                nd->data=prefix[i];
                if(isalpha(nd->data))
                {
                    stk.push(nd);
                }
                else if(nd->data=='+' || nd->data=='*' || nd->data=='-' || nd->data=='/' )
                {
                    Node *lc=stk.pop(),*rc=stk.pop();
                    nd->left=lc;
                    nd->right=rc;
                    stk.push(nd);
                }
            }
            root=stk.pop();
        }
        void postorder(Node *nd)
        {
            if(nd!=NULL)
            {
                
                postorder(nd->left);
                postorder(nd->right);
                cout<<nd->data;
            }
        }
        
        void inorder(Node *nd)
        {
            if(nd!=NULL)
            {
                
                inorder(nd->left);
                cout<<nd->data;
                inorder(nd->right);
                
            }
        }
        
        void non_rec_postorder(Node *nd)
        {
            stack s1,s2;
            s1.push(nd);
            while(!s1.isempty())
            {
                Node *T=s1.pop();
                s2.push(T);
                if(T->left!=NULL)
                    s1.push(T->left);
                if(T->right!=NULL)
                    s1.push(T->right);
            }
            while(!s2.isempty())
            {
                cout<<s2.pop()->data;
            }
            cout<<endl;
        }
        void deletetree(Node *nd)
        {
            if(nd==NULL)
                return;
            deletetree(nd->left);
            deletetree(nd->right);
            cout<<"\n Deleting Tree "<<nd->data;
            free(nd);
        }
};


int main()
{
    Tree t;
    string prefix;
    cout<<"Enter the Prefix Operation :- ";
    cin>>prefix;
    t.expression(prefix);
    while(true)
    {
        cout<<"\n\n1. Prefix to postfix (using Recursion) \n";
        cout<<"2. Prefix to Infix  (using Recursion) \n";
        cout<<"3. Prefix to postfix (using Non-Recursion) \n";
        cout<<"4. Delete tree \n";
        cout<<"0.Exit  \n";
        cout<<"Enter Choice:- ";
        int ch; cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"Prefix to Postfix (using Recursion) :- ";
                t.postorder(t.root);
                cout<<endl;
                break;
            case 2:
                cout<<"Prefix to infix (using Recursion) :- ";
                t.inorder(t.root);
                cout<<endl;
                break;
            case 3:
                cout<<"Prefix to infix (using Non-Recursion) :- ";
                t.non_rec_postorder(t.root);
                cout<<endl;
                break;
            case 4:
                t.deletetree(t.root);
                break;
            case 0:
                exit(0);
                break;
            default:
                cout<<"Wrong Choice "<<endl;
                break;
        }
    }
    return 0;
}

