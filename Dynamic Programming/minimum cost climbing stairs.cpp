//memoization method

class Solution {
private:
    int solve(vector<int> &cost, int n, vector<int> &dp){
        if(n == 0 || n == 1) return cost[n];

        if(dp[n] != -1) return dp[n];

        dp[n] = cost[n] + min(solve(cost, n-1,dp),solve(cost, n-2,dp));
        return dp[n];

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1, -1);
        int ans = min(solve(cost, n-1,dp),solve(cost, n-2,dp));
        return ans;
    }
};


//second method:- tabulation method
class Solution {
private:
    int solve(vector<int> &cost, int n){
        //create a dp
        vector<int>dp(n+1);
        //add the base case value into dp
        dp[0] = cost[0];
        dp[1] = cost[1];

        //for rest of them using loop to iterate

        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
       return min(dp[n-1],dp[n-2]);
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost,n);
    }
};

// third method:- optimized tabulation method space complexity O(1)

class Solution {
private:
    int solve(vector<int> &cost, int n){

        int firstOne = cost[0];
        int secOne = cost[1];

        int ans = 0;

        for(int i = 2; i < n; i++){
            ans = cost[i] + min(firstOne,secOne);
            firstOne = secOne;
            secOne = ans;
        }
       return min(firstOne,secOne);
    }
    
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost,n);
    }
};