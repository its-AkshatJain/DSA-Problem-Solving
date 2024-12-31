// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.

// You are also given an integer 'k' which denotes the number of aggressive cows.

// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.

// Print the maximum possible minimum distance.

#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

int isPossible(vector<int> &stalls, int k, int mid){
    int cowsCount = 1;
    int lastPos= stalls[0];

    for(size_t i=0;i<stalls.size();i++){
        if(stalls[i] - lastPos>=mid){
            cowsCount++;
            if(cowsCount==k){
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int s=0;
    int maxi =-1;
    for(size_t i=0;i<stalls.size();i++){
        maxi = max(maxi,stalls[i]);
    }
    int e=maxi;
    int mid,ans=-1;

    while(s<=e){
        mid=s+(e-s)/2;
        
        if(isPossible(stalls,k,mid)){
            ans = mid;
            s=mid+1;
        }
        else{
            e = mid - 1;
        }
    }
    return ans;
}


int main(){
    vector<int> vec;
    vec.push_back(0);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(10);
    vec.push_back(9);

    cout<<"Max Difference between Aggressive Cows :"<<aggressiveCows(vec,4);
    return 0;
}