#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string digits,string output,int index,vector<string>& ans,string mapping[]){
    int n =digits.length();
    if(index>=n){
        ans.push_back(output);
        return ;
    }

    int number = digits[index] - '0';
    string value = mapping[number];
    for(size_t i = 0; i<value.length();i++){
        output.push_back(value[i]);
        solve(digits,output,index+1,ans,mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits == ""){
        return ans;
    }
    string output;
    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,index,ans,mapping);
    return ans;
}

int main(){
    string digits;
    cin >> digits;
    vector<string> ans = letterCombinations(digits);
    for(string combination : ans){
        cout<<combination<<" | ";
    }
    cout<<endl;

    return 0;
}