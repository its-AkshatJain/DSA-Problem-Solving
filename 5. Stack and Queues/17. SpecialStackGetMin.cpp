#include <iostream>
#include <stack>
using namespace std;

// Design a stack that supports getMin() in O(1) time and O(1) extra
class SpecialStack{
    public:
    stack<int> s;
    int mini;
    void push(int data) {
        // Implement the push() function.
        // For first element
        if(s.empty()){
            s.push(data);
            mini = data;
        }else{
            if(data < mini){
                int val = 2*data - mini;
                s.push(val);
                mini = data; 
            }else{
                s.push(data);
            }
        }
    }

    void pop() {
        // Implement the pop() function.
        // UnderFlow condition
        if(s.empty()){
            return ;
        }

        int curr = s.top();
        s.pop();

        if(curr > mini){
            return ;            
        }else{
            int val = 2*mini - curr;
            mini = val;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr < mini){
            return mini;
        }else{
            return curr;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        return mini;
    }  
};

int main(){
    SpecialStack s;
    s.push(54);
    s.push(92);
    s.push(14);
    s.push(1);
    s.push(60);

    cout<<"Min element is : "<<s.getMin()<<endl;

    s.pop();
    cout<<"Min element is : "<<s.getMin()<<endl;
    s.pop();
    cout<<"Min element is : "<<s.getMin()<<endl;

    cout<<"Top element of stack is : "<<s.top()<<endl;
}