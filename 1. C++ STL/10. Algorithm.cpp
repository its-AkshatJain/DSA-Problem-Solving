#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Iterator lower_bound (Iterator first, Iterator last, const val)  
// lower_bound returns an iterator pointing to the first element in the range [first,last) which 
// has a value not less than ‘val’  and if the value is not present in the vector then it returns the end iterator.

// Iterator upper_bound (Iterator first, Iterator last, const val)
// upper_bound returns an iterator pointing to the first element in the range [first,last) which 
// has a value greater than ‘val’  and if the value is not present in the vector then it returns the end iterator.

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding 6 : "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"Lower Bound : "<<lower_bound(v.begin(),v.end(),6) - v.begin()<<endl;
    cout<<"Upper Bound : "<<upper_bound(v.begin(),v.end(),6) - v.begin()<<endl;

    int a=5;
    int b=3;

    cout<<"Max : "<<max(a,b)<<endl;
    cout<<"Min : "<<min(a,b)<<endl;

    swap(a,b);
    cout<<"{a,b}"<<a<<" "<<b<<endl;

    string abcd ="abcd";
    reverse(abcd.begin(),abcd.end());
    cout<<abcd<<endl;
            //start     middle   end
    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"After Rotate : "<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    // It uses intro sort to sort. it is combination of quick, insertion and heap sort.
    sort(v.begin(),v.end());
    cout<<"After Sorting : "<<endl;
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}