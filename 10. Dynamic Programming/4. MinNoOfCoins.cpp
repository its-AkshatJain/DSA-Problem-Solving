#include <bits/stdc++.h> 

// Recursion
int solveRec(vector<int> &num, int x){
    // Base case
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;
    // Traverse coins array
    for(int i=0; i<num.size(); i++){
        int ans = solveRec(num, x - num[i]);
        if(ans != INT_MAX){
            mini = min(mini, 1 + ans);
            // we are adding 1 in ans to add current coin to the count
        }
    }
    return mini;
}

int minimumElements1(vector<int> &num, int x)
{
    int ans = solveRec(num, x);
    if(ans == INT_MAX){
        return -1;
    }else{
        return ans;
    }
}

// Recursion - Memoization
int solveMem(vector<int> &num, int x, vector<int> dp){
    // Base case
    if(x == 0){
        return 0;
    }
    if(x < 0){
        return INT_MAX;
    }

    // Step 3
    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++){
        int ans = solveMem(num, x - num[i], dp);
        if(ans != INT_MAX){
            mini = min(mini, 1 + ans);
            // we are adding 1 in ans to add current coin to the count
        }
    }
    // Step 2
    dp[x] = mini;
    return dp[x];
}

int minimumElements2(vector<int> &num, int x)
{
    // Step 1
    vector<int> dp(x+1, -1);

    int ans = solveMem(num, x, dp);
    if(ans == INT_MAX){
        return -1;
    }else{
        return ans;
    }
}

// Bottom up Tabulation
int solveTab(vector<int> &num, int x){
    // Step 1
    vector<int> dp(x+1, INT_MAX);

    // Step 2
    dp[0] = 0;

    // Step 3
    for(int i=0; i<=x; i++){
        // trying to solve for each figure from 1 to x
        for(int j=0; j<num.size(); j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            } 
        }
    }

    if(dp[x] == INT_MAX){
        return -1;
    }

    return dp[x];
}

int minimumElements3(vector<int> &num, int x)
{
    int ans = solveTab(num, x);
    return ans;
}