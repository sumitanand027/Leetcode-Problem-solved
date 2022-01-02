class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestSeq = 0;
        
        unordered_set<int> s;
        for( auto num : nums ) {
            s.insert( num );
        }
        
        for( int num : nums )
        {
            if( !s.count( num - 1) )
            {
                int curNum = num;
                int curSeq = 1;
                
                while( s.count( curNum + 1 ) ) {
                    curNum += 1;
                    curSeq += 1;
                }
                
                longestSeq = max( longestSeq , curSeq );
            }
        }
        return longestSeq;
    }
};