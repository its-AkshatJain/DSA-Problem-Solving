#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class NStack
{
    int *arr;
    int *top;
    int *next;

    int n,s;
    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialise top
        for(int i=0; i<n; i++){
            top[i] = -1;
        }
        // Initialise next
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        // Update last index with -1
        next[s-1] = -1;

        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Check for overflow
        if(freespot == -1){
            return false;
        }
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // Push the element to stack
        arr[index] = x;

        // Update next
        next[index] = top[m-1];

        // Update top
        top[m-1] = index;

        return  true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Write your code here.
        // Check for underFlow
        if(top[m-1] == -1){
            return -1;
        }

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main(){
    NStack s(4,10);
    s.push(15,2);
    s.push(2,3);

    s.pop(3);
}