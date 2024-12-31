#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void displayVector(vector<int> v){
    for(int num: v){
        cout<<num<<" ";
    }
    cout<<endl;
}

// Sieve of Eratosthenes
int countPrimes(int n) {  //O(n*log(logn))
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                count++;
                for (int j = 2 * i; j < n; j = j + i) {
                    prime[j] = false;
                }
            }
        }
        return count;
    }

int countPrimes2(int n) {  //O(n^2)  will face tle
    int count = 0;
    for(int i=2; i<n;i++){
        bool isPrime = true;
        for(int j=2; j<=i/2;j++){
            if(i%j == 0){
                isPrime= false;
            }
        }
        if(isPrime){
            count++;
        }
    }
    return count;
}

// Sieve of Eratosthenes
vector<int> simpleSieve(int n) {  //O(n*log(logn))
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    vector<int> prime;
    // int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            // count++;
            prime.push_back(i);
            for (int j = 2 * i; j < n; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    return prime;
}

// Segmented Sieve 
//To find prime number between given values
vector<int> segmentedSieve(int l,int h) {
    int sq = floor(sqrt(h));

    vector<int> prime = simpleSieve(sq+1);
    // displayVector(prime);
    vector<bool> isPrime(h-l+1,true);
    vector<int> ansPrime;
    for(int p: prime){
        int sm = (l/p)*p;

        if(sm<l){
            sm = sm + p;
        }
        // cout<<sm+p<<endl;
        for(int i=sm; i<=h; i=i+p){
            isPrime[i-l] = false; 
            // cout<<i-l<<endl;
        }
    }
    for(int i=l; i<=h; i++){
        if(isPrime[i-l]){
            ansPrime.push_back(i);
        }
    }
    return ansPrime;
}

int main(){
    int n;
    cin>>n;
    cout<<"No. of primes :"<<countPrimes(n)<<endl;
    cout<<"Primes are : "<<endl;
    vector<int> primeArray = simpleSieve(n);
    displayVector(primeArray);
    cout<<"Primes b/w 6 and 10 are : "<<endl;
    vector<int> primeSegmented = segmentedSieve(6,10);
    displayVector(primeSegmented);
}