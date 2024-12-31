#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
        int ansIndex = 0;
        int n = chars.size();

        int i=0;
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            // Loop se bahar 2 condition mai aa sakta hai
            // it encounters new character
            // it reached the end of char array
            chars[ansIndex++] = chars[i];
            int count = j-i;
            if(count>1){
                //converting count to single digit and storing it
                string str = to_string(count);
                for(char ch: str){
                    chars[ansIndex++] = ch;
                }
            }
            i=j;
        }
        return ansIndex;
    }

    int main(){
    vector<char> v1;
    v1.push_back('a');
    v1.push_back('a');
    v1.push_back('a');
    v1.push_back('a');
    v1.push_back('a');
    v1.push_back('b');
    v1.push_back('b');
    v1.push_back('b');
    v1.push_back('c');
    v1.push_back('d');
    v1.push_back('d');
    // ans array --> {'a','5','b','3','c','d','2'}
    cout<<"Size of answer array : "<<compress(v1)<<endl;
   
}