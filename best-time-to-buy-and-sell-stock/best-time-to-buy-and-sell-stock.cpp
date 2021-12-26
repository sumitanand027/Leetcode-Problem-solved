class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_max = -1;
        int ans = 0;
        for( int i = prices.size() - 1 ; i >= 0 ; i-- ) 
        {
            cur_max = max( cur_max , prices[i] );
            ans = max( ans , cur_max - prices[i] );
        }
        return ans;
    }
};