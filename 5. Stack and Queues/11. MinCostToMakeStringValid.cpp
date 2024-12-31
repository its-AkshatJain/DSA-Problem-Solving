#include <iostream>
#include <stack>
using namespace std;

int findMinimumCost(string str) {
  // Write your code here
  // string length is odd
  if( str.length()%2 == 1){
    return -1;
  }

  stack<char> st;
  for(size_t i=0; i<str.length(); i++){
    char ch = str[i];
    if(ch == '{'){
      st.push(ch);
    }else{
      // ch is closing bracket
      if(!st.empty() && st.top()== '{'){
        st.pop();
      }else{
        st.push(ch);
      }
    }
  }

  // Now Stack contains Invalid Expression
  int a = 0, b = 0;
  while(!st.empty()){
    if(st.top() == '{'){
      b++;
    }else{
      a++;
    }
    st.pop();
  }

  int ans = (a+1)/2 + (b+1)/2;
  return ans;
}

int main(){
    // string s = "{}}{}}";
    string s = "{{{{";
    cout<<"Minimum Cost to make string valid is : "<<findMinimumCost(s)<<endl;
}