#include<iostream>
using namespace std;

struct node
{
    int data;
    node *left,*right;
    int height;
    node(int n)
    {
        data = n;
        left = right = NULL;
        height = 1;
    }
};

class AVL
{
    public:
        node *root;
        AVL()
        {
            root = NULL;
        }
        node *insertKey(node *, int);
        node *balance(node *);
        int bal_fact(node *);
        int height(node *);
        node *leftRotation(node *);
        node *rightRotation(node *);
        void preOrder(node *);
};

int main()
{
    AVL avl;
    int ch,key;
    do
    {
        cout<<"\n--------------AVL TREE--------------"<<endl;
        cout<<"1.Insert Node"<<endl;
        cout<<"2.Display Preorder"<<endl;
        cout<<"0.Exit"<<endl;
        cout<<"Enter the Choice :- ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter the Key :- ";
            cin>>key;
            avl.root = avl.insertKey(avl.root , key);
        break;
        case 2:
            cout<<"\nDisplaying Pre-order Traversal "<<endl;
            avl.preOrder(avl.root);
            cout<<endl;
        break;

        default:
            cout<<"Invalid Choice\n";
        break;
        }

    }while(ch!=0);
}

node *AVL::insertKey( node *nd , int key)
{
    if(nd == NULL)
    {
        return new node(key);
    }
    if(key < nd->data)
    {
        nd->left = insertKey(nd->left,key);
        nd = balance(nd);
    }
    else if(key > nd->data)
    {
        nd->right = insertKey(nd->right , key);
        nd = balance(nd);
    }
    return nd;
}

node *AVL::balance(node *nd)
{
    int bf = bal_fact(nd);
    if(bf>1)    // Height of left is more than height of right
    {
        if(bal_fact(nd->left)<0)    //lr rotation
        {
            nd->left = leftRotation(nd->left);
            nd = rightRotation(nd);
        }
        else                        //ll ratation
        {   
            nd = rightRotation(nd);
        }
    }
    else if(bf<-1)  //Height of Right is grater than height of left
    {
        if(bal_fact(nd->right) > 0)     //rl rotation
        {
            nd->right = rightRotation(nd->right);
            nd = leftRotation(nd);
        }
        else                            //rr rotation
        {
            nd = leftRotation(nd);
        }
    }
    return nd;
}

int AVL::bal_fact(node *nd)
{
    return height(nd->left)-height(nd->right);
}

int AVL::height(node *nd)
{
    if(nd == NULL)
        return  0;
    int hl = height(nd->left);
    int hr = height(nd->right);
    int mh  = hl>hr ? hl :hr;
    return mh+1;
}

node *AVL::leftRotation(node *nd)
{
    node *x = nd->right;
    node *y = x->left;
    nd->right = y;
    x->left = nd;
    return x;
}

node *AVL::rightRotation(node *nd)
{
    node *x = nd->left;
    node *y = x->right;
    nd->left = y;
    x->right = nd;
    return x;
}

void AVL::preOrder(node *nd)
{
    if(nd!=NULL)
    {
        cout<<nd->data<<" ";
        preOrder(nd->left);
        preOrder(nd->right);
    }
}