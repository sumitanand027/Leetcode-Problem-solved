class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        
        for( auto a : n ) {
            int t = a - '0';
            ans = max( ans , t );
        }
        return ans;
    }
};