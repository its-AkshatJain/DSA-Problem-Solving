#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-2;i++){
		// Avoid duplicate elements
        if (i > 0 && arr[i] == arr[i - 1]) continue;

		int target=K-arr[i];
		int left=i+1;
		int right=n-1;
		while(left<right){
			if(arr[left]+arr[right]==target){
				vector<int> v;
				v.push_back(arr[i]);
				v.push_back(arr[left]);
				v.push_back(arr[right]);
				ans.push_back(v);
				left++;
				right--;

				//skip duplicates
				while(left<right && arr[left]==arr[left-1]){
					left++;
				}
				while(left<right && arr[right]==arr[right+1]){
					right--;
				}
			}
			else if(arr[left]+arr[right]>target){
				right--;
			}
			else{
				left++;
			}
		}
	}
	return ans;
}

vector<vector<int>> findTriplets2(vector<int>arr, int n, int K) {
	// Write your code here.
	vector<vector<int>> ans;
    set<vector<int>> found;  // Use a set to track unique triplets
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(arr[i]+arr[j]+arr[k]==K){
					vector<int> v;
					v.push_back(arr[i]);
					v.push_back(arr[j]);
					v.push_back(arr[k]);
                    found.insert(v);
				}
			}
		}
	}

    for(const auto &triplet: found){
        ans.push_back(triplet);
    }
	return ans;
}

void display(const vector<vector<int>> &vec) {
    for (const auto &triplet : vec) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> arr;
    vector<vector<int>> answer;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(4);
    // answer=findTriplets(arr,6,12);
    answer=findTriplets2(arr,6,12);

    // for(size_t i=0;i<answer.size();i++){
    //     cout<<answer.at(i)<<" ";
    // }
    display(answer);
    return 0;
}