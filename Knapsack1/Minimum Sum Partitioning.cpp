class Solution {
public:
int subsetsum(vector<int> &nums, int sum, vector<vector<bool>> &t){
        for(int i = 0; i<=nums.size(); i++){
            for(int j = 0; j<=sum; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        int ans = sum;
        int n = nums.size();
        for(int i = 0; i<=sum/2; i++){
            if(t[n][i]==true){
                ans = i;
            }
        }
        return sum+ans*2;
    }
    int minimumDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> t(nums.size()+1 , vector<bool> (sum+1, false) );
        for(int i = 0; i<=nums.size(); i++){
            t[i][0] = true;
        }
    
    }
};


//  incomplete code