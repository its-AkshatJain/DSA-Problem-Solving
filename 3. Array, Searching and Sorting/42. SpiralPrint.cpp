#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 

vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();

        int count=0;
        int total=row*col;
        vector<int> ans;

        //index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow =row-1;
        int endingCol =col-1;

        while(count<total){
            //Printing starting row
            for(int index=startingCol; count<total && index<=endingCol; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            //Printing ending col
            for(int index=startingRow; count<total && index<=endingRow; index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            //Printing ending row
            for(int index=endingCol; count<total && index>=startingCol; index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            //Printing starting col
            for(int index=endingRow; count<total && index>=startingRow; index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
    return ans;
    }

int main(){
    vector<vector<int>> v1;
    v1.push_back({2,3,4});
    v1.push_back({6,8,0});
    v1.push_back({5,9,1});

    vector<int> v2 = spiralOrder(v1);

    cout<<"Spiral Print : "<<endl;
    for(size_t i=0;i<v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<endl;
}