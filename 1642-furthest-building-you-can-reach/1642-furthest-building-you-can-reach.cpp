class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue <int> q;
        int i;
        
        for( i = 0 ; i < h.size() - 1 ; i++ )
        {
            int dif = h[i+1] - h[i];
            
            if( dif <= 0 )
                continue;
            
            b -= dif;
            q.push( dif );
            
            if( b < 0 ) {
                b += q.top();
                q.pop();
                l--;
            }
            if( l < 0 )
                break;
        }
        return i;
    }
};