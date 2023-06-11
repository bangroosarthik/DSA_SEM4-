#include<iostream>
#include<queue>
#include<stack>
#define size 10
using namespace std;
class Node{
    int data;
    Node* next;
    public:
    Node(){
        data=0;
        next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    friend class graph;
};
class graph{
    Node* arr[size];
    public:
    graph(){
        for(int i=0;i<size;i++){
            arr[i]=NULL;
        }
    }

    void insert_edge(int sv,int dv){
        //creating nodes for source and destination 
        Node* nn1=new Node(sv);
        Node* nn2=new Node(dv);
        
        if(arr[sv]==NULL){
            arr[sv]=nn2;
        }

        else{
            Node* temp=arr[sv];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn2;
        }

        // if(arr[sv]==NULL){
        //     arr[sv]=nn2;
        // }

        // else{
        //     Node* temp=arr[sv];
        //     while(temp!=NULL){
        //         temp=temp->next;
        //     }
        //     temp->next=nn2;
        // }

        

    }


    void display(){
        for(int i=0;i<size;i++){
            cout<<i<<" -> ";
            Node* temp=arr[i];
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }

    void BFS(int sv){
        queue<int> q;
        bool visited[size]={};
        q.push(sv);
        visited[sv]=1;
        while(q.empty()==false){
            sv=q.front();
            q.pop();
            cout<<sv<<endl;
            Node* temp=arr[sv];
            while(temp!=NULL){
                if(visited[temp->data]==0){
                    visited[temp->data]=1;
                    q.push(temp->data);
                }
                temp=temp->next;
            }
        }
    }

    void DFS(int sv){
        stack<int> q;
        bool visited[size]={};
        q.push(sv);
        visited[sv]=1;
        while(q.empty()==false){
            sv=q.top();
            q.pop();
            cout<<sv<<endl;
            Node* temp=arr[sv];
            while(temp!=NULL){
                if(visited[temp->data]==0){
                    visited[temp->data]=1;
                    q.push(temp->data);
                }
                temp=temp->next;
            }
        }
    }
};
int main(){
    graph obj;
    cout<<"Enter the total number of vertixe"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int sv;
        cout<<"Enter source vertex"<<endl;
        cin>>sv;
        int n2;
        cout<<"Enter number of neighbouring vertex to"<<sv<<endl;
        cin>>n2;
        for(int i=0;i<n2;i++){
            int n3;
            cout<<"Enter destination vertex"<<i<<endl;
            cin>>n3;
            obj.insert_edge(sv,n3);
        }

    }

    obj.display();

    while(true){
        cout<<"Enter 1 for BFS traversal"<<endl;
        cout<<"Enter 2 for DFS traversal"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            int sv;
            cout<<"Enter source vertex"<<endl;
            cin>>sv;
            obj.BFS(sv);
            cout<<endl;
        }
        else if(op==2){
            int sv;
            cout<<"Enter source vertex"<<endl;
            cin>>sv;
            obj.DFS(sv);
            cout<<endl;
        }
        
    }
    return 0;
}