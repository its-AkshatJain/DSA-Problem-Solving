#include <iostream>
using namespace std;

// You have been given a number of stairs. Initially, you are at the 0th stair, 
// and you need to reach the Nth stair.
// Each time, you can climb either one step or two steps.
// You are supposed to return the number of distinct ways you can climb from the 0th step to the Nth step.

int distinctWaysToClimbStairs(int nStairs){
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }
    return distinctWaysToClimbStairs(nStairs-1) + distinctWaysToClimbStairs(nStairs-2);
}
// this solution is not optimised you can use dynamic programming to optimise it

int main(){
    cout<<"No. of distinct ways to climb stairs using 1 or 2 step :"<<distinctWaysToClimbStairs(5)<<endl;
}