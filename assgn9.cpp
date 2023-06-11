#include<iostream>
using namespace std;
class Node{
    int word;
    string meaning;
    Node* left;
    Node* right;
    int height;
    public:
    Node(){
        word=0;
        meaning="";
        left=NULL;
        right=NULL;
        height=1;
    }
    Node(int word,string meaning){
        this->word=word;
        this->meaning=meaning;
        this->left=NULL;
        this->right=NULL;
        this->height=1;
    }
    friend class AVL;
};
class AVL{
    Node* root;

    

    int height(Node* node){
        if(node==NULL){
            return 0;
        }
        return node->height;
    }

    int balancefact(Node* node){
        if(node==NULL){
            return 0;
        }
        return height(node->left)-height(node->right);
    }

    //LEFT LEFT
    Node* left_left(Node* x){
        Node* y=x->left;
        Node* t1=y->right;

        //after rotation
        y->right=x;
        x->left=t1;

        x->height=max(height(x->left),height(x->right))+1;
        y->height=max(height(y->left),height(y->right))+1;

        return y;
    }

    Node* right_right(Node* x){
        Node* y=x->right;
        Node* t1=y->left;


        //after rotation
        y->left=x;
        x->right=t1;

        x->height=max(height(x->left),height(x->right))+1;
        y->height=max(height(y->left),height(y->right))+1;

        return y;
    }


    Node* left_right(Node* x){
        Node* y=x->left;
        Node* z=y->right;
        Node* t2=z->left;
        Node* t3=z->right;

        //after rotation
        z->left=y;
        z->right=x;
        y->right=t2;
        x->left=t3;

        x->height=max(height(x->left),height(x->right))+1;
        y->height=max(height(y->left),height(y->right))+1;
        z->height=max(height(z->left),height(z->right))+1;
        
        return z;
    }

    Node* right_left(Node* x){
        Node* y=x->right;
        Node* z=y->left;
        Node* t4=z->left;
        Node* t5=z->right;

        //after rotation
        z->left=x;
        z->right=y;
        x->right=t4;
        y->left=t5;
        
        x->height=max(height(x->left),height(x->right))+1;
        y->height=max(height(y->left),height(y->right))+1;
        z->height=max(height(z->left),height(z->right))+1;
        
        return z;
    }

    Node* insert(Node* root,int word,string meaning){
        if(root==NULL){
            return new Node(word,meaning);
        }
        else if(root->word<word){
            root->right=insert(root->right,word,meaning);
            
        }
        else if(root->word>word){
            root->left=insert(root->left,word,meaning);
            
        }
        else{
            cout<<"Duplicate word"<<endl;
            return root;
        }

        //updating height 
        root->height=max(height(root->left),height(root->left))+1;
        //updating balance factor
        int bf=balancefact(root);

        if(bf>1 && word<root->left->word){
            return left_left(root);
        }
        else if(bf<1 && word>root->right->word){
            return right_right(root);
        }
        else if(bf>1 && word>root->left->word){
            return left_right(root);
        }
        else if(bf<1 && word<root->right->word){
            return right_left(root);
        }
        
        return root;
    }

    void inorder(Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<"("<<root->word<<","<<root->meaning<<")"<<" ";
        inorder(root->right);
    }

    int count=0;
    bool search(Node* root,int word){
        if(root->word==word){
            count+=1;
            cout<<"Number of comparisons required "<<count<<endl;
            return 1;
        }
        else if(root->word>word){
            count+=1;
            return search(root->left,word);
        }
        else if(root->word<word){
            count+=1;
            return search(root->right,word);
        }
        
    }
    public:
    AVL(){
        root=NULL;
    }

    void insertAVL(int word,string meaning){
        root=insert(root,word,meaning);
    }

    void display(){
        inorder(root);
    }
    
    void searchAVL(int word){
        if(search(root,word)==1){
            cout<<"word is present"<<endl;
        }
        else{
            cout<<"word is not present"<<endl;
        }
    }

};
int main(){
    AVL obj;
    while(true){
        cout<<"Enter 1 to insert into AVL"<<endl;
        cout<<"Enter 2 to display AVL"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            int n;
            cout<<"Enter number of words you wish to enter"<<endl;
            cin>>n;
            for(int i=0;i<n;i++){
                int word;
                string meaning;
                cout<<"Enter word "<<endl;
                cin>>word;
                cout<<"Enter meaning"<<endl;
                cin>>meaning;
                obj.insertAVL(word,meaning);

            }
        }
        else if(op==2){
            obj.display();
        }
        else if(op==3){
            int word;
            cout<<"Enter word"<<endl;
            cin>>word;
            obj.searchAVL(word);
        }
    }
    return 0;
}