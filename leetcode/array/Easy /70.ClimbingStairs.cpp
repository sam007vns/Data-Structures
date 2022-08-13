typedef vector<int> vi;
class Solution {
public:
    int f(int n, vi& dp){
    if(n < 0) return 0;
    if(n <= 1) return 1;
    if(n == 2) return 2;
        if(dp[n] != 0) return dp[n];
        return dp[n] = f(n-1, dp) + f(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n, 0);
        return f(n-1, dp) + f(n-2, dp);
    }
    int climbStairs(int n) {
        if(n<=2) return n;
        int prev = 2;
        int secondPrev = 1;
        int curr;
        for(int i=3;i<=n;i++){
            curr = prev + secondPrev;
            secondPrev = prev;
            prev = curr;
        }
        return curr;
    }
};