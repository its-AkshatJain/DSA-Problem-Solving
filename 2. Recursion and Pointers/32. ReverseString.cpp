#include <iostream>
using namespace std;

void reverse(string &s,int start, int end){
    // Base case
    if(start>=end){
        return ; 
    }

    swap(s[start],s[end]);
    return reverse(s,start+1,end-1);
}

void reverse2(string &s,int i){
    // Base case
    int n = s.length();
    if(i>=(n-1)){
        return ; 
    }

    swap(s[i],s[(n-1)-i]);
    i++;
    return reverse2(s,i);

}

int main(){
    string s = "abcde";
    // reverse(s,0,s.length()-1);
    reverse2(s,0);
    cout<<"Reverse of string : "<<s<<endl;
}