#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void BFS(int s,int adj[10][10],int vis[10],int n)
{
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int i=q.front();
        q.pop();
        cout<<i<<" ";
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]==1 && vis[j]!=1)
            {
                q.push(j);
                vis[j]=1;
            }
        }
    }
}

void DFS(int s,int adj[10][10],int vis[10],int n)
{
    stack<int> stk;
    stk.push(s);
    vis[s]=1;
    while(!stk.empty())
    {
        int i=stk.top();
        stk.pop();
        cout<<i<<" ";
        for(int j=0;j<n;j++)
        {
            if(adj[i][j]==1 && vis[j]!=1)
            {
                stk.push(j);
                vis[j]=1;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the Number of vertices in the Graph :- ";
    cin>>n;
    int adj[10][10]={0},vis[10]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                break;
            cout<<"Do you want Edge between "<<i<<" & "<<j<<"?   ";
            char ch;
            cin>>ch;
            if(ch=='y' || ch=='Y'){
                adj[i][j]=adj[j][i]=1;
            }
        }
    }
    cout<<"\nAdjecency Matrix of the given graph is :- \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"The BFS on the given graph is :- \n"<<endl;
    BFS(0,adj,vis,n);
    
    for(int i=0;i<n;i++)
        vis[i]=0;
    
    cout<<"\nThe DFS on the given graph is :- \n"<<endl;
    DFS(0,adj,vis,n);
    
}