#include <iostream>
using namespace std;

string replaceSpaces(string &str){
	// Write your code here.
	string temp= "";
	for(size_t i=0;i<str.length();i++){
		if(str[i]==' '){
			temp.push_back('@');
			temp.push_back('4');
			temp.push_back('0');
		}else{
			temp.push_back(str[i]);
		}
	}
	return temp;
}

void replaceSpacesInPlace(string &str){
	// Write your code here.
	int spaceCount=0;
    int originalLength = str.length();
    for(size_t i=0;i<str.length();i++){
        if(str[i]== ' '){
            spaceCount++;
        }
    }
    int newLength = originalLength + (spaceCount*2);
    // resize str
    str.resize(newLength);

    // now start from end and assign space with @40
    int j = newLength - 1;
	for(int i=originalLength-1;i>=0;i--){
		if(str[i]==' '){
			str[j-2] = '@';
            str[j-1] = '4';
            str[j] = '0';
            j=j-3;
		}else{
			str[j] = str[i];
            j--;
		}
	}
}

int main(){
    string s = "My name is Akshat Jain";
    // cin>>s;
    // cout<<s<<endl;
    string c = replaceSpaces(s);
    cout<<"Replacing Spaces with @40 : "<<c<<endl;

    replaceSpacesInPlace(s);
    cout<<"Replacing Spaces with @40 in place : "<<s<<endl;
}
