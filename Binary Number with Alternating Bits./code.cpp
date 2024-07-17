Code
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int org = n;
        vector<int> arr;
        while(org){
            arr.push_back(org & 1);
            org >>= 1;
        }
        bool flag = true;
        for(int i = 1 ; i < arr.size() ; i++){
            if((arr[i] ^ arr[i-1]) == 0) flag = false;
        }
        return flag;
        
    }
};

