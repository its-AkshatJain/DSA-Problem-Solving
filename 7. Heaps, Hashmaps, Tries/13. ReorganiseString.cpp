#include <iostream>
#include<queue>
#include<vector>
#include<string>
#include <limits.h>
using namespace std;

string reorganizeString(string s) {
    typedef pair<int, char> P;
    // Find frequency of all the characters
    vector<int> count(26,0);
    int n = s.length();
    for(int i=0; i<n; i++){
        int index = s[i] - 'a';
        count[index]++;

        if(count[index] > (n+1)/2 ){
            return "";
        }
    }

    // Max heap
    priority_queue<P> pq;
    for(char ch= 'a'; ch <= 'z'; ch++){
        if(count[ch - 'a'] > 0){
            pq.push({count[ch-'a'], ch});
            // pq.push(make_pair(count[ch-'a'], ch));
        }
    } 

    string result = "";

    // Storing elements in a String 
    while(pq.size() >= 2){
        auto p1 = pq.top();
        pq.pop();

        auto p2 = pq.top();
        pq.pop();

        result.push_back(p1.second);
        p1.first--;

        result.push_back(p2.second);
        p2.first--;

        if(p1.first > 0){
            pq.push(p1);
        }

        if(p2.first > 0){
            pq.push(p2);
        }
    }

    if(!pq.empty()){
        result.push_back(pq.top().second);
    }

    return result;
}

string reorganizeString2(string s) {
    typedef pair<int, char> P;
    // Find frequency of all the characters
    vector<int> count(26,0);
    int n = s.length();

    int maxFreq = 0;
    char charMaxFreq;

    for(int i=0; i<n; i++){
        int index = s[i] - 'a';
        count[index]++;

        if(count[index] > maxFreq){
            maxFreq = count[index];
            charMaxFreq = s[i];
        }

        if(count[index] > (n+1)/2 ){
            return "";
        }
    }

    string result = s;
    int i = 0;

    // Max freq char ko alternate position pe daal do
    while(count[charMaxFreq - 'a']>0){
        result[i] = charMaxFreq;
        i+= 2; //Alternate
        count[charMaxFreq-'a']--;
    }

    // Place rest of the slots in empty slots in alternate fashion
    for(char ch='a'; ch<='z'; ch++){
        while(count[ch-'a']>0){
            if(i>n){
                i = 1;
            }
            result[i] = ch;
            i+=2;
            count[ch-'a']--;
        }
    }
    return result;
}

int main(){
    string s = "aabbbc";
    string s1 = "aaaaa";

    cout<<"Reorganised String : "<<reorganizeString(s)<<endl;
    cout<<"Reorganised String : "<<reorganizeString2(s1)<<endl;
}

