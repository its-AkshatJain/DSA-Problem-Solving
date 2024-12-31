#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 

void reverse(vector<int> &arr){
    int s = 0;
    int e = arr.size()-1;
    while(s<e){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void rotate(vector<vector<int>>& matrix) {

    int n = matrix.size();

    // Transpose of matrix
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i=0;i<n;i++){
        reverse(matrix[i]);
        // reverse(matrix[i].begin(),matrix[i].end());
    }
}

void rotateA(vector<vector<int>>& matrix) {            //Akshat's Method
    vector<vector<int>> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    for(int i=0;i<col;i++){
        vector<int> v;
        for(int j=row-1;j>=0;j--){
            v.push_back(matrix[j][i]);
        }
        ans.push_back(v);
    }
    matrix = ans;
}

int main(){
    vector<vector<int>> v1;
    v1.push_back({2,3,4});
    v1.push_back({6,8,0});
    v1.push_back({5,9,1});

    rotate(v1);

    cout<<"Image rotated by 90 degree is : "<<endl;
    for(size_t i=0;i<v1.size();i++){
        for(size_t j=0;j<v1.size();j++){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }

    rotateA(v1);

    cout<<"Image rotated by 90 degree is : "<<endl;
    for(size_t i=0;i<v1.size();i++){
        for(size_t j=0;j<v1.size();j++){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }
}
