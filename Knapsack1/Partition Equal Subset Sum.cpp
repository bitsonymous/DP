class Solution {
public:
    bool subsetsum(vector<int> &nums, int sum, int n, vector<vector<bool>> &t){
        // if(n==0 || sum == 0){
        //     if(sum == 0) return true;
        //     else return false;
        // }

        for(int i = 1; i<n+1; i++){
            for(int j = 1; j<sum+1; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];

        // if(nums[n-1]<=sum){
        //     return subsetsum(nums, sum - nums[n-1], n-1) || subsetsum(nums, sum, n-1);
        // }
        // else{
        //     return subsetsum(nums, sum, n-1);
        // }
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        vector<vector<bool>> t(n+1 , vector<bool> (sum+1, false));
        for(int i = 0; i<n+1; i++ ){
            t[i][0] = true;
        }
        if(sum%2!=0) return false;
        return subsetsum(nums, sum/2, n, t);
    }
};