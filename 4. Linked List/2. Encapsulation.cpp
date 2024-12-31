#include <iostream>
using namespace std;

class Hero{
    private:
    string name;
    int age;
    int height;

    public:
    int getAge(){
        return this->age;
    }
};

int main(){
    Hero first;
    cout<<"Encapsulation sahi chal rha hai "<<endl;
}