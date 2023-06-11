#include<iostream>
using namespace std;
class Heap{
    public:
    void accept(int arr[],int n){
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
    }

    void maxheapify(int arr[],int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        if(left<n && arr[left]>arr[largest]){
            largest=left;
        }
        if(right<n && arr[right]>arr[largest]){
            largest=right;
        }

        if(largest!=i){
            swap(arr[largest],arr[i]);
            maxheapify(arr,n,largest);
        }
    }

    void buildheap(int arr[],int n){
        for(int i=(n-2)/2;i>=0;i--){
            maxheapify(arr,n,i);
        }
    }

    void heapsort(int arr[],int n){
        buildheap(arr,n);
        for(int i=n-1;i>=1;i--){
            swap(arr[0],arr[i]);
            maxheapify(arr,i,0);
        }
    }




    void display(int arr[],int n){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    int n;
    cout<<"Enter the number of vertices in a heap"<<endl;
    cin>>n;
    int arr[n];
    Heap obj;
    while(true){
        cout<<"Enter 1 to accept vertices of heap"<<endl;
        cout<<"Enter 2 to display heap"<<endl;
        cout<<"Enter 3 to display heap using heap sort"<<endl;
        int op;
        cout<<"Enter option"<<endl;
        cin>>op;
        if(op==1){
            obj.accept(arr,n);
        }
        else if(op==2){
            obj.display(arr,n);
        }
        else if(op==3){
            obj.heapsort(arr,n);
            obj.display(arr,n);
        }
    }
    return 0;
}