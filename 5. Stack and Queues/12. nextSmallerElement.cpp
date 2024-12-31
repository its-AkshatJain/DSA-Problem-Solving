#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=n-1; i>=0; i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }

        // Stack top containssmaller element
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i=0; i<n; i++){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }

        // Stack top containssmaller element
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(4);
    arr.push_back(3);

    vector<int> ans1 = nextSmallerElement(arr,4);
    for(int i : ans1){
        cout<<i<<" ";
    }
    cout<<endl;

    vector<int> ans2 = prevSmallerElement(arr,4);
    for(int i : ans2){
        cout<<i<<" ";
    }
    cout<<endl;
}