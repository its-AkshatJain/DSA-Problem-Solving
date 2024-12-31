#include <iostream>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    int deficit = 0;
    int balance = 0;
    int start = 0;
    
    for(int i=0; i<n; i++){
        balance += p[i].petrol - p[i].distance;
        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    
    if(balance + deficit >= 0){
        return start;
    }else{
        return -1;
    }
}

int main(){
    petrolPump arr[4] = {{4, 6},{6, 5},{7, 3},{4, 5}};

    cout<<"To complete a circular tour we should start from : "<<tour(arr,4)<<endl;
}