class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        while(target != startValue){
            if(target<startValue || target%2==1)
                target+=1;
            else
                target/=2;
            ans++;
        }
        return ans; 
    }
};