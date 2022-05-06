#include<iostream>
using namespace std;

int pr[20],f=-1,r=-1;
string q[20];

void enque(string name,int s)
{
    if(f==-1){
        f=r=0;
        q[r]=name;
        pr[r]=s;
        return;
    }
    int i=r;
    for(i;i>=f;i--){
        if(s>pr[i]){
            q[i+1]=q[i];
            pr[i+1]=pr[i];
            q[i]=name;
            pr[i]=s;
        }
        else{
            break;
        }
    }
    pr[i+1]=s;
    q[i+1]=name;
    r++;
}
void display(){
    if(f==-1){
        cout<<"There are no patients to Display ";
        return;
    }
    cout<<"\nDisplaying Data";
    for(int i=f;i<=r;i++){
        cout<<"\nName of the patient:- '"<<q[i]<<"'\tPriority :- ";
        switch(pr[i]){
            case 1:     cout<<"'General Checkup";
            break;
            case 2:     cout<<"'Non Serious'";
            break;
            case 3:     cout<<"'Serious'";
            break;
            default:    cout<<"Not Defined";
            break;
        }
    }
}
void deque(){
    if(f==-1){
        cout<<"There are no patients to Checkout ";
        return;
    }
    cout<<"check up is done for patient :- '"<<q[f]<<"' \t Priority :- ";
    switch(pr[f]){
            case 1:     cout<<"'General Checkup";
            break;
            case 2:     cout<<"'Non Serious'";
            break;
            case 3:     cout<<"'Serious'";
            break;
            default:    cout<<"Not Defined";
            break;
    }
    f++;
    if(f>r){
        f=r=-1;
    }
}

int main()
{
    int ch,n,s;
    string name,ans;
    do{
        cout<<"\n\n-------------HOSPITAL-------------"<<endl;
        cout<<"1. Enter the data \n2. Display data \n3. Delete the data \n0. Exit \nEnter the Choice:- ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"How many patients are there? ";
                cin>>n;
                for(int i=0;i<n;i++){
                    cout<<"Enter the Name of the person ";
                    cin>>name;
                    cout<<"Enter the severity : 1.General Checkup 2.Non Serious 3.Serious \n";
                    cin>>s;
                    enque(name,s);
                }
            break;
            case 2:
                display();
                break;
            case 3:
                deque();
            break;
            case 0:
            break;
            default:    cout<<"Enter the Valid Choice ";
            break;
       }
    }while(ch!=0);
        
    return 0;
}



