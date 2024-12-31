#include <bits/stdc++.h> 

// Recursion
int solve(vector<int> weight, vector<int> value, int index, int capacity){
	// Base case
	// If only one item to steal then compare its weight with knapsack
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}else{
			return 0;
		}
	}

	int include = 0;
	if(weight[index] <= capacity){
		include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
	}

	int exclude = 0 + solve(weight, value, index - 1, capacity);

	int ans = max(include, exclude);
	return ans;
} 

int knapsack1(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	solve(weight, value, n-1, maxWeight);
}

// Recursion + Memoization
int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp){
	// Base case
	// If only one item to steal then compare its weight with knapsack
	if(index == 0){
		if(weight[0] <= capacity){
			return value[0];
		}else{
			return 0;
		}
	}

	// Step 3
	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}

	int include = 0;
	if(weight[index] <= capacity){
		include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
	}

	int exclude = 0 + solveMem(weight, value, index - 1, capacity, dp);

	// Step 2
	dp[index][capacity] = max(include, exclude);
	return dp[index][capacity];
} 

int knapsack2(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// 2D dp array row, column
	// Step1
	vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

	return solveMem(weight, value, n-1, maxWeight, dp);
}

// Bottom-up Tabulation
int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity){
	// Step1
	vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
	
	// Base case analyze
	for(int w=weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
			dp[0][w] = value[0];
		}else{
			dp[0][w] = 0;
		}
	}

	// Step 3
	for(int index=1; index<n; index++){
		for(int w=0; w<=capacity; w++){
			int include = 0;
			if(weight[index] <= w){
				include = value[index] + dp[index-1][w- weight[index]];
			}

			int exclude = 0 + dp[index-1][w];

			// Step 2
			dp[index][w] = max(include, exclude);
		}
	}
	
	return dp[n-1][capacity];
} 

int knapsack3(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveTab(weight, value, n, maxWeight);
}

// Space optimisation
int solveSpaceOP(vector<int> &weight, vector<int> &value, int n, int capacity){
	// Step1
	vector<int> prev(capacity + 1, 0);
	vector<int> curr(capacity + 1, 0);
	
	// Base case analyze
	for(int w=weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
			prev[w] = value[0];
		}else{
			prev[w] = 0;
		}
	}

	// Step 3
	for(int index=1; index<n; index++){
		for(int w=0; w<=capacity; w++){
			int include = 0;
			if(weight[index] <= w){
				include = value[index] + prev[w- weight[index]];
			}

			int exclude = 0 + prev[w];

			// Step 2
			curr[w] = max(include, exclude);
		}
		prev = curr;
	}
	
	return prev[capacity];
} 

int knapsack4(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveSpaceOP(weight, value, n, maxWeight);
}

// Using single array
int solveSpace(vector<int> &weight, vector<int> &value, int n, int capacity){
	// Step1
	vector<int> curr(capacity + 1, 0);
	
	// Base case analyze
	for(int w=weight[0]; w<=capacity; w++){
		if(weight[0] <= capacity){
			curr[w] = value[0];
		}else{
			curr[w] = 0;
		}
	}

	// Step 3
	for(int index=1; index<n; index++){
		for(int w=capacity; w>=0; w--){
			int include = 0;
			if(weight[index] <= w){
				include = value[index] + curr[w- weight[index]];
			}

			int exclude = 0 + curr[w];

			// Step 2
			curr[w] = max(include, exclude);
		}
	}
	
	return curr[capacity];
} 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	return solveSpace(weight, value, n, maxWeight);
}