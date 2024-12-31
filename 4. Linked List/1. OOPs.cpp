#include <iostream>
#include <cstring>
// #include "Hero.cpp"   // If you have created hero class on seperate file import it
using namespace std;

// Default constructor do shallow copy
// In shallow copy it creates a pointer which stores the address of value and when value gets updated it also updates

// Deep copy we create a new variable and copy the value to it so when value gets updated it does not updates

// Copy assignment operator '=' -  copy one object to other a = b

// const int var = 5;   it cannot be leaved uninitialised and cannot be changed

// Initialisation list : Point(int i = 0, int j = 0): x(i), y(j) {} you can define constructor like this also x(i) means x = i;

// Static keyword is accessed without creating class object.

class Hero{
    // Properties
    private:
    int health;

    public:
    // int health;
    char level;
    char *name;
    static int timetoComplete;

    static int random(){
        // static fn can only use static variable
        return timetoComplete;
    }
    
    // Default constructor
    Hero(){
        cout<<"Constructor called. "<<endl;
        name = new char[100];
    }

    // Parameteised constructor
    Hero(int health){
        // this is a pointer which stores the address of current object
        this->health = health;
    }
    Hero(int health,char level){
        this->level = level;
        this->health = health;
    }

    // Copy constructor
    Hero(Hero& temp){
        // Deep copy
        char *ch = new char[100];
        strcpy(ch,temp.name);
        this->name= ch;
        this->health = temp.health;
        this->level = temp.level;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setlevel(char l){
        level = l;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }

    void print(){
        cout<<"Name is : "<<this->name<<endl;
        cout<<"Health is : "<<this->health<<endl;
        cout<<"Level is : "<<this->level<<endl;
    }

    // Destructor: deallocates dynamic Memory
    ~Hero(){
        cout<<"Destructor bhai called"<<endl;
    }
};

int Hero:: timetoComplete = 5;

int main(){

    // // creation of object
    // Hero ramesh;
    // // ramesh.health = 70;
    // ramesh.setHealth(70); // using setter
    // ramesh.level = 'A';   

    // // cout<<"Health of Ramesh is : "<<ramesh.health<<endl;
    // cout<<"Health of Ramesh is : "<<ramesh.getHealth()<<endl;  // using getter

    // cout<<"Level of Ramesh is : "<<ramesh.level<<endl;
    // cout<<"Size of class : "<<sizeof(ramesh)<<endl;

    // // static allocation
    // // Hero a;
    // Hero a(40);
    // // a.setHealth(80);
    // a.setlevel('B');
    // cout<<"Health is : "<<a.getHealth()<<endl;
    // cout<<"Level is : "<<a.getLevel()<<endl;
    // // Dynamic Allocation
    // Hero *b = new Hero;
    // // Hero *b = new Hero(); 
    // b->setHealth(90);
    // b->setlevel('C');
    // cout<<"Health is : "<<(*b).getHealth()<<endl;
    // cout<<"Level is : "<<(*b).getLevel()<<endl;
    // cout<<"Health is : "<<b->getHealth()<<endl;
    // cout<<"Level is : "<<b->getLevel()<<endl;

    // Hero S;
    // S.print();

    // Hero R(S);
    // R.print();

    // Hero hero1;
    // hero1.setHealth(35);
    // hero1.setlevel('Z');
    // char name[7] = "Akshat";
    // hero1.setName(name);
    // hero1.print();

    // // use default copy constructor i.e comment the copy constructor that you have created
    // // Hero hero2 = hero1;
    // Hero hero2(hero1); 
    // hero2.print();

    // hero1.name[0] = 'B';
    // hero1.print();

    // hero2.print();  // hero2 is also updated it is shallow copy

    cout<<Hero::timetoComplete<<endl;
    cout<<Hero::random()<<endl;
}