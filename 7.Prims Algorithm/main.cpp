#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int n;  
    cout<<"Enter the Number of Cities :- ";
    cin>>n;
    int cost[n][n],visit[n];
    //Declared visit array and cost matrix
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cost[i][j]=-1;
    for(int i=0;i<n;i++)
        visit[i]=0;
    //Initialize cost Matrix to -1 and visit Array to 1
            
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) break;
            cout<<"Do you Want to add path between city "<<i<<" and city "<<j<<"? ";
            char ch;    cin>>ch;
            if(ch=='y' || ch=='Y'){
                cout<<"Enter the Cost of the Edge :- ";
                cin>>cost[i][j];
                cost[j][i]=cost[i][j];
            }
        }
    }
    //Updated Cost Matrix given By User
    
    int mincost=0;
    int next;
    visit[0]=1;
    for(int e=0;e<n-1;e++)
    {
        int min=999;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visit[i]==1 && visit[j]==0 && cost[i][j]!=-1 && cost[i][j]<min){
                    min=cost[i][j];
                    next=j;
                }
            }
        }
        mincost+=min;
        visit[next]=1;
    }
    
    cout<<"Minimum Cost to Visit all cities  :- "<<mincost<<endl;
    
    cout<<"\n\nCost Matrix:- "<<endl;
    cout<<endl;
    
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++)
            cout<<setw(5)<<cost[i][j]<<" ";
        cout<<endl<<endl;
    }
    
    return 0;
}
