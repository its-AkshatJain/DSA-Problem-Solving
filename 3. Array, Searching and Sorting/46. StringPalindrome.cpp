#include <iostream>
using namespace std;

bool isAlnum(char ch){
    if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z') || (ch>='0'&&ch<='9')){
        return 1;
    }
    else{
        return 0;
    }
}

bool checkPalindrome(string s)
{
    // Write your code here.
    int start=0;
    int end= s.length() - 1;

    while(start<end){
        while(start<end && !isalnum(s[start]) ){
            start++;
        }
        while(start<end && !isalnum(s[end]) ){
            end--;
        }
        
        if(tolower(s[start])==tolower(s[end])){
            start++;
            end--;
        }else{
            return 0;
        }
    }
    return 1;
}

int main(){
    string name;
    cout<<"Enter the name : ";
    cin>>name;
    cout<<"Name is : "<<name<<endl;
    cout<<"Palindrome or Not : "<<checkPalindrome(name)<<endl;
    cout<<isAlnum('@');
}