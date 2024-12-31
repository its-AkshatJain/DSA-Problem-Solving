#include <iostream>
using namespace std;

bool isPresent(int arr[][4],int key,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==key){
                return true;
            }
        }
    }
    return false;
}

void  rowWiseSum(int arr[3][4],int row,int col){
    for(int i=0;i<row;i++){
        int rowSum = 0;
        for(int j=0;j<col;j++){
            rowSum += arr[i][j];
        }
        cout<<rowSum<<endl;
    }
}

void  columnWiseSum(int arr[3][4],int row,int col){
    for(int i=0;i<col;i++){
        int columnSum = 0;
        for(int j=0;j<row;j++){
            columnSum += arr[j][i];
        }
        cout<<columnSum<<" ";
    }
    cout<<endl;
}

void  largestRowSum(int arr[3][4],int row,int col){
    int maxi= INT_MIN;
    int rowIndex= -1;
    for(int i=0;i<row;i++){
        int rowSum = 0;
        for(int j=0;j<col;j++){
            rowSum += arr[i][j];
        }
        if(rowSum>maxi){
            maxi= rowSum;
            rowIndex=i;
        }
    }
    cout<<"Largest row sum index and value is  : "<<rowIndex<<" "<<maxi<<" respectively."<<endl;
}

int main(){
    int arr[3][4];
    int m=3,n=4;
    // int arr1[3][2]={1,5,7,9,6,4};
    // int arr2[3][3]={{1,11,111},{2,22,222},{3,33,333}};

    // Row-wise Input
    cout<<"Enter the elements for 3*4 Array : "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

    // Column-wise Input
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<3;j++){
    //         cin>>arr[j][i];
    //     }
    // }

    // Printing array -(row-wise)
    cout<<"Printing array : "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    int key;
    cout<<"Enter the element to search : "<<endl;
    cin>>key;
    //Searching in 2D Array
    if(isPresent(arr,key,m,n)){
        cout<<"Element Found!"<<endl;
    }else{
        cout<<"Element Not Found!"<<endl;
    }

    cout<<"Row-wise Sum :"<<endl;
    rowWiseSum(arr,m,n);

    cout<<"Column-wise Sum :"<<endl;
    columnWiseSum(arr,m,n);

    largestRowSum(arr,m,n);
    
}