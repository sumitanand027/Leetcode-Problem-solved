class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        for( auto &t : time )
        {
            t = t % 60;
        }
        
        unordered_map<int,int> m;
        
        int ans = 0;
        int zero = 0;
        
        for( auto &t : time )
        {
            int rem = 60 - t;
            if( t == 0 ) {
                ans += zero;
                zero++;
            }
            else if( m.find( rem ) != m.end() ) {
                ans += m [ rem ];
            }
            m[t]++;
        }
        
        return ans;
    }
};