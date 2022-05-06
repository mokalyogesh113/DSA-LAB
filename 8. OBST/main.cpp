#include<bits/stdc++.h>
using namespace std;
#define MAX 10

struct node{
    string data;
    node *left=NULL,*right=NULL;
};

void inorder(node *nd){
    if(nd!=NULL){
        inorder(nd->left);
        cout<<nd->data<<"  ";
        inorder(nd->right);
        return;
    }
}

void preorder(node *nd){
    if(nd!=NULL){
        cout<<nd->data<<"  ";
        preorder(nd->left);
        preorder(nd->right);
        return;
    }
}

node *construct(string wrd[],int r[MAX][MAX],int i,int j)
{
    if(r[i][j]==0 )  return NULL;
    
    int root=r[i][j];
    node *nd=new node;
    nd->data=wrd[root];
    nd->left=construct(wrd,r,i,root-1);
    nd->right=construct(wrd,r,root+1,j);
    return nd;
}


void OBST(string wrd[],int p[],int q[],int n)
{   
    int w[MAX][MAX],c[MAX][MAX],r[MAX][MAX];
    
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            w[i][j]=c[i][j]=r[i][j]=0;
        }
    }


    //Step 1
    for(int i=1;i<=n;i++){
        
        w[i][i]=q[i-1]+q[i]+p[i];
        c[i][i]=w[i][i];
        r[i][i]=i;
    }

    //Step2 
    for(int step = 1 ; step<n;step++){
        for(int i=1;i<=n-step;i++)
        {
            int j=i+step;
            w[i][j]=w[i][j-1]+q[j]+p[j];
            
            int root;                               //Find the minimum cost and root
            int min=999;
            for(int k=i;k<=j;k++){
                if(c[i][k-1]+c[k+1][j] < min ){
                    min = c[i][k-1]+c[k+1][j];
                    root=k;
                }
            }
            c[i][j]=min+w[i][j];
            r[i][j]=root;
        }
    }
    
    
    //Printing the w,c,r Matrix
    for(int step=0;step<n;step++){
        for(int i=1;i<=n-step;i++){
            int j=i+step;
            cout<<"w["<<i<<"]["<<j<<"] = "<<w[i][j]<<"\t";
        }   
        cout<<endl;
        for(int i=1;i<=n-step;i++){
            int j=i+step;
            cout<<"c["<<i<<"]["<<j<<"] = "<<c[i][j]<<"\t";
        }
        cout<<endl;
        for(int i=1;i<=n-step;i++){
            int j=i+step;
            cout<<"r["<<i<<"]["<<j<<"] = "<<r[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
    


    //Constructing The tree using r matrix
    node *root=construct(wrd,r,1,n);    //(recursion)
    
    cout<<"The Minimum cost is "<<c[1][n]<<endl;;
    
    
    cout<<"Displaying the data (Inorder) :-  ";
    inorder(root);      
    cout<<endl;
    
    cout<<"Displaying the data (Preorder) :- ";
    preorder(root); 
    cout<<endl;
    
    return;
}


int main()
{
    int p[MAX],q[MAX];
    string wrd[MAX];

    int n; 
    cout<<"Enter the Number of Words :- ";
    cin>>n;

    cout<<"Enter "<<n<<" Words in Assending Ordrer "<<endl;
    for(int i = 1; i <=n; i++)    {
        cin>>wrd[i];
    }

    cout<<"Enter the Successfull Probilities of words "<<endl;
    for(int i=1;i<=n;i++){
        cout<<"Enter the probility p of word '"<<wrd[i]<<"' :- ";
        cin>>p[i];
    }

    cout<<"Enter the "<<n+1<<" Unsuccessful Probilities "<<endl;
    for(int i=0;i<=n;i++){
        cin>>q[i];
    }
    
    OBST(wrd,p,q,n);


    return 0;
}
