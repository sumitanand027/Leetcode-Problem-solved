class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans; 
        int m = strs.size();
        int n = INT_MAX;
        
        for( auto s : strs ) {
            n = min( n, (int) s.size() );
        }
        
        for( int j = 0; j < n; j++ ) {
            char c = strs[0][j];
            int same = 1;
            for( int i = 0; i < m; i++ ) {
                if( strs[i][j] != c ) {
                    same = 0;
                    break;
                }
            }
            if( same ) {
                ans.push_back( c );
            } else {
                break;
            }
        }
        return ans;
    }
};