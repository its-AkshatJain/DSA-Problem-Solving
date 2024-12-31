#include <iostream>
using namespace std;

// Recursion
// base case banao
// Ek case ke liye solve karo or phir baki apne aap ho jaiga

int factorial(int n){
    // Base case
    if(n==0){  // 0! = 1
        return 1;
    }
    return n*factorial(n-1);
    // int smallerProblem = factorial(n-1);
    // int biggerProblem = n*smallerProblem;
    // return biggerProblem;
}

int powerof2(int n){
    // Base case 2^0=1
    if(n==0){
        return 1;
    }
    return 2*powerof2(n-1);
}

//Print counting
void tailCount(int n){
    // Base case
    if(n==0){
        return ;
    }
    cout<<n<<endl;  //Processing
    tailCount(n-1);
    // As Recursive relation is at the end it is tail recursion
}

void headCount(int n){
    // Base case
    if(n==0){
        return ;
    }
    headCount(n-1);
    cout<<n<<endl;  //Processing
    // As Processing is at the end or after Recursive relation => it is head recursion
}

void reachHome(int src,int dest){
    cout<<"Source is at "<<src<<" and destination is "<<dest<<endl;
    if(src == dest){
        return ;
    }
    reachHome(++src,dest);  // Increase source by one step
}

int fib(int n) {
        //Base case
        if(n==0 || n==1){
            return n;
        }
        // Recursive relation
        return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cout<<"Enter the no. : "<<endl;
    cin>>n;
    cout<<"Factorial is : "<<factorial(n)<<endl;
    cout<<"Power of 2 is : "<<powerof2(n)<<endl;
    cout<<"Tail Count is : "<<endl;
    tailCount(n);
    cout<<"Head Count is : "<<endl;
    headCount(n);
    reachHome(0,5);
    cout<<"5th term of fibonacci is : "<<fib(5)<<endl;
    
    return 0;
}