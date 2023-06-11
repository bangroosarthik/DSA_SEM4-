//om siya ram
#include<iostream>
#define size 10
using namespace std;
class Node{
    string word;
    string meaning;
    Node* next;
    public:
    Node(){
        word="";
        meaning="";
        next=NULL;
    }
    Node(string word,string meaning){
        this->word=word;
        this->meaning=meaning;
        this->next=NULL;
    }
    friend class Chaining;
};
class Chaining{
    Node* HT[size];
    public:
    Chaining(){
        for(int i=0;i<size;i++){
            HT[i]=NULL;
        }
    }

    //hash func
    int hashfunc(string word){
        return (word[0]-'0')%size;
    }

    //insert function
    void insert(string word,string meaning){
        int index=hashfunc(word);
        
        //base case
        if(HT[index]==NULL){
            HT[index]=new Node(word,meaning);
            return;
        }
        Node* temp=HT[index];
        while(temp->next!=NULL){
            if(temp->word==word){
                cout<<"Duplicate word"<<endl;
                return;
            }
            temp=temp->next;
        }
        if(temp->word==word){
            cout<<"Duplicate word"<<endl;
            return;
        }

        temp->next=new Node(word,meaning);
    }

    void display(){
        for(int i=0;i<size;i++){
            Node* temp=HT[i];
            cout<<i<<"-> ";
            while(temp!=NULL){
                cout<<" "<<temp->word<<"-> "<<temp->meaning<<",";
                temp=temp->next;

            }
            cout<<endl;
        }
    }

    void search(string word){
        int index=hashfunc(word);
        Node* temp=HT[index];
        while(temp!=NULL){
            if(temp->word==word){
                cout<<word<<" is present"<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"Word not present"<<endl;

    }

    void deletion(string word){
        int index=hashfunc(word);
        Node* temp=HT[index];
        if(temp->word==word){
            HT[index]=temp->next;
            delete temp;
            cout<<word<<" deleted successfully"<<endl;
            return;
        }

        Node* prev=temp;
        temp=temp->next;
        while(temp->next!=NULL){
            if(temp->word==word){
                prev=temp->next;
                delete temp;
                cout<<word<<" deleted successfuly"<<endl;
                return;
            }
            prev=temp;
            temp=temp->next;
        }

        if(temp->word==word){
            prev->next=NULL;
            cout<<word<<" deleted successfully"<<endl;
            return;
        }
        cout<<"Word not found"<<endl;
    }
};
int main(){
    Chaining obj;
    while(true){
        cout<<"Enter 1 to insert word and meaning"<<endl;
        cout<<"Enter 2 to display "<<endl;
        cout<<"Enter 3 to search a word"<<endl;
        cout<<"Enter 4 to delete a word"<<endl;
        int op;
        cout<<"Enter the option"<<endl;
        cin>>op;
        if(op==1){
            cout<<"Enter word"<<endl;
            string word;
            cin>>word;
            cout<<"Enter meaning"<<endl;
            string meaning;
            cin>>meaning;
            obj.insert(word,meaning);
        }
        else if(op==2){
            obj.display();
        }
        else if(op==3){
            string word;
            cout<<"Enter word"<<endl;
            cin>>word;
            obj.search(word);
        }
        else if(op==4){
            string word;
            cout<<"Enter word"<<endl;
            cin>>word;
            obj.deletion(word);
        }
    }
    return 0;
}