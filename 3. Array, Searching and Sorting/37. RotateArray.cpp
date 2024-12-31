#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            // (i+k)%n gives value between 0 to n-1
            temp[(i + k) % n] = nums[i];
        }
        // Copying to nums
        nums=temp;
}

int main(){
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(0);

    rotate(v1,3);
    for(size_t i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}