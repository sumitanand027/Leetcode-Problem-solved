class Solution {
public:
    
    int countBit ( int x ) {
        int cnt = 0;
        
        while( x ) {
            if( ( x & 1 ) == 1 ) {
                cnt++;
            }
            x = x >> 1;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans;
        for( int i = 0 ; i <= n ; i++ ) {
            ans.push_back( countBit(i) );
        }
        return ans;
    }
};