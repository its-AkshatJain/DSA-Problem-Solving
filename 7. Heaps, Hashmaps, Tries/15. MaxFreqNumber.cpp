#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maximumFrequency(vector<int> &arr)
{
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0; i<arr.size(); i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i=0; i<arr.size(); i++){
        if (maxFreq == count[arr[i]]) {
          maxAns = arr[i];
          break;
        }
    }
    return maxAns;
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);

    cout<<"Find max Frequency number : "<<maximumFrequency(v)<<endl;
}