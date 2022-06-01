class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        
        for( auto &num : nums )
        {
            s.insert( num );
        }
        
        int ans = 0;
        for( auto &num : nums )
        {
            if( !s.count( num - 1 ) )
            {
                int curNum = num;
                int seq = 1;
                
                while( s.count( curNum + 1 ) ) {
                    curNum++;
                    seq++;
                }
                ans = max( ans , seq );
            }
        }
        return ans;
    }
};