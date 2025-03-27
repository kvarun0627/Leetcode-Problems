class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int chosen_stock=prices[0];
        int profit=0;
        for(int stock:prices)
        {
            if(stock<chosen_stock)
            {
                chosen_stock=stock;
            }
            else
            {
                profit=max(profit,stock-chosen_stock);
            }
        }
        return profit;
    }
};