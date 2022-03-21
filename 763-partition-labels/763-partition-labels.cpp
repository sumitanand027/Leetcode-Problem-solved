class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> m ( 26 , 0 );
        
        for( int i = 0 ; i < s.size() ; i++ )
        {
            m[ s[i] - 'a'] = i;
        }
        
        vector<int> ans;
        int maxInd = -1 , lastInd = 0;
        
        for( int i = 0 ; i < s.size() ; i++ )
        {
            maxInd = max( maxInd , m[ s[i] - 'a'] );
            if( maxInd == i ) {
                ans.push_back( maxInd - lastInd + 1 );
                lastInd = i + 1;
            }
        }
        return ans;
    }
};