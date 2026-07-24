class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_Buy = prices[0];
        int max_price = 0;
        for(int i = 0;i<prices.size();i++){
            min_Buy = min(min_Buy,prices[i]);
            max_price = max(max_price,prices[i]-min_Buy);
        }
        return max_price;
    }
};
