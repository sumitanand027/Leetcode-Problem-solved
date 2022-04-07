class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
         priority_queue<int> q;
        
        for( auto x : stones ) {
            q.push( x );
        }        
        
        while( !q.empty() )
        {
            int y = q.top();
            q.pop();
            int x = -1;
            if( !q.empty() )
            {
                x = q.top();
                q.pop();
            }
            if( x == -1 ) return y;
            if( x != y ) 
            {
                q.push( y - x );
            }
        }
        return 0;
    }
};