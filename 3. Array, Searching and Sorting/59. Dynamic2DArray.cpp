#include <iostream>
using namespace std;

int main(){
    int m,n;
    cout<<"Enter no. of rows and columns : "<<endl;
    cin>>m>>n;

    // Creating 2D Array
    int** arr = new int*[m];
    for(int i=0; i<m;i++){
        arr[i] = new int[n];
    }
    // Input
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // Output
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    // Releasing 2D Array memory
    for(int i=0; i<m; i++){
        delete[] arr[i];
    }
    delete[] arr;
}