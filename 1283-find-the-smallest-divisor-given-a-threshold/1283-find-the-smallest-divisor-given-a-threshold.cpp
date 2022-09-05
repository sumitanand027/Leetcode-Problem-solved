class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int l = 1, h = 1e7;
        
        while( l < h ) 
        {
            int ans = 0;
            int m = ( l + h )/ 2;
            
            for( int i = 0 ; i < nums.size(); i++ ) 
            {
                ans += ceil( ( nums[i] + m - 1) / m );
            }
            
            
            if( ans > threshold ) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        
        return l;
    }
};