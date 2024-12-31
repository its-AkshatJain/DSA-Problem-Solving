#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std; 

vector<int> reverse(vector<int> v){
	int s=0;
	int e=v.size()-1;
	while(s<e){
		swap(v[s],v[e]);
		s++;
		e--;
	}
	return v;
}

vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	int i=n-1;
	int j=m-1;
	int carry=0;
	vector<int> ans;

	while(i>=0 && j>=0){
		int val1=a[i];
		int val2=b[j];
		int sum= val1+val2+carry;
		carry=sum/10;
		int value=sum%10;
		ans.push_back(value);
		i--;
		j--;
	}

	// First case
	while(i>=0){
		int val1=a[i];
		int sum= val1+carry;
		carry=sum/10;
		int value=sum%10;
		ans.push_back(value);
		i--;
	}

	// Second case
	while(j>=0){
		int val2=b[j];
		int sum= val2+carry;
		carry=sum/10;
		int value=sum%10;
		ans.push_back(value);
		j--;
	}

	// Third case
	while(carry!=0){
		int sum= carry;
		carry=sum/10;
		int value=sum%10;
		ans.push_back(value);
	}

	return reverse(ans);
}

int main(){
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(6);
    
    vector<int> v2;
    v2.push_back(8);
    v2.push_back(0);

    vector<int> v3 = findArraySum(v1,4,v2,2);
    // 2 3 4 6
    // +   8 0
    // --------
    // 2 4 2 6
    cout<<"Sum of Arrays is : "<<endl;
    for(size_t i=0;i<v3.size();i++){
        cout<<v3[i]<<" ";
    }
    cout<<endl;
}