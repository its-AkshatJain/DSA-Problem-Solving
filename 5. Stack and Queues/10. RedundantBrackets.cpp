#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> st;

    for(size_t i=0; i<s.length(); i++){
        char ch = s[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ){
            st.push(ch);
        }else{
            // Closing bracket ya lower case letter
            if(ch == ')'){
                // Check if there is any operator between opening and closing brackets
                bool isRedundant = true;
                while(!st.empty() && st.top() != '('){
                    char top = st.top();
                
                    if( top == '+' || top == '-' || top == '*' || top == '/'){
                        isRedundant = false;
                    }
                    st.pop();
                }
                if(isRedundant == true){
                    return true;
                }
                st.pop();   // to remove opening bracket also
            }
        }
    }
    return false;
}

int main(){
    // string s = "(a + b)";
    string s = "((a + b))";
    cout<<"String is reduntant or not : "<<findRedundantBrackets(s)<<endl;
}