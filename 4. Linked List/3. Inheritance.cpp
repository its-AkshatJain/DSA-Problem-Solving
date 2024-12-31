#include <iostream>
using namespace std;

class Human{
    private:
    int age;

    public:
    int height;
    int weight;

    public:
    int getAge(){
        return this->age;
    }

    void setWeight(int w){
        return this->weight = w;
    }
};

            // Access modifier and parent class name
class Male : public Human{
    public:
    string color;

    void sleep(){
        cout<<"Male sleeping"<<endl;
    }
}

int main(){
    Male object1;
    cout<<object1.weight<<endl;
    cout<<object1.height<<endl;

    cout<<object1.color<<endl;
}