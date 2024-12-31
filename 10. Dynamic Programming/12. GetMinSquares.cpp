// Recursion
int solve(int n){
    // Base case
    if(n == 0){
        return 0;
    }
    
    int ans = n;
    for(int i=1; i*i<=n; i++){
        int temp = i*i;
        ans = min(ans, 1+ solve(n - temp));
    }
    return ans;
    
}

int MinSquares1(int n) {
    return solve(n);
}

// Recusion + Memoization
int solveMem(int n, vector<int> &dp){
    // Base case
    if(n == 0){
        return 0;
    }
    
    // step 3
    if(dp[n] != -1){
        return dp[n];
    }
    
    int ans = n;
    for(int i=1; i*i<=n; i++){
        int temp = i*i;
        ans = min(ans, 1 + solveMem(n - temp, dp));
    }
    
    // step 2
    dp[n] = ans;
    return dp[n];
    
}

int MinSquares2(int n) {
    // Step 1
    vector<int> dp(n+1, -1);
    return solveMem(n, dp);
}

// Tabulation
int solveTab(int n){
    // Step 1
    vector<int> dp(n+1, INT_MAX);
    
    // Step 2
    dp[0] = 0;
    
    // step 3
    for(int i=1; i<=n; i++){
        
        for(int j=1; j*j<=n; j++){
            
            int temp = j*j;
            
            if(i-temp>=0){
                dp[i] = min(dp[i], 1 + dp[i - temp]);   
            }
        }
    }
    
    return dp[n];
}

int MinSquares3(int n) {
    return solveTab(n);
}