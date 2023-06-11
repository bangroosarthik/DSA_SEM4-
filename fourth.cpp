#include<iostream>
#define size 10
using namespace std;
class Node{
    long int tele;
    string name;
    public:
    Node(){
        tele=0;
        name="";
    }
    Node(long int tele,string name){
        this->tele=tele;
        this->name=name;
    }
    friend class Hash;
};
class Hash{
    Node HT[size];

    public:

    //hash function
    int hashfunction(long int tele){
        return tele%size;
    }

    //insert without replacement or with replacement
    void insert_without(long int tele,string name){
        int index=hashfunction(tele);
        int preindex;
        //empty hash table 
        if(HT[index].tele==0){
            HT[index].tele=tele;
            HT[index].name=name;
        }
        else{
            
            while(HT[index].tele!=0){
                preindex=index;
                index=(index+1)%size;
            }

            HT[index].tele=tele;
            HT[index].name=name;
        }
    }



    void insert_with(long int tele,string name){
        int index=hashfunction(tele);
        int preindex;
        if(HT[index].tele==0){
            HT[index].tele=tele;
            HT[index].name=name;
        }
        else{
            //check whether the index matches with the index of the number present at that location
            if(index==hashfunction(HT[index].tele)){
                
                while(HT[index].tele!=0){
                    index=(index+1)%size;
                }
                HT[index].tele=tele;
                HT[index].name=name;
            }
            else{
                Node temp=HT[index];
                HT[index].tele=tele;
                HT[index].name=name;

                insert_with(temp.tele,temp.name);
            }
        }
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<i<<" "<<HT[i].tele<<" "<<HT[i].name<<endl;
        }
    }

    int search(long int tele){
        int count=1;
        int index=hashfunction(tele);
        if(HT[index].tele==tele){
            cout<<"Telephone number exist in directory in "<<count<<" comparisons"<<endl;
            return index;
        }
        else{
            while(HT[index].tele!=0){
                index=(index+1)%size;
                if(HT[index].tele==tele){
                    count++;
                    cout<<"Telephone number exist in directory in "<<count<<" comparisons"<<endl;
                    return index;
                }
            }
        }
        return index;
    }

    void deletion(long int tele){
        int index=hashfunction(tele);
        if(HT[index].tele==tele){
            HT[index].tele=0;
            HT[index].name=" ";
            cout<<"Deleted successfully"<<endl;
        }
        else{
            cout<<"Not present in directory"<<endl;
        }
    }



};
int main(){
    Hash obj,obj1;
    while(true){
        cout<<"Enter 1 to insert <tele,name> "<<endl;
        cout<<"Enter 2 to display hash tables"<<endl;
        cout<<"Enter 3 to search a telephone number"<<endl;
        cout<<"Enter 4 to delete telephone number"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            int n;
            cout<<"Enter the number of telephone numbers you wish to insert"<<endl;
            cin>>n;
            for(int i=0;i<n;i++){
                long int tele;
                string name;
                cout<<"Enter <tele,name>"<<endl;
                cin>>tele>>name;
                obj.insert_without(tele,name);
                obj1.insert_with(tele,name);
            }
        }
        else if(op==2){
            cout<<"WITHOUT REPLACEMENT"<<endl;
            obj.display();
            cout<<endl;
            cout<<"----------------------------------------------------------------"<<endl;
            cout<<"WITH REPLACEMENT"<<endl;
            obj1.display();
            cout<<endl;
        }
        else if(op==3){
            long int tele;
            cout<<"Enter telephone number you wish to search"<<endl;
            cin>>tele;
            cout<<"WITHOUT REPLACEMENT"<<endl;
            obj.search(tele);
            cout<<"-----------------------"<<endl;
            cout<<"WITH REPLACEMENT"<<endl;
            obj1.search(tele);
            cout<<endl;
        }
        else if(op==4){
            long int tele;
            cout<<"Enter telephone number you wish to delete"<<endl;
            cin>>tele;
            cout<<"After Deletion "<<endl;
            obj.deletion(tele);
            cout<<"WITHOUT REPLACEMENT"<<endl;
            obj.display();
            cout<<endl;
            cout<<"WITH REPLACEMENT"<<endl;
            obj1.deletion(tele);
            obj1.display();
        }
        else{
            cout<<"Thankyou"<<endl;
        }
    }
    return 0;
}