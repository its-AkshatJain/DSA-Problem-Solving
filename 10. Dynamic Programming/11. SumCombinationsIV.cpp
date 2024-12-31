#include <bits/stdc++.h> 

// Recursion
int solve(vector<int> &num, int tar){
    // Base case
    if(tar < 0){
        return 0;
    }
    if(tar == 0){
        return 1;
    }

    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans += solve(num, tar-num[i]);
    }
    return ans;
}

int findWays(vector<int> &num, int tar)
{
    return solve(num, tar);
}

// Recursion + Memoization
int solveMem(vector<int> &num, int tar, vector<int> &dp){
    // Base case
    if(tar < 0){
        return 0;
    }
    if(tar == 0){
        return 1;
    }

    // Step 3
    if(dp[tar] != -1){
        return dp[tar];
    }

    int ans = 0;
    for(int i=0; i<num.size(); i++){
        ans += solveMem(num, tar-num[i], dp);
    }
    // Step 2
    dp[tar] = ans;
    return dp[tar];
}

int findWays2(vector<int> &num, int tar)
{
    // Step 1
    vector<int> dp(tar+1, -1);
    return solveMem(num, tar, dp);
}

// Tabulation
int solveTab(vector<int> &num, int tar){

    vector<int> dp(tar + 1, 0); 

    // Base case
    dp[0] = 1;

    // For traversing from target 1 to tar
    for(int i=1; i<=tar; i++){
        // For traversing on num vector
        for(int j=0; j<num.size(); j++){
            if(i-num[j] >= 0){
                dp[i] += dp[i - num[j]]; 
            }
        }
    }
    return dp[tar];
}

int findWays3(vector<int> &num, int tar)
{
    return solveTab(num, tar);
}