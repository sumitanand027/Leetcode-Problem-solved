class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, h = arr.size();
        
        // l , h , m are number of missing elements
        
        while( l < h )
        {
            int m = ( l + h ) / 2;
            
            if( arr[m] - m - 1 < k ) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        
        return l + k;
    
    }
    
};