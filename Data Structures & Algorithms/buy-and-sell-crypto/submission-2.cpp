class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_Buy = prices[0];
        int maxPr = 0;
        for(int i = 0;i<prices.size();i++){
            min_Buy = min(min_Buy,prices[i]);
            maxPr = max(maxPr,prices[i]-min_Buy);
        }
        return maxPr;
    }
};
