// FindMaxConsecutiveOnes
int findMaxConsecutiveOnes(vector<int>& nums) {
    int cnt =0;
    int maxi = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == 1){
            cnt++;
        }else if(nums[i] == 0){
            maxi = max(maxi,cnt);
            cnt = 0;
        }
    }
    maxi = max(maxi,cnt);
    return maxi;
}

// FindMaxConsecutiveOnes II
int longestOnes(vector<int>& nums, int k) {
// To solve this count the numbers of consecutive zeros instead of one.
int l = 0, r = 0;
int maxi = 0;
int zeros = 0;
int n = nums.size();

while(r<n){
    // Count the zeros
    if(nums[r] == 0){
        zeros++;
    }
    // If count of zeros > k increment l
    if(zeros>k){
        while(nums[l] == 0){
            zeros--;
        }
        l++;
    }

    // Calculate max window size
    if(zeros<=k){
        int len = r-l+1;
        maxi = max(maxi, len);
    }
    r++;
}
return maxi;
}

int longestOnes2(vector<int>& nums, int k) {
// To solve this count the numbers of consecutive zeros instead of one.
int l = 0, r = 0;
int maxi = 0;
int zeros = 0;
int n = nums.size();

while(r<n){
    // Count the zeros
    if(nums[r] == 0){
        zeros++;
    }
    // If count of zeros > k increment l
    if(zeros>k){
        if(nums[l] == 0){
            zeros--;
        }
        l++;
    }

    // Calculate max window size
    if(zeros<=k){
        int len = r-l+1;
        maxi = max(maxi, len);
    }
    r++;
}
return maxi;
}