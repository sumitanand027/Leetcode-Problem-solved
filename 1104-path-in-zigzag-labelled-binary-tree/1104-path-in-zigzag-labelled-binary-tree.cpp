class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int llv = 1;
        int curllv = 0;
        
        while( curllv < label )
        {
            curllv += llv;
            llv *= 2;
        }
        
        llv /= 2;
        
        int st = llv;
        int end = curllv;
        
        vector<int> ans;
        
        while( label != 1 )
        {
            int cmp = end + st - label;
            ans.push_back( label );
            label = cmp / 2;
            end -= st;
            st /= 2;
        }
        
        ans.push_back( 1 );
        reverse ( ans.begin() , ans.end() );
        
        return ans;
    }
    
};



