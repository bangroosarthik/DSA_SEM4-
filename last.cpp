#include<iostream>
#include<fstream>
using namespace std;
class Hash{
    int address;
    public:
    friend class random;

};
class random{
    int emp_id;
    int emp_sal;
    char name[40];
    char exp[40];
    char add[40];

    Hash HT[10];
    public:
    random(){
        for(int i=0;i<10;i++){
            HT[i].address=-1;
            emp_id=0;
        }
    }

    void add_data(){
        int n;
        cout<<"Enter the number of employees you wish to insert"<<endl;
        cin>>n;
        ofstream fout;
        fout.open("last.txt",ios::out);

        for(int i=0;i<n;i++){
            cout<<"Enter id"<<endl;
            cin>>emp_id;
            cout<<"Enter name"<<endl;
            cin>>name;
            cout<<"Enter salary"<<endl;
            cin>>emp_sal;
            cout<<"Enter exper"<<endl;
            cin>>exp;
            cout<<"Enter add"<<endl;
            cin>>add;
        

        int loc=fout.tellp();
        int index=emp_id%10;

        HT[index].address=loc;
        fout<<"ID: "<<emp_id<<endl<<"Name: "<<name<<endl<<"Sal: "<<emp_sal<<endl<<"exp: "<<exp<<endl<<"Add: "<<add<<endl;
        cout<<"("<<loc<<","<<index<<")"<<endl;
        }
        fout.close();
    }


    void display(){
        fstream f;
        
        f.open("last.txt",ios::in);
        char data[80];
        f.seekg(0,ios::beg);
        while(!f.eof()){
            for(int i=0;i<6;i++){
                f.getline(data,40);
                cout<<data<<endl;
            }
        }

        f.close();

        //displaying hash table 
        for(int i=0;i<10;i++){
            cout<<i<<" ->";
            cout<<HT[i].address<<" "<<endl;
        }
    }

    void search(){
        int id;
        cout<<"Enter the id you wish to search"<<endl;
        cin>>id;
        int index=id%10;
        int loc=HT[index].address;

        ifstream f;
        f.open("last.txt",ios::in);
        f.seekg(loc,ios::beg);
        char data[200];
        for(int i=0;i<6;i++){
            f.getline(data,200);
            cout<<data<<" "<<endl; 
        }
        f.close();
    }

    void deletion(){
        int id;
        cout<<"Enter id you wish to delete"<<endl;
        cin>>id;

        fstream first,second;
        first.open("last.txt",ios::in);
        second.open("temp.txt",ios::out);
        string mytext;
        bool found=false;
        while(getline(first,mytext)){
            if(mytext.find("ID: "+to_string(id))==string::npos){
                second<<mytext<<" "<<endl;
                //delete
            }
            else{
                found=true;
                for(int i=0;i<6;i++){
                    getline(first,mytext);
                }
            }

        }

        first.close();
        second.close();

        remove("last.txt");
        rename("temp.txt","last.txt");
        if(found){
            cout<<"Data deleted successfully"<<endl;
        }
        else{
            cout<<"Data is not present"<<endl;
        }
    }
    
};
int main(){
    random obj;
    while(true){
        cout<<"Enter 1 to add data in file"<<endl;
        cout<<"Enter 2 to display data "<<endl;
        cout<<"Enter 3 to search data"<<endl;
        cout<<"Enter 4 to delete data"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            obj.add_data();
        }
        else if(op==2){
            obj.display();
        }
        else if(op==3){
            obj.search();
        }
        else if(op==4){
            obj.deletion();
        }
    }
    return 0;
}