#include <iostream>
using namespace std;

class TwoStack {
private:
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = num;
        }else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = num;
        }else{
            cout<<"Stack OverFlow"<<endl;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2<size){
            int ans = arr[top2];
            top2++;
            return ans;
        }else{
            return -1;
        }
    }
};

int main(){
    TwoStack s(5);

    s.push1(5);
    s.push1(6);
    s.push1(7);

    s.push2(11);
    s.push2(12);

    cout<<"Deleting element from stack1 : "<<s.pop1()<<endl;
    cout<<"Deleting element from stack2 : "<<s.pop2()<<endl;
}