class Solution {
public:
    int divide(int dividend, int divisor) {
        
        //Handling boundary cases;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        if(dividend==INT_MIN && divisor==1) return INT_MIN;
        
        //Converting divisors and dividend to their positive values;
        long int d = abs(dividend), v = abs(divisor);
        
        //Result Variables;
        int ans=0;
        // long way of performing division;
        while(v<=d) {
            long int mul=v, tmp=1;
            while(mul<=d-mul) {
                mul+=mul;
                tmp+=tmp;
            }
            ans+=tmp;
            d-=mul;
        }
        if((dividend<0&&divisor>0) || (dividend>0&&divisor<0)) return -ans;
            
        return ans;  
    }
};