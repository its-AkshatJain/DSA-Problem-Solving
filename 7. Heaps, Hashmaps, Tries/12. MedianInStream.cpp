#include <iostream>
#include<queue>
#include<vector>
using namespace std;

int signum(int a, int b){
	if(a==b){
		return 0;
	}else if(a > b){
		return 1;
	}else{
		return -1;
	}
}

void callMedian(int element, priority_queue<int> &maxh,
				priority_queue<int, vector<int>, greater<int> > &minh, int &median){

	switch(signum(maxh.size(), minh.size())){
		case 0: if(element > median){
					minh.push(element);
					median = minh.top();
				}else{
					maxh.push(element);
					median = maxh.top();				
				}	
				break;
		case 1: if(element > median){
					minh.push(element);
					median = (minh.top() + maxh.top())/2;
				}else{
					minh.push(maxh.top());
					maxh.pop();
					maxh.push(element);
					median = (minh.top() + maxh.top())/2;		
				}
				break;
		case -1: if(element > median){
					maxh.push(minh.top());
					minh.pop();
					minh.push(element);
					median = (minh.top() + maxh.top())/2;	
				}else{
					maxh.push(element);
					median = (minh.top() + maxh.top())/2;	
				}
				break;
		}						

				
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int> > minheap;

	int median = 0;

	for(int i=0; i<n; i++){
		callMedian(arr[i], maxheap, minheap, median);
		ans.push_back(median);
	}

	return ans;
}

int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(3);
    v.push_back(8);

    vector<int> ans = findMedian(v, 3);
    cout<<"Median of a stream is : "<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    // After reading first element of stream, Median of [5] is 5
    // After reading second element of stream, Median of [5, 3]  = floor((5+3)/2)  = 4
    // After reading third element of stream, Median of [5,3,8] = 5 , it is the middle value of the sorted array
    // So the output will be 5 4 5.
}