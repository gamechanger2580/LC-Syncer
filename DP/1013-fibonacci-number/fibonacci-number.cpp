class Solution {
public:

    // space opti
    int fib4(int n)
    {
        if (n == 0)
            return 0;
            
        int prev1 = 1;
        int prev2 = 0;
        
        // int curr;
        for(int i = 2;i <= n;i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    // bottum up approach
    int fib3(int n,vector<int> &dp)
    {
        dp[0] = 0;
        dp[1] = 1;

        if(dp[n] != -1)
            return dp[n];

        int ans;        
        for(int i = 2; i < dp.size(); i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
            ans = dp[i];
        }

        return ans;            
    }

    // top down approach 
    int fib2(int n, vector<int> &dp)
    {
        if(n <= 1)
        {
            return n;
        }

        if(dp[n] != -1)
        {
            return dp[n];
        }

        dp[n] = fib2(n-1,dp) + fib2(n-2,dp);

        return dp[n];
    }

    // normal reucursion
    int fib1(int n)
    {
        if(n == 0 || n == 1)
        {
            return n;
        }

        int ans = fib1(n-1) + fib(n-2);
        
        return ans;
    }

    int fib(int n) {
        // int ans = fib1(n);
        // int ans = fib2(n,dp);
        // int ans = fib3(n,dp);
        // vector<int> dp(n+1,-1);

        int ans = fib4(n);
        return ans;
    }
};