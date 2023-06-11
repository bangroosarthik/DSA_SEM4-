#include<iostream>
#include<fstream>
using namespace std;
class Node{
    string name,add,div;
    int roll;
    public:

    void add_data(){
        ofstream o;
        o.open("seq.txt",ios::app);
        if(!o){
            cout<<"Error in the file"<<endl;
            return;
        }

        string name,add,div;
        int roll;
        cout<<"Enter name of student"<<endl;
        cin>>name;
        cout<<"Enter address"<<endl;
        cin>>add;
        cout<<"Enter Division"<<endl;
        cin>>div;
        cout<<"Enter roll number: "<<endl;
        cin>>roll;

        o<<"Name: "<<name<<endl<<"Address: "<<add<<endl<<"Division: "<<div<<endl<<"Roll: "<<roll<<endl;
        o.close();
    }

    void deletion(){
        remove("seq.txt");
    }

    void display_search(){
        string name;
        cout<<"Enter name you wish to search"<<endl;
        cin>>name;
        ifstream i;
        i.open("seq.txt",ios::in);
        if(!i){
            cout<<"Error in file"<<endl;
            return;
        }
        
        string myname;
        bool found=false;
        while(getline(i,myname)){
            if(myname.find("Name: "+name)!=string::npos){
                found=true;
                cout<<name<<" Present in file"<<endl;
                cout<<myname<<endl;
                getline(i,myname);
                cout<<myname<<endl;
                getline(i,myname);
                cout<<myname<<endl;
                getline(i,myname);
                cout<<myname<<endl;
            }
        }
        if(!found){
            cout<<name<<"not present in file"<<endl;
        }
    }
};
int main(){
    Node obj;
    while(true){
        cout<<"Enter 1 to add data"<<endl;
        cout<<"Enter 2 to delete data"<<endl;
        cout<<"Enter 3 to search and display"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            obj.add_data();
        }
        else if(op==2){
            obj.deletion();
        }
        else if(op==3){
            obj.display_search();
        }
    }
    return 0;
}