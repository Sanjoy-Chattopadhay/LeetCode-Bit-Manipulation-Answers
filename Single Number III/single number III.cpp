class Solution {
public:
    int getBit(int n, int pos) {
    int mask = 1 << pos;
    if (n & mask) return 1;
    else return 0;
}

int getFirstOneInLSB(int n) {
    //n = 1010
    int pos = 0;
    while (n) {
        if (n & 1) return pos;
        else {
            pos++;
            n >>= 1;
        }
    }
    return pos;
}

vector < int > singleNumber(vector < int > & nums) {
    int n = nums.size();
    int exor = 0;
    for (int i = 0; i < n; i++) {
        exor ^= nums[i];
    }
    vector < int > set1, set2, ans;
    int pos = getFirstOneInLSB(exor);
    cout<<pos<<endl;

    for (int i = 0; i < n; i++) {
        if (getBit(nums[i], pos)) set1.push_back(nums[i]);
        else set2.push_back(nums[i]);
    }
    int ele1 = 0;
    int ele2 = 0;

    for (int i = 0; i < set1.size(); i++) {
        ele1 ^= set1[i];
    }

    for (int i = 0; i < set2.size(); i++) {
        ele2 ^= set2[i];
    }

    ans.push_back(ele1);
    ans.push_back(ele2);
    cout << ele1 << "  " << ele2;
    return ans;



}

};
