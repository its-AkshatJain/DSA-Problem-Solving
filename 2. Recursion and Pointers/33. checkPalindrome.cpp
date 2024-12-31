#include <iostream>
using namespace std;

bool checkPalindrme(string s,int i,int j){
    // Base case
    if(i>j){
        return true;
    }

    if(s[i]!= s[j]){
        return false;
    }else{
        return checkPalindrme(s,i+1,j-1);
    }
}

// If input is number and we have to check if its binary is palindrome or not
bool decimalToBinary(long long N)
{
	string binary = "";
	while(N>0){
		binary += (N&1)?'1':'0';
		N=N>>1;
	}
	return checkPalindrme(binary,0, binary.length()-1);
}

int main(){
    string s = "abcde";
    string s1 = "naman";
    cout<<"String is Palindrome or not : "<<checkPalindrme(s1,0,s1.length()-1)<<endl;
    cout<<"Number is Palindrome or not : "<<decimalToBinary(5)<<endl;
}