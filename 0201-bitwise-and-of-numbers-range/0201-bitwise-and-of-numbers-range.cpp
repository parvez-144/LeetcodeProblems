class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int makeshift=0;
        while(left<right){
            left>>=1;
            right>>=1;
            makeshift++;
        }
        return left<<makeshift;

    }
};