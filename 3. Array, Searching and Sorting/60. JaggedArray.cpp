#include <iostream>
using namespace std;

int main(){
    // Jagged Array
    int r=3;
    cout<<"Enter no. of rows : "<<endl;
    cin>>r;
    int * c = new int[r];  // col size array
    for(int i=0;i<r;i++){
        cout<<"Enter the no. of column in row-"<<i+1<<" : "<<endl;
        cin>>c[i];
    }

    int** arr1 = new int*[r]; 
    for(int i=0;i<r;i++){
        arr1[i] = new int[c[i]];
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c[i];j++){
            cin>>arr1[i][j];
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c[i];j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
}