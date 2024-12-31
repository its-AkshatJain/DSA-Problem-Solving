#include <iostream>
using namespace std;

char maxOccurenceCharacter(string s){
    int arr[26]={0};
    int number = 0;
    // Creating count array for characters
    for(size_t i=0; i<s.length();i++){
        char ch = s[i];
        if(ch>='a' && ch<='z'){
            //lowercase
            number = ch - 'a';     // since a-z  0-25
            arr[number]++;
        }else{
            number = ch - 'A';     // since A-Z  0-25
            arr[number]++;
        }
    }

    // Finding character with maximum occurence
    int maxi = -1;
    int ans = 0;
    for(int i=0;i<26;i++){
        if(arr[i]>maxi){
            ans = i;
            maxi=arr[i];
        }
    }
    char finalAns;
    if(maxi<=1){
        finalAns = '-';
    }else{
        finalAns = ans + 'a';
    }
    cout<<"Max occurrence count : "<<maxi<<endl;
    return finalAns;
}

int main(){
    string s;
    cin>>s;
    // cout<<s<<endl;
    char c = maxOccurenceCharacter(s);
    cout<<"Max Occurence Character : "<<c<<endl;
}