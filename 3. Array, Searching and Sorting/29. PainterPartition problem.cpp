#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

int possibleSol(const vector<int> &boards, int k, int mid){
    int lengthSum=0;
    int noOfPainter=1;

    for(size_t i=0; i<boards.size(); i++){
        if(lengthSum + boards[i]<=mid){
            lengthSum += boards[i];
        }else{
            noOfPainter++;
            if(noOfPainter>k || boards[i]>mid){
                return false;
            }
            lengthSum = boards[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s=0;
    int sum;
    for(size_t i=0; i<boards.size();i++){
        sum += boards[i];
    }
    int e= sum;
    int mid, ans=-1;

    while(s<=e){
        mid= s+(e-s)/2;
        if(possibleSol(boards,k,mid)){
            ans=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> vec;
    vec.push_back(48);
    vec.push_back(90);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(1);

    cout<<"The min board size :"<<findLargestMinDistance(vec,2);
    return 0;
}