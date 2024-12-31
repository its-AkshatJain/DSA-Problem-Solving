#include <iostream>
#include <queue>
using namespace std;

int solve(int *arr, int n, int k){
    deque<int> maxi;
    deque<int> mini;

    // Addition(finding maxi and mini) of first k size window
    for(int i=0; i<k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for(int i=k; i<n; i++){
        ans += arr[maxi.front()] + arr[mini.front()];

        // next window
        // Removal
        while(!maxi.empty() && maxi.front() - i >= k){
            maxi.pop_front();
        }
        while(!mini.empty() && mini.front() - i >= k){
            mini.pop_front();
        }

        // Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    // For last window
    ans += arr[maxi.front()] + arr[mini.front()];

    return ans;
}

int solve2(int *arr, int n, int k){
    deque<int> maxi;
    deque<int> mini;

    // Addition of first k size window
    for(int i=0; i<k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];
    for(int i=k; i<n; i++){
        // next window
        // Removal
        while(!maxi.empty() && maxi.front() - i >= k){
            maxi.pop_front();
        }
        while(!mini.empty() && mini.front() - i >= k){
            mini.pop_front();
        }

        // Addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main(){
    int arr[7] = {2,5,-1,7,-3,-1,-2};
    cout<<solve2(arr,7,4)<<endl;
}