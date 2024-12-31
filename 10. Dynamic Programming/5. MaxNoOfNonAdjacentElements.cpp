#include <bits/stdc++.h> 

// Normal Recursion
int solve1(vector<int> &nums, int n){
    // Base case
    if(n < 0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    int incl = solve(nums, n-2) + nums[n];
    int excl = solve(nums, n-1);

    return max(incl, excl);
}

int maximumNonAdjacentSum1(vector<int> &nums){
    int n = nums.size();
    int ans = solve1(nums, n-1);
    return ans;
}

// Recursion + Memoization
int solve2(vector<int> &nums, int n, vector<int> &dp){
    // Base case
    if(n < 0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }

    // step 3
    if(dp[n] != -1){
        return dp[n];
    }

    int incl = solve2(nums, n-2, dp) + nums[n];
    int excl = solve2(nums, n-1, dp);

    // step 2
    dp[n] = max(incl, excl);
    return dp[n];
}

int maximumNonAdjacentSum2(vector<int> &nums){
    int n = nums.size();

    // Step 1
    vector<int> dp(n, -1);

    int ans = solve2(nums, n-1, dp);
    return ans;
}

// Bottom up Tabulation
int solve3(vector<int> &nums){
    int n = nums.size();
    // Step 1
    vector<int> dp(n, 0);

    // Step 2
    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1];
        dp[i] = max(incl, excl);
    }

    return dp[n-1];
}

int maximumNonAdjacentSum3(vector<int> &nums){
    int ans = solve3(nums);
    return ans;
}

// Space optimisation
int solve4(vector<int> &nums){
    int n = nums.size();
    // Base cases
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1; i<n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int maximumNonAdjacentSum4(vector<int> &nums){
    int ans = solve4(nums);
    return ans;
}