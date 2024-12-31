#include <iostream>
using namespace std;

// Modular and Fast Exponention
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int result = 1;
	while(n>0){
		if(n&1){
			// odd
			result = (1LL * result * (x)%m)%m;
		}
		// 1LL is used to typecast to long long
		x=(1LL * (x)%m * (x)%m);
		n = n>>1;
	}
	return result;
}

int main(){
    int ans = modularExponentiation(5,3,4);
    cout<<ans<<endl;

    return 0;
}