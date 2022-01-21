class StockSpanner {
public:
    stack< pair<int,int> > sk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while( !sk.empty() && sk.top().first <= price ) {
            res += sk.top().second;
            sk.pop();
        }
        sk.push( { price, res } );
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
