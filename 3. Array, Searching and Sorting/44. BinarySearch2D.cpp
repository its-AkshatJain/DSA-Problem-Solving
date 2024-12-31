#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

// Given matrix is sorted in a row and starting element of next row is greater than ending element of previous row
// 1 2 3
// 4 5 6
// 7 8 9
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int s = 0;
        int e = (row * col) - 1;
        int mid;

        while (s <= e) {
            mid = s + (e - s) / 2;
            int element = matrix[mid / col][mid % col];
            if (element == target) {
                return true;
            } else if (element < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return false;
    }

// Given matrix is sorted in a row and column
// 1 4 7
// 2 5 8
// 3 6 9
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col - 1;

    while (rowIndex < row && colIndex >= 0) {
        int element = matrix[rowIndex][colIndex];
        if (element == target) {
            return 1;
        } else if (element < target) {
            rowIndex++;
        } else {
            colIndex--;
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> v1;
    v1.push_back({1,2,3});
    v1.push_back({4,5,6});
    v1.push_back({7,8,9});

    for(size_t i=0;i<v1.size();i++){
        for(size_t j=0;j<v1.size();j++){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;
    }

    if(searchMatrix1(v1,8)){
        cout<<"Element Found! "<<endl;
    }else{
        cout<<"Element not Found! "<<endl;
    }
    
    vector<vector<int>> v2;
    v2.push_back({1,4,7});
    v2.push_back({2,5,8});
    v2.push_back({3,6,9});

    for(size_t i=0;i<v2.size();i++){
        for(size_t j=0;j<v2.size();j++){
            cout<<v2[i][j]<<" ";
        }
        cout<<endl;
    }

    if(searchMatrix2(v2,3)){
        cout<<"Element Found! "<<endl;
    }else{
        cout<<"Element not Found! "<<endl;
    }

    return 0;
}