#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> ans;
    for(int col=0;col<mCols;col++){
        if(col&1){
            // odd : bottom to top
            for(int row=nRows-1;row>=0;row--){
                ans.push_back(arr[row][col]);
            }
        }
        else{
            for(int row=0;row<nRows;row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> v1;
    v1.push_back({2,3,4});
    v1.push_back({6,8,0});

    vector<int> v2 = wavePrint(v1,2,3);

    cout<<"Wave Print : "<<endl;
    for(size_t i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
}