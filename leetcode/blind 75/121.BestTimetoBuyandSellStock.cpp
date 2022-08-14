class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minSoFar = prices[0];
        int maxProfit = 0;
        for(int i =1;i<n;i++){
            if(prices[i] < minSoFar){
                minSoFar = prices[i];
            }
            int profit = prices[i] - minSoFar;
            if(profit > maxProfit) maxProfit = profit;
        }
        return maxProfit;
    }
};