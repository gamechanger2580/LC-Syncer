class Solution {
public:
    int solveRecur(vector<int> &nums,int target)
    {
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        int ans = 0;
        for(int i = 0; i < nums.size();i++)
        {
            ans += solveRecur(nums,target-nums[i]);
        }

        return ans;
    }

    int solveMemo(vector<int>& nums, int target, vector<unsigned long long int>& dp)
    {
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans += solveMemo(nums, target - nums[i] , dp);
        }
        dp[target] = ans;
        return dp[target];
    }

    int solveTab(vector<int>& nums, int target)
    {
        vector<unsigned long long int> dp(target+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                if(i - nums[j] >= 0)
                    dp[i] += dp[i-nums[j]];
            }
        }

        return dp[target];
    }

    int combinationSum4(vector<int>& nums, int target) {

        // by simple recur
        // return solveRecur(nums,target);

        // // by memo
        // vector<unsigned long long int> dp(target+1,-1);
        // return solveMemo(nums,target,dp);

        //by tab
        return solveTab(nums,target);

    }
};