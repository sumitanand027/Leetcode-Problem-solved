class Solution {
public:
    
    int helper( vector< vector<int>> &m , int mid , int n )
    {
        int count = 0;
        
        int row = n - 1, col = 0;
        
        while( row >= 0 && col < n )
        {
            if( m[row][col] > mid ) {
                row--;
            } else {
                count += row + 1;
                col++;
            }
        }
        return count;
    }
    
    
    int kthSmallest(vector<vector<int>>& m, int k) {
        int n = m.size();
        
        int lo = m[0][0] , hi = m[n-1][n-1];
        
        int ans = -1;
        
        while( lo <= hi )
        {
            int mid = ( lo + hi ) / 2;
            int count = helper( m , mid , n );
            
            if( count < k ) {
                lo = mid + 1;
            } else if( count == k ) {
                ans = mid;
                hi = mid - 1;
            } else {
                ans = mid;
                hi = mid  - 1;
            }
        }
        return ans;
    }
};