#include <iostream>
#include <vector>
using namespace std;

// Power Set
// no of subsets = 2^n
void solve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
    // Base case
    int n = nums.size();
    if(index>= n){
        ans.push_back(output);
        return ;
    }
    // Exclude
    solve(nums,output,index+1,ans);
    // Include
    int element = nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);
    return ans;
}

int main(){
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);

    vector<vector<int>> ans = subsets(num);
    for(vector<int> subset : ans){
        for(int i: subset){
            cout<<i<<" ";
        }
        cout<<"|";
    }
    cout<<endl;

    return 0;
}
