#include <iostream>
using namespace std;

bool checkEqual(int arr1[],int arr2[]){
    for(int i=0;i<26;i++){
        if(arr1[i] != arr2[i]){
            return 0;
        }
    }
    return 1;
}


bool checkInclusion(string s1, string s2) {
    int count1[26] = {0};
    // Finding count of elements in s1
    for(size_t i=0;i<s1.length();i++){
        int index = s1[i] - 'a';
        count1[index]++;
    }

    size_t i=0;
    size_t windowSize = s1.length();
    int count2[26] = {0};
    // for first window
    while(i<windowSize && i<s2.length()){
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if(checkEqual(count1,count2)){
        return 1;
    }

    // for further windows
    while(i<s2.length()){
        int newChar = s2[i];
        int index = newChar - 'a';
        count2[index]++;

        int oldChar= s2[i-windowSize];
        index = oldChar - 'a';
        count2[index]--;

        if(checkEqual(count1,count2)){
            return 1;
        }
        i++;
    }
    return 0;
}

int main(){
    string a1 = "ab";
    string a2 = "eidbaooo";
    cout<<"a1 is present in a2 or not : "<<checkInclusion(a1,a2)<<endl;
}