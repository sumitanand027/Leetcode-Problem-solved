struct customCompare {
    
    bool operator() ( const pair<int,int> &a , const pair<int,int> &b ) {
        if( a.first > b.first )
            return 1;
        else if( a.first == b.first ) {
            if( a.second > b.second )
                return 1;
        }
        return 0;
    }
};


class Solution {
public:
    
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> ans;
        
        priority_queue<pair<int,int>, vector<pair<int,int>> , customCompare  > p;
        
        for( auto a : arr ) {
            p.push( { abs( x - a ) , a } );
        }
        
        cout << p.top().first << " " << p.top().second << endl;
        
        while( k-- ) {
            ans.push_back( p.top().second );
            p.pop();
        }
        
        sort( ans.begin() , ans.end() );
        return ans;
    }
};







