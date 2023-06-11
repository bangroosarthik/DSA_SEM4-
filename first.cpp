#include<iostream>
#include<queue>
using namespace std;
class Node{
    int data;
    Node* left;
    Node* right;

    public:
    Node(){
        data=0;
        left=NULL;
        right=NULL;
    }

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    friend class BST;
};
class BST{
    Node* root;

    //insert function 
    Node* insertIntoBST(Node* root,int data){
        if(root==NULL){
            return new Node(data); 
        }
        else if(root->data>data){
            root->left=insertIntoBST(root->left,data);
        }
        else if(root->data<data){
            root->right=insertIntoBST(root->right,data);
        }
        else{
            cout<<"Duplicate value"<<endl;
            return root;
        }

    }
    void takeinput(int data){
        int n;
        cout<<"Enter the data"<<endl;
        cin>>n;
        while(n!=-1){
            insertIntoBST(root,data);
            cin>>n;
        }
        
    }

    // traversals using recursion 
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

    //level order Traversal 

    void levelorderTraversal(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(q.empty()==false){
            Node* temp=q.front();
            q.pop();
            if(temp==NULL){
                cout<<endl;
                if(q.empty()==false){
                    q.push(NULL);
                }
            }
            else{
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
    }
    //Number of nodes in longest path

    int heightoflongest(Node* root){
        if(root==NULL){
            return 0;
        }
        else{
            return max(heightoflongest(root->left),heightoflongest(root->right))+1;
        }
    }

    //iterative 
    int heightiter(Node* root){
        Node* temp=root;
        int lcount=0;
        int rcount=0;
        while(temp->left!=NULL){
            lcount+=1;
            temp=temp->left;
        }
        while(temp->right!=NULL){
            rcount+=1;
            temp=temp->right;
        }

        if(lcount>rcount){
            return lcount+1;
        }
        else{
            return rcount+1;
        }

    }

    //min and max

    int minVal(Node* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root->data;
    }

    int maxVal(Node* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root->data;
    }

    void swapping(Node* root){
        if(root==NULL){
            return;
        }
        else{
            Node* temp=root->left;
            root->left=root->right;
            root->right=temp;

            swapping(root->left);
            swapping(root->right);
        }
    }

    // bool searchInBST(Node* root,int val){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     if(root->data==val){
    //         return 1;
    //     }
    //     else if(root->data<val){
    //         return searchInBST(root->right,val);
            
    //     }
    //     else if(root->data>val){
    //         return searchInBST(root->left,val);
            
    //     }
    // }

    bool searchInBST(Node* root,int val){
        Node* temp=root;
        while(temp!=NULL){
            if(temp->data==val){
                return 1;
            }
            else if(temp->data>val){
                temp=temp->left;
            }
            else {
                temp=temp->right;
            }
        }
        return 0;
    }

    //------------------------------------------------------------------------------------------------------------

    public:

    BST(){
        root=NULL;
    }

    void insert(int data){
        root=insertIntoBST(root,data);
    }

    void increasing(){
        inorder(root);
    }

    void post(){
        postorder(root);
    }

    void pre(){
        preorder(root);
    }
    void displayTree(){
        levelorderTraversal(root);
    }

    void height(){
        cout<<heightoflongest(root)<<endl;
    }

    void heightit(){
        cout<< heightiter(root)<<endl;
    }

    void mini(){
        cout<<minVal(root)<<endl;
    }
    void Maxi(){
        cout<<maxVal(root)<<endl;
    }

    void swaa(){
        swapping(root);
    }

    void search(int val){
        if(searchInBST(root,val)==1){
            cout<<"Node is present"<<endl;
        }
        else{
            cout<<"Node is not present"<<endl;
        }
    }
};
int main(){
    BST obj;
    while(true){
        cout<<"Enter 1 to insert Node in BST"<<endl;
        cout<<"Enter 2 to display tree in increasing order"<<endl;
        cout<<"Enter 3 to display preorder traversal"<<endl;
        cout<<"Enter 4 to display in postorder traversal"<<endl;
        cout<<"Enter 5 to display tree"<<endl;
        cout<<"Enter 6 to display height of longest path using recursion"<<endl;
        cout<<"Enter 7 to display height of longest path without using recursion"<<endl;
        cout<<"Enter 8 to display min value of tree"<<endl;
        cout<<"Enter 9 to display max value of a tree"<<endl;
        cout<<"Enter 10 to swap left and right pointers"<<endl;
        cout<<"Enter 11 to search a node"<<endl;
        int op;
        cout<<"Enter option: "<<endl;
        cin>>op;
        if(op==1){
            int n;
            cout<<"Enter the number of elements you wish to insert"<<endl;
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Enter the "<<i<<" element"<<endl;
                int ele;
                cin>>ele;
                obj.insert(ele);
            }
        }
        else if(op==2){
            cout<<"Displaying in inorder (increasing order)"<<endl;
            obj.increasing();
            cout<<endl;
        }
        else if(op==3){
            cout<<"Displaying in preorder"<<endl;
            obj.pre();
            cout<<endl;
        }
        else if(op==4){
            cout<<"Displaying in postorder"<<endl;
            obj.post();
            cout<<endl;
        }
        else if(op==5){
            cout<<"Displaying tree"<<endl;
            obj.displayTree();
        }
        else if(op==6){
            cout<<"Height of longest path using recursion"<<endl;
            obj.height();
        }
        else if(op==7){
            cout<<"Height of longest path using iterative"<<endl;
            obj.heightit();
        }
        else if(op==8){
            cout<<"Minimum value in a tree"<<endl;
            obj.mini();
        }
        else if(op==9){
            cout<<"Maximum value in a tree"<<endl;
            obj.Maxi();
        }
        else if(op==10){
            cout<<"Before swapping"<<endl;
            obj.displayTree();
            cout<<"After Swapping"<<endl;
            obj.swaa();
            obj.displayTree();
        }
        else if(op==11){
            int val;
            cout<<"Enter the value you wish to search"<<endl;
            cin>>val;
            obj.search(val);
        }

    }
    return 0;
}