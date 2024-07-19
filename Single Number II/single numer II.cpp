class Solution {
public:

    void updateSum(vector<int> &sumArr, int x){
        //extract all bits of x
        for(int i = 0 ; i < 32 ; i++){
            int ith_bit = x & (1<<i);
            if (ith_bit) sumArr[i] ++;
            }
    }

    int getDecFromBitsArray(vector<int> sumArr){
        int ans= 0 ;
        long long int power = 1;
        for(int i = 0 ; i < 32 ; i++){
            ans += power * sumArr[i];
            power *= 2;
        }
        return ans;
    }

    int singleNumber(vector<int>& nums) {

        //first initialise the atrray of sum with all 0's.
        vector<int> sumArr(32,0);

        //pick elements from the array and keep adding the elements in binary in the sum array.
        for(int x: nums) updateSum(sumArr, x);

        for(int i = 0 ; i < 32 ; i++){
            sumArr[i] = sumArr[i] % 3;
        }

        int ans =  getDecFromBitsArray(sumArr);
        return ans;
    }
};
