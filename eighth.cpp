#include<iostream>
using namespace std;
class Node{
    string data;
    Node* left;
    Node* right;
    public:
    Node(){
        data="";
        left=NULL;
        right=NULL;
    }

    Node(string data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    friend class OBST;
};

class OBST{
    Node* root;
    public:
    
    

    Node* getroot(){
        return root;
    }

    void cal_wt(double* p,double* q,int n,string* data){
        double** w=new double*[n+1];
        double** c=new double*[n+1];
        double** r=new double*[n+1];

        //creating 2d array
        for(int i=0;i<n+1;i++){
            w[i]=new double[n+1];
            c[i]=new double[n+1];
            r[i]=new double[n+1];
        }

        for(int i=0;i<n;i++){
            //diagonal case
            w[i][i]=q[i];
            c[i][i]=0;
            r[i][i]=0;

            //above diagonal 
            w[i][i+1]=q[i]+q[i+1]+p[i];
            c[i][i+1]=w[i][i+1];
            r[i][i+1]=i+1;
        }

        //edge case
        w[n][n]=q[n];
        c[n][n]=0;
        r[n][n]=0;

        //main logic
        for(int m=2;m<=n;m++){
            for(int i=0;i<=n-m;i++){
                double min=999;
                int k=0;
                int j=i+m;
                w[i][j]=w[i][j-1]+p[j-1]+q[j];
                for(int t=i+1;t<=j;t++){
                    double sum=c[i][t-1]+c[t][j];
                    if(sum<min){
                        min=sum;
                        k=t;
                    }
                }
                c[i][j]=c[i][k-1]+c[k][j]+w[i][j];
                r[i][j]=k;
            }
        }
        display(w,c,r,n);
        root=createTree(0,n,r,data);
    }

    void display(double** w,double** c,double** r,int n){
        for(int i=0;i<n+1;i++){
            for(int j=i;j<n+1;j++){
                cout<<"("<<w[i][j]<<","<<c[i][j]<<","<<r[i][j]<<")"<<" ";
            }
            cout<<endl;
        }
    }


    Node* createTree(int i,int j,double**r,string* data){
        if(i!=j){
            int k=r[i][j];
            Node* t=new Node(data[k]);
            t->left=createTree(i,k-1,r,data);
            t->right=createTree(k,j,r,data);

            return t;
        }
        else{
            return NULL;
        }
    }

    void inorder(Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void preorder(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }

    void postorder(Node* root){
        if(root==NULL){
            return;

        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    OBST(){
        root==NULL;
    }

    
    
};
int main(){
    int n;
    cout<<"Enter the number of identifiers"<<endl;
    cin>>n;
    string data[n+1];
    data[0]="";
    for(int i=1;i<n+1;i++){
        cin>>data[i];
    }

    double* p=new double[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i<<"successfull probability"<<endl;
        cin>>p[i];
    }

    double* q=new double[n+1];
    for(int i=0;i<n+1;i++){
        cout<<"Enter the "<<i<<"unsuccessfull probability"<<endl;
        cin>>q[i];
    }

    OBST obj;
    while(true){
        cout<<"Enter 1 to display matrix"<<endl;
        cout<<"Enter 2 to display inorder"<<endl;
        cout<<"Enter 3 to display preorder"<<endl;
        cout<<"Enter 4 to display postorder"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            obj.cal_wt(p,q,n,data);    
        }
        else if(op==2){
            obj.inorder(obj.getroot());
        }
        else if(op==3){
            obj.preorder(obj.getroot());
        }
        else if(op==4){
            obj.postorder(obj.getroot());
        }
    }
    
    return 0;
}