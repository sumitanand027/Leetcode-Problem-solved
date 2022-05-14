class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair< int , pair<int, int>> , vector<pair< int , pair<int, int>>> , greater<pair< int , pair<int, int>>> > p;
        
        for( auto pp : points )
        {
            p.push( make_pair( ( pp[0] * pp[0] + pp[1] * pp[1] ) , make_pair( pp[0] , pp[1] ) ) );
        }
        
        vector<vector<int>> ans;
        
        while( k-- )
        {
            vector<int> t;
            t.push_back( p.top().second.first );
            t.push_back( p.top().second.second );
            ans.push_back( t );
            p.pop();
        }
        return ans;
    }
};