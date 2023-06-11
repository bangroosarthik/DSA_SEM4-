#include<iostream>
#include<queue>
#include<stack>
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
    friend class BT;
};

class BT{
    Node* root;
    
    //insert or create binary tree

    Node* insertIntoBT(Node* root){
        //first take root data 
        int data;
        cout<<"Enter data of node"<<endl;
        cin>>data;
        root=new Node(data);

        if(data==-1){
            return NULL;
        }
        cout<<"Enter data left of "<<data<<endl;
        root->left=insertIntoBT(root->left);
        cout<<"Enter data right of "<<data<<endl;
        root->right=insertIntoBT(root->right);
        

        return root;
    }

    //using recursion preorder inorder and postorder
    void preorder(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }

    void inorder(Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }


    void postorder(Node* root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    //iterative traversals

    void inorderiter(Node* root){
        stack<Node*> st;
        Node* curr=root;
        while(st.empty()==false || curr!=NULL){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            Node* temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            curr=temp;
            curr=curr->right;
        }
    }


    void preorderiter(Node* root){
        stack<Node*> st;
        st.push(root);
        while(st.empty()==false){
            //print as pre
            Node* temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            if(temp->right!=NULL){
                st.push(temp->right);
            }
            if(temp->left!=NULL){
                st.push(temp->left);
            }
        }
    }


    void postiter(Node* root){
        stack<Node*> st;
        Node* curr=root;
        while(curr!=NULL || st.empty()==false){
            while(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            Node* temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                cout<<temp->data<<" ";
                while(!st.empty() && temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    cout<<temp->data<<" ";
                }
            }
            else{
                curr=temp;
            }
        }
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

    //using recursion
    int height(Node* root){
        if(root==NULL){
            return 0;
        }
        else{
            return max(height(root->left),height(root->right))+1;
        }
    }

    int heightt(Node* root){
        Node* temp=root;
        if(temp==NULL){
            return 0;
        }
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

    //clone 
    Node* clone(Node* root){
        if(root==NULL){
            return NULL;
        }
        
            Node* nn=new Node(root->data);
            nn->left=clone(root->left);
            nn->right=clone(root->right);

            return nn;
    }

    int countleaves(Node* root){
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        return countleaves(root->left)+countleaves(root->right);
    }

    int countinternal(Node* root){
        if(root==NULL || (root->left==NULL && root->right==NULL )){
            return 0;
        }
        return 1+countinternal(root->left)+countinternal(root->right);

    }

    Node* erase(Node* root){
        if(root==NULL){
            return NULL;
        }
        erase(root->left);
        erase(root->right);

        cout<<"deleted node is "<<root->data<<endl;
        delete root;
    }

    public:
    BT(){
        root=NULL;
    }

    void insert(){
        root=insertIntoBT(root);
    }

    void in(){
        inorder(root);
    }

    void pre(){
        preorder(root);
    }
    void post(){
        postorder(root);
    }

    void levl(){
        levelorderTraversal(root);
    }

    void swap(){
        swapping(root);
    }

    void heightrec(){
        cout<<height(root);
    }

    void heightiter(){
        cout<<heightt(root);
    }

    void copytree(){
        root=clone(root);
    }

    void countLeaf(){
        cout<<countleaves(root);
    }

    void countinternal(){
        cout<<countinternal(root);
    }

    void eraseAllNodes(){
        erase(root);
    }

    void iterin(){
        inorderiter(root);
    }

    void preiter(){
        preorderiter(root);
    }

    void piter(){
        postiter(root);
    }

};

int main(){
    BT obj;
    while(true){
        cout<<"Enter 1 to insert into BT"<<endl;
        cout<<"Enter 2 to display inorder traversal"<<endl;
        cout<<"Enter 3 to display preorder traversal"<<endl;
        cout<<"Enter 4 to display postorder traversal"<<endl;
        cout<<"Enter 5 to display level order traversal"<<endl;
        cout<<"Enter 6 to swap left and right pointers"<<endl;
        cout<<"Enter 7 to display height using recursion"<<endl;
        cout<<"Enter 8 to display height without using recursion"<<endl;
        cout<<"Enter 9 to copy one tree to another"<<endl;
        cout<<"Enter 10 to count number of leaves"<<endl;
        cout<<"Enter 11 to count number of internal nodes"<<endl;
        cout<<"Enter 12 to erase all nodes"<<endl;
        cout<<"Enter 13 to display inorder using iterative"<<endl;
        cout<<"Enter 14 to display preorder using iterative"<<endl;
        cout<<"Enter 15 to display postorder using iterative"<<endl;
        
        int op;
        cout<<"Enter option: "<<endl;
        cin>>op;
        if(op==1){
            obj.insert();
        }
        else if(op==2){
            cout<<"Inorder Traversal of tree is :"<<endl;
            obj.in();
            cout<<endl;
        }
        else if(op==3){
            cout<<"Preorder traversal of tree is : "<<endl;
            obj.pre();
            cout<<endl;
        }
        else if(op==4){
            cout<<"Postorder traversal of tree is: "<<endl;
            obj.post();
            cout<<endl;
        }
        else if(op==5){
            cout<<"Level order Traversal of tree is: "<<endl;
            obj.levl();
            cout<<endl;
        }
        else if(op==6){
            cout<<"Swapping recursion"<<endl;
            obj.swap();
            cout<<"After swapping"<<endl;
            obj.levl();
            cout<<endl;
        }
        else if(op==7){
            cout<<"Height of tree using recursion"<<endl;
            obj.heightrec();
        }
        else if(op==8){
            cout<<"Height of tree without recursion"<<endl;
            obj.heightiter();
        }
        else if(op==9){
            cout<<"Copying one tree to another"<<endl;
            obj.copytree();
        }
        else if(op==10){
            cout<<"Count number of leaves"<<endl;
            obj.countLeaf();
        }
        else if(op==11){
            cout<<"Number of internal nodes are"<<endl;
            obj.countinternal();
        }
        else if(op==12){
            cout<<"Erasing all nodes"<<endl;
            obj.eraseAllNodes();
        }
        else if(op==13){
            cout<<"Iterative traversal using inorder"<<endl;
            obj.iterin();
        }
        else if(op==14){
            cout<<"Iterative traversal using preorder"<<endl;
            obj.preiter();

        }
        else if(op==15){
            cout<<"Iterative traversal using postorderr"<<endl;
            obj.piter();
        }


    }

    return 0;
}