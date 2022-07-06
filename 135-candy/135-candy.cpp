class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        vector<int> candy ( n , 1 );
        
        for( int i = 1 ; i < n ; i++ )
        {
            if( ratings[i-1] < ratings[i] ) {
                candy[i] = candy[i-1] + 1;
            }
        }
        
        for( int i = n - 2; i >= 0 ; i-- ) 
        {
            if( ratings[i+1] < ratings[i] ) {
                candy[i] = max(candy[i+1] + 1 , candy[i]);
            }
        }
        
        int ans = 0;
        for( auto a : candy ) {
            
            cout << a << " ";
            ans += a;
        }
        return ans;
    }
    
};