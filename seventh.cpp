#include<iostream>
using namespace std;
class Graph{
    int ne,nv;
    int **adjmat;
    public:
    Graph(){
        ne=0;
        nv=0;
    }
    Graph(int ne,int nv){
        this->ne=ne;
        this->nv=nv;
        adjmat=new int*[nv];
        for(int i=0;i<nv;i++){
            adjmat[i]=new int[nv];
            for(int j=0;j<nv;j++){
                adjmat[i][j]=0;
            }
        }
    }
    
    //create
    void create(){
        int sv,dv,cost;
        for(int i=0;i<ne;i++){
            cout<<"Enter source vertex"<<endl;
            cin>>sv;
            cout<<"Enter destination vertex"<<endl;
            cin>>dv;
            cout<<"Enter cost"<<endl;
            cin>>cost;

            adjmat[sv][dv]=adjmat[dv][sv]=cost;
        }
    }

    void display(){
        for(int i=0;i<nv;i++){
            for(int j=0;j<nv;j++){
                cout<<adjmat[i][j]<<" ";
            }
            cout<<endl;
        }
    }


    void prims(int sv){
        int v1=sv;
        int count=0;
        int count1=0;
        int weight=0;
        int father[nv];
        int mst[nv][nv];
        int A[nv];

        int u,v;
        int min=1000;
        A[count1]=v1;
        count1++;

        for(int i=0;i<nv;i++){
            father[i]=-1;
        }
        while(count1<nv){
            min=1000;
            for(int i=0;i<count1;i++){
                for(int j=0;j<nv;j++){
                    if(adjmat[A[i]][j]!=0 && adjmat[A[i]][j]<min){
                        min=adjmat[A[i]][j];
                        u=A[i];
                        v=j;
                    }
                }
            }
            
            adjmat[u][v]=adjmat[v][u]=0;
            int temp1=u;
            int temp2=v;

            
            int root_temp1;
            int root_temp2;

            while(u>=0){
                root_temp1=u;
                u=father[u];
            }
            while(v>=0){
                root_temp2=v;
                v=father[v];
            }


            if(root_temp1!=root_temp2){
                mst[temp1][temp2]=mst[temp2][temp1]=min;
                weight=weight+mst[temp1][temp2];

                father[root_temp1]=root_temp2;
                count++;
                A[count1]=temp2;
                count1++;
            }

        }
        cout<<weight<<endl;
    }

    void kruskal(){
        
        int count=0;
        int count1=0;
        int weight=0;
        int father[nv];
        int mst[nv][nv];
        int A[nv];

        int u,v;
        int min=1000;
        
        count1++;

        for(int i=0;i<nv;i++){
            father[i]=-1;
        }
        while(count1<nv){
            min=1000;
            for(int i=0;i<nv;i++){
                for(int j=0;j<nv;j++){
                    if(adjmat[i][j]!=0 && adjmat[i][j]<min){
                        min=adjmat[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
            
            adjmat[u][v]=adjmat[v][u]=0;
            int temp1=u;
            int temp2=v;

            
            int root_temp1;
            int root_temp2;

            while(u>=0){
                root_temp1=u;
                u=father[u];
            }
            while(v>=0){
                root_temp2=v;
                v=father[v];
            }


            if(root_temp1!=root_temp2){
                mst[temp1][temp2]=mst[temp2][temp1]=min;
                weight=weight+mst[temp1][temp2];

                father[root_temp1]=root_temp2;
                count++;
                A[count1]=temp2;
                count1++;
            }

        }
        cout<<weight<<endl;
    }

};
int main(){
    int ne,nv;
    cin>>ne>>nv;
    Graph obj(ne,nv);
    obj.create();
    obj.display();
    

    // obj.prims(sv);
    
    obj.kruskal();
    return 0;
}