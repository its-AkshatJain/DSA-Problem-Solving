#include <iostream>
using namespace std;

// The isPossible function checks whether it's possible to allocate books such that no student gets more than mid pages. There are two key conditions here:

// If the current sum of pages plus the current book exceeds mid, allocate the current book to the next student.
// If the number of students exceeds n or if a single book has more pages than mid, return false.
        // no of students , no of books, no. of pages resp.
// bool isPossible(int n, int m, int arr[],int mid){
//     int sumOfPages = 0;
//     int noOfStudent = 1;
//     for (int i = 0; i < m; i++){
//         if(sumOfPages + arr[i] <= mid){
//             sumOfPages += arr[i];
//         }else{
//             noOfStudent++;
//             if(noOfStudent>n || arr[i]>mid){
//                 return false;
//             }
//             sumOfPages = arr[i];
//         }
//     }
//     return true;
// }

bool isPossible(int n, int m, int arr[],int mid,int sumOfPages = 0,int noOfStudent = 1,int index = 0){
    // Base case
    if(index == m){
        return true;
    }
    // for (int i = 0; i < m; i++){
    if(sumOfPages + arr[index] <= mid){
        sumOfPages += arr[index];
        return isPossible(n,m,arr,mid,sumOfPages,noOfStudent,index + 1);
    }else{
        noOfStudent++;
        if(noOfStudent>n || arr[index]>mid){
            return false;
        }
        sumOfPages = arr[index];
        return isPossible(n,m,arr,mid,sumOfPages,noOfStudent,index + 1);
    }
}

        // no of students , no of books, no. of pages resp.
int bookAllocation( int n, int m, int arr[],int start,int end,int ans = 0){ 
    // Base case
    if(start>end){
        return ans;
    }
    int mid = start + (end -start)/2;
    if(isPossible(n,m,arr,mid)){
        ans = mid;
        return bookAllocation(n,m,arr,start,mid-1,ans);
    }else{
        return bookAllocation(n,m,arr,mid+1,end,ans);
    }
}

void callBookAllocation( int n, int m, int arr[]){
    int start = 0;
    int sum = 0;
    for(int i=0; i<m; i++){
        sum = sum + arr[i];
    }
    int end = sum;
    cout<<"Max pages assigned to student is minimum : "<<bookAllocation(n,m,arr,start,end);
}

int main(){
    int arr[4] = {10,20,30,40};
    callBookAllocation(2,4,arr);
}