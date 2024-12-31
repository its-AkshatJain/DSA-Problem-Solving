#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(string str,string output,int index,vector<string>& ans){
	// base case
    int n = str.length();
	if(index>=n){
		if(output.length()>0){
			ans.push_back(output);
		}
		return ;
	}

	// Exclude
	solve(str,output,index+1,ans);

	// Include
	char element= str[index];
	output.push_back(element);
	solve(str,output,index+1,ans);
}

vector<string> subsequences(string str){
	
	// Write your code here
	vector<string> ans;
	string output = "";
	int index = 0;
	solve(str,output,index,ans);
	return ans;
}


int main(){
    string s = "abc";

    vector<string> ans = subsequences(s);
    for(string subset : ans){
        cout<<subset<<" | ";
    }
    cout<<endl;

    return 0;
}
