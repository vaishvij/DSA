class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int i, min=0, max=0;
        min = prices[0];
        if(prices.size() <= 1) 
        {
            return 0; 
        }
        for(i=0; i<prices.size(); i++)
        {
            if(min > prices[i])
            {
                min = prices[i];
            }
            if((prices[i]-min) > max)
            {
                max = prices[i]-min;
            }
        }
        return max;
    }
};