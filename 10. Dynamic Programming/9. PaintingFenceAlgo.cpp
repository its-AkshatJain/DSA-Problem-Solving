#include <bits/stdc++.h>
#define MOD 1000000007

int add(int a, int b){
    return ((a%MOD)+(b%MOD))%MOD;
}

int mul(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}

// Recursion
int solve(int n, int k){
    // Base case
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k, k-1));
        // K + K*(K-1)
    }

    int ans = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));
    return ans;
}

int numberOfWays1(int n, int k) {
    return solve(n,k);
}

// Recursion + memoization
int solveMem(int n, int k, vector<int> &dp){
    // Base case
    if(n==1){
        return k;
    }
    if(n==2){
        return add(k, mul(k, k-1));
        // K + K*(K-1)
    }

    if(dp[n] != -1){
        return dp[n];
    }
    
    dp[n] = add(mul(solveMem(n-2, k,dp), k-1), mul(solveMem(n-1, k, dp), k-1));
    return dp[n];
}

int numberOfWays2(int n, int k) {
    vector<int> dp(n+1, -1);
    return solveMem(n,k, dp);
}

// Tabulation
int solveTab(int n, int k){
    vector<int> dp(n+1, 0);

    // Base case
    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));
    
    for(int i=3; i<=n; i++){
       dp[i] = add( mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }
    
    return dp[n];
}

int numberOfWays(int n, int k) {
    return solveTab(n,k);
}

// Space optimisation
int solveSpaceOP(int n, int k){
    // Base case
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));
    
    for(int i=3; i<=n; i++){
       int ans = add( mul(prev2, k-1), mul(prev1, k-1));
       prev2 = prev1;
       prev1 = ans;
    }
    
    return prev1;
}

int numberOfWays4(int n, int k) {
    return solveSpaceOP(n,k);
}
