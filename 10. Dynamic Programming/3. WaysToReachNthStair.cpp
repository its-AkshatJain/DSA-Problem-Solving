#include <bits/stdc++.h> 
#define MOD 1000000007

// Recursion
int solve(int nStairs, int i){
    // Base Case
    if(i == nStairs){
        return 1;
    }
    if(i > nStairs){
        return 0;
    }

    return solve(nStairs, i+1) + solve(nStairs, i+2) % MOD;
}

int countDistinctWays(int nStairs) {
    int ans = solve(nStairs, 0);
    return ans;
}

// Recusion + memoization
int solve2(int nStairs, int i, vector<int> &dp){
    // Base Case
    if(i == nStairs){
        return 1;
    }
    if(i > nStairs){
        return 0;
    }

    // Step 3
    if(dp[i] != -1){
        return dp[i];
    }

    // Step 2
    dp[i] = (solve2(nStairs, i+1, dp) + solve2(nStairs, i+2, dp)) % MOD;
    return dp[i];
}

int countDistinctWays2(int nStairs) {
    // step 1
    vector<int> dp(nStairs+1, -1);

    int ans = solve2(nStairs, 0, dp);
    return ans;
}

// Bottom up- Tabulation
int solve3(int nStairs){
    // step 1
    vector<int> dp(nStairs+1, -1);

    // Base Case analyze
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<= nStairs; i++){
        dp[i] = (dp[i-1] + dp[i-2]) %  MOD;
    }
    
    return dp[nStairs];
}

int countDistinctWays(int nStairs) {
    
    int ans = solve3(nStairs);
    return ans;
}