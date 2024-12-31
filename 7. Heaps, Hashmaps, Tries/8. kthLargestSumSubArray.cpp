#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	vector<int> sumStore;
	int n = arr.size();

	for(int i=0; i<n; i++){
		int sum = 0;

		for(int j=i; j<n; j++){
			sum += arr[j]; 
			sumStore.push_back(sum);
		}
	}

	sort(sumStore.begin(), sumStore.end());

	return sumStore[sumStore.size() - k];
}

int main(){
    vector<int> a;
    a.push_back(50);
    a.push_back(55);
    a.push_back(53);
    a.push_back(52);
    a.push_back(51);
    a.push_back(60);


    cout<<"Sum of Kth Largest subarray :"<<getKthLargest(a, 3)<<endl;
}