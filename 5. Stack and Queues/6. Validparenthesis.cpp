#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    for(size_t i=0; i<s.length(); i++){
        // If Open bracket : stack push 
        // If Close bracket : stacktop Check and pop
        char ch = s[i];
        if(ch == '(' || ch == '{' || ch == '['){
            st.push(ch);
        }else{   // If Close bracket
            if (!st.empty()) {
              if ((ch == ')' && st.top() == '(') ||
                  (ch == '}' && st.top() == '{') ||
                  (ch == ']' && st.top() == '[')){
                      st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }

    if(st.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s = "{([])}";
    cout<<s<<endl;

    cout<<"Is valid Parenthesis or not : "<<isValidParenthesis(s)<<endl;
    
}