#include<vector>
using namespace std;
typedef vector<int> vi;
class Solution {
public:
    // recursive t:  O(n^2) s: O(n)
    int f(vi& cost, int n){
        if (n < 0) return 0;
        if(n == 1 || n == 0) return cost[n];
        return cost[n] + min(f(cost, n-1), f(cost, n-2));
    }
    // top down memoization O(n) space : O(n) + O(n)
    int f_memo(vi& cost, int n, vi& dp){
        if (n < 0) return 0;
        if(n == 1 || n == 0) return cost[n];
        if(dp[n] != 0) return dp[n];
        return dp[n] = cost[n] + min(f_memo(cost, n-1,dp), f_memo(cost, n-2,dp));
    }
    // bottom up t: O(n), s: O(n)
    int f_bottom(vi& cost, int n, vi& dp){
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
    // space optimization s: O(1), t: O(n)
    int f_space(vi& cost, int n){
        int first = cost[0];
        int second = cost[1];
        for(int i = 2;i<n;i++){
            int curr = cost[i] + min(first, second);
            first = second;
            second = curr;
        }
        return min(first, second);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vi dp(n, 0);
        // return min(f_memo(cost, n-1, dp), f_memo(cost, n-2, dp));
        // return f_bottom(cost, n, dp);
        return f_space(cost, n);
    }
};