class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int p = n - k;
        
        int ans = 0;
        int sum = 0;
        int totSum = 0;
        
        for( int i = 0 ; i < n ; i++ ) 
        {
            totSum += cardPoints[i];
        }
        
        for( int i = 0 ; i < p ; i++ )
        {
            sum += cardPoints[i];
        }
        
        ans = max( ans , totSum -sum );
        int l = 0;
        for( int r = p ; r < n ; r++ )
        {
            sum -= cardPoints[l++];
            sum += cardPoints[r];
            ans = max( ans , totSum -sum );
        }
        return ans;
    }
};
