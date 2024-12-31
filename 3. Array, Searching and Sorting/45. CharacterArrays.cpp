#include <iostream>
#include <cstring>
using namespace std;

int getLength(char name[]){
    int count=0;
    for(int i=0; name[i] !='\0'; i++){
        count++;
    }
    return count;
}

void reverse(char name[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s++],name[e--]);
    }
}

char toLowerCase(char ch){
    char l;
    if(ch>='a' && ch<='z'){
        return ch;
    }else{
        l = ch - 'A' + 'a';
        // char U = ch - 'a' + 'A';   // To get in upper case
        // char n = ch - '0';         // To get number in int form from char from
    }
    return l;
}

bool checkPalindrome(char arr[],int n){
    int s=0;
    int e=n-1;
    while(s<e){
        if(toLowerCase(arr[s])==toLowerCase(arr[e])){
            s++;
            e--;
        }else{
            return 0;
        }
    }
    return 1;
}

int main(){
    char name[20];
    char c[]="Hello";
    char a[25];
    // char name[20] = {'A','k','s','h','a','t'};
    cout<<"Enter the name : ";
    cin>>name;
    // If you will enter Akshat Jain the it will take only Akshat and terminate at space

    cout<<"Name is : "<<name<<endl;
    // int len = getLength(name);
    int len = strlen(name);
    cout<<"Length is : "<<len<<endl;
    string s = "qwerty ke";
    cout<<"in case of string Length is : "<<s.length()<<endl;

    // Compare  
    // 0               : The strings are equal.
    // A positive value: The first string is greater than the second string.
    // A negative value: The first string is less than the second string.
    cout<<"Element are equal(0) or not : "<<strcmp(name,c)<<endl;
    // in case of strings
    // s.compare(s2); same as char arrays
    // s.compare(index,length,s2);  compare length no of elements from index

    //Copy
    strcpy(a,c);
    cout<<"a is : "<<a<<endl;
    // a=c;  // In case of string

    reverse(name,len);
    cout<<"Reversed Name is : "<<name<<endl;

    cout<<"To Lower Case : "<<toLowerCase('c')<<endl;
    cout<<"To Lower Case : "<<toLowerCase('D')<<endl;

    cout<<"Palindrome or Not : "<<checkPalindrome(name,len)<<endl;

    return 0;
}