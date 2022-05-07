class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mini( n );
        
        mini[0] = nums[0];
        for( int i = 1 ; i < n ; i++ ) {
            mini[i] = min( nums[i] , mini[i-1] );
        }
        
        stack<int> sk;
        
        for( int i = n - 1  ; i >= 0 ; i-- ) 
        {
            if( nums[i] > mini[i] ) {
                while( !sk.empty() && sk.top() <= mini[i] ) {
                    sk.pop();
                }
                if( !sk.empty() && sk.top() < nums[i] )
                    return true;
                sk.push( nums[i] );
            }    
        }
        return false;
    }
};