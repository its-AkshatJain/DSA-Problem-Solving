#include <iostream>
#include <vector>
// #include <string>
using namespace std;

// No. of permutations = n! , where n is length of string
void solve(vector<int> nums,vector<vector<int>>& ans,int index){
    // Base case
    int n = nums.size();
    if(index>=n){
        ans.push_back(nums);
        return ;
    }

    for(size_t j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        solve(nums,ans,index+1);
        // Backtrack
        swap(nums[index],nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    int index = 0;
    solve(nums,ans,index);
    return ans;
}


int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);

    vector<vector<int>> ans = permute(num);
    for(vector<int> subset : ans){
        for(int i: subset){
            cout<<i<<" ";
        }
        cout<<"|";
    }
    cout<<endl;

    return 0;
}