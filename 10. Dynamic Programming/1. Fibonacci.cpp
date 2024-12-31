#include<bits/stdc++.h>
using namespace std;

// Top-Down Approach
int fib1(int n, vector<int> &dp){
        // Base case
        if(n<=1){
           return n;
        }

        // Step 3
        if(dp[n] != -1){
           return dp[n];
        }
        
        // Step 2
        dp[n] = fib1(n-1, dp) + fib1(n-2, dp);
        return dp[n];
}

// Bottom-up Approach
int fib2(int n, vector<int> &dp){
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
}

// Space - optimisation
int fib3(int n){
    int prev1 = 1;
    int prev2 = 0;

    if(n==0){
        return prev2;
    }
    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
      int n;
      cin>>n;

      // Step 1
      vector<int> dp(n+1);
      for(int i=0; i<=n; i++){
        dp[i] = -1;
      }

      // cout<<fib1(n, dp)<<endl;
      cout<<fib2(n, dp)<<endl;
      cout<<fib3(n)<<endl;

      return 0;
}