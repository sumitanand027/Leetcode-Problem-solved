class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inte) {
        
        sort( inte.begin() , inte.end() );
        vector< vector<int> > ans;
        
        for( auto &i : inte ) {
            if( ans.size() > 0 && ans[ ans.size() - 1 ][1] >= i[0] ) {
                ans[ ans.size() - 1 ][1] = max( i[1] , ans[ ans.size() - 1 ][1]  );
            } else {
                ans.push_back( {i[0] , i[1] });
            }
        }
        return ans;
    }
};