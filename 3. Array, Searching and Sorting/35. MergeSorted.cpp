#include <iostream>
#include <vector>
using namespace std;


//Merge nums1 and nums2 and store it in nums1
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v;
        for (int i = 0; i < m; i++) {
            v.push_back(nums1[i]);
        }

        int i = 0;
        int j = 0, k = 0;
        while (i < m && j < n) {
            if (v[i] < nums2[j]) {
                nums1[k++] = v[i++];
            } else {
                nums1[k++] = nums2[j++];
            }
        }

        // copying v
        while (i < m) {
            nums1[k++] = v[i++];
        }
        // copying nums2
        while (j < n) {
            nums1[k++] = nums2[j++];
        }
    }

int main(){
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(6);
    v1.push_back(8);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(5);
    v2.push_back(7);

    merge(v1,5,v2,4);
    for(size_t i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}