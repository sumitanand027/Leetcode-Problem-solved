class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        sort( p.begin() , p.end() );
        int n = p.size();
        int l = 0 , h = n - 1;
        
        int ans = 0;
        while( l <= h ) {
            if( p[l] + p[h] > limit ) {
                ans++;
                h--;
            } else {
                ans++;
                l++;
                h--;
            }
        }
        return ans;
    }
};