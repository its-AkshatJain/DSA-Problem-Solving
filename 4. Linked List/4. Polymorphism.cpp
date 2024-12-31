#include <iostream>
using namespace std;

// Compile time Polymorphism  - static
// Function Overloading
class A{
    public:
    void sayHello(){
        cout<<"Hello from Akshat Jain"<<endl;
    }

    void sayHello(string name){
        cout<<"Hello from "<<name<<endl;
    }

    int sayHello(string name, int n){
        cout<<"Hello from "<<name<<endl;
        return n;
    }

    int sayHello(char ch){
        cout<<"Hello from "<<ch<<endl;
        return 1;
    }
};

// Operator overloading
class B{
    public: 
    int a,b;

    public:
    int add(){
        return a+b;
    }

    void operator+(B &obj){
        int value1 = this->a;
        int value2 = obj.a;

        cout<<"Output is : "<<value1 - value2<<endl;
    }

    void operator() (){
        cout<<"Mai breacket hu :) "<<this->a<<endl;
    }
};


// Runtime Polymorphism - dynamic
// Method overriding
class Animal{
    public:
    void speak(){
        cout<<"Speaking! "<<endl;
    }
};

class Dog{
    public:
    void speak(){
        cout<<"Barking! "<<endl;
    }
};


int main(){
    // A obj;
    // obj.sayHello();

    // B obj1,obj2;
    // obj1.a = 7;
    // obj2.a = 3;
    // obj1 + obj2;
    // obj1();

    Animal a1;
    Dog d1;
    a1.speak();
    d1.speak();

    return 0;
}