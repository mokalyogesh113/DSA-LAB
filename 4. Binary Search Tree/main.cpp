//CODE BY 44_A_Mokal_Yogesh

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left=NULL,*right=NULL;
};


class BST
{
    public:
    Node* root;
    BST()
    {
        root=NULL;
    }
    void insert();
    void display_inorder(Node *);
    int min();
    int longest_path(Node *);
    void search(int );
    void mirror(Node *);
};


void BST::insert()
{
    int n;
    cout<<"Enter the value :- ";
    cin>>n;
    
    Node *temp=new Node;
    temp->data=n;
    
    if(root ==NULL){
        root = temp;
        return;
    }
    
    Node *trav=root;
    
    while(true)
    {
        if(trav->data>n)
            if(trav->left==NULL){
                trav->left=temp;
                return;
            }
            else
                trav=trav->left;
        else
            if(trav->right==NULL){
                trav->right=temp;
                return;
            }
            else
                trav=trav->right;
    }
}//End Function

void BST::display_inorder(Node *root)
{
    if(root == NULL)    return;
    display_inorder(root->left);
    cout<<root->data<<" ";
    display_inorder(root->right);
}

int BST::min()
{
    if(root==NULL)
        return -1;
    Node *trav=root;
    while(trav->left!=NULL)
        trav=trav->left;
    return trav->data;
}

int BST::longest_path(Node *nd)
{
    if(nd==NULL)
        return 0;
    int cnt=1;
    int ll=longest_path(nd->left);
    int lr=longest_path(nd->right);
    cnt+=ll>=lr ? ll : lr;
    return cnt;
}

void BST::search(int x)
{
    Node *trav=root;
    while(trav!=NULL)
    {
        if(trav->data==x){
            cout<<"Data is found"<<endl;
            return ;
        }
        else if(trav->data>x)
            trav=trav->left;
        else
            trav=trav->right;
    }
    cout<<"Data Not Found "<<endl;
}

void BST::mirror(Node *root)
{
    if(root==NULL)
        return ;
    mirror(root->left);
    mirror(root->right);
    Node *temp=root->left;
    root->left=root->right;
    root->right=temp;
}

int main ()
{
  BST b;
  int ch;
  do
    {
      cout <<"1.Insert Node \n2.Display Inorder of the Tree \n3.Find number of nodes in longest path from root \n4.Minimum data value found in the tree \n5.Mirror Tree \n6.Search A node by Value \n0.Exit \n";
      cout << "\nEnter Choice :- ";
      cin >> ch;
      switch (ch)
      {
    	case 0: break;
    	case 1:
        	    b.insert();
        	    break;
    	case 2:
    	        cout << "\nInorder traversal:- ";
                b.display_inorder (b.root);
                cout << endl;
                break;
        case 3:
                cout << "Number of nodes in longest path from root:- ";
                cout << b.longest_path (b.root) << endl;
                break;
        case 4:
                cout<<"Minimum data value found in the tree :- "<<b.min()<<endl;
                break;
        case 5:
                b.mirror(b.root);
                cout<<"Tree After Mirror :-";
                b.display_inorder(b.root);
                b.mirror(b.root);
                break;
        case 6:
                cout<<"Enter the value to be found:- ";
                int val;        cin>>val;
                b.search(val);
                break;
      }
      cout<<endl<<endl;
    } while (ch != 0);
    
  }
