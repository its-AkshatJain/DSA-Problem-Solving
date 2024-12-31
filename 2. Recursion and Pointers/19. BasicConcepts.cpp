#include <iostream>
using namespace std;
#define PI 3.14   // Object like macros
#define PRINT(x) cout<<x<<endl  //Function like macros

int score = 15;  // Global Variables

void a(int &i){
    i++;
    cout<<"From fn a : "<<i<<endl;;
}

int main(){
    int r = 7;
    int area = PI*r*r;
    PRINT(area);

    // Using Global variables is a bad practice
    // As it can be modified anywhere and can cause error instead use global variable
    score++;
    cout<<score<<endl;

    int i = 5;
    a(i);
    cout<<"From main : "<<i<<endl;

    return 0;
}