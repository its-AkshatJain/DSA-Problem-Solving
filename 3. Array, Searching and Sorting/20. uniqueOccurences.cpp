#include <iostream>
#include <vector>
// #include <unordered_map>
// #include <unordered_set>
using namespace std;

//using stl
// bool uniqueOccurrencesSTL(vector<int>& arr) {
//     unordered_map<int,int> countMap;
//     for(int i=0;i<arr.size();i++){
//     //for(int i: arr){
//         countMap[arr[i]]++;
//     }

//     unordered_set<int> countSet;
//     for(const auto& pair: countMap){
//             if(!countSet.insert(pair.second).second){
//                 return false;
//             }
//     }
//     return true;
// }

//Partially using stl
bool uniqueOccurrencesStl(vector<int>& arr) {
    const int max_value= 2001; //for -1000 to 1000
    int count[max_value] ={0};
    int occurences[max_value]={0};

    // Count occurrences of each number
    for(size_t i=0;i<arr.size();i++){
        count[arr[i]+1000]++; //handling negative values
    }

    // Check for unique occurrences
    for(int i=0;i<2001;i++){
        if(count[i]>0){
            if(occurences[count[i]] == 0){
                occurences[count[i]] = 1;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

//without using stl
bool uniqueOccurrences(int arr[],int size) {
    const int max_value= 2001; //for -1000 to 1000
    int count[max_value] ={0};
    int occurences[max_value]={0};

    // Count occurrences of each number
    for(int i=0;i<size;i++){
        count[arr[i]+1000]++; //handling negative values
    }

    // Check for unique occurrences
    for(int i=0;i<2001;i++){
        if(count[i]>0){
            if(occurences[count[i]] == 0){
                occurences[count[i]] = 1;
            }
            else{
                return false;
            }
        }
    }
    return true;
}
int main() {
    vector<int> arr1; 
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(2);
    arr1.push_back(1);
    arr1.push_back(1);
    arr1.push_back(3);
    cout<< uniqueOccurrencesStl(arr1) << endl; // true
    int arr[6] = {1, 2, 2, 1, 1, 3};
    cout<< uniqueOccurrences(arr,6) << endl; // true
    // vector<int> arr1 = {1, 2, 2, 1, 1, 3};
    // std::vector<int> arr2 = {1, 2};
    // std::vector<int> arr3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    // std::cout << std::boolalpha; // to print boolean values as true/false
    
    // std::cout << "Example 2: " << uniqueOccurrences(arr2) << std::endl; // false
    // std::cout << "Example 3: " << uniqueOccurrences(arr3) << std::endl; // true

    return 0;
}