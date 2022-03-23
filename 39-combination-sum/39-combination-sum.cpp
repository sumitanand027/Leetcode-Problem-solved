class Solution {
public:
    void helper( vector<int>&cad, int i , vector<int> arr, vector<vector<int> > & ans, int t ) {
        if( t < 0 ) return;
        if( t == 0 ) {
            ans.push_back( arr );
            return;
        }
        if( i == cad.size() ) return;
        
        
        arr.push_back( cad[i] );
        helper( cad, i, arr, ans, t - cad[i] );
        arr.pop_back();
        helper( cad, i+1, arr, ans, t );
        
    }
    vector<vector<int>> combinationSum(vector<int>& cad, int t ) {
        vector< vector<int> > ans;
        vector<int> arr;
        helper( cad, 0, arr,ans, t);
        return ans;
    }
};
