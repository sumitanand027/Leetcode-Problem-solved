class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0, ten = 0, tw = 0;
        
        for( auto b : bills )
        {
            if( b == 5 ) {
                f++;
            } else if( b == 10 ) {
                if( f > 0 ) {
                    f--;
                } else {
                    return false;
                }
                ten++;
            } else {
                if( ten > 0 ) {
                    ten--;
                    if( f > 0 ) {
                        f--;
                    } else {
                        return false;
                    }
                }
                else if( f > 2 ) {
                    f--;
                    f--;
                    f--;
                } else {
                    return false;
                }
                tw++;
            }
        }
        return true;
    }
};