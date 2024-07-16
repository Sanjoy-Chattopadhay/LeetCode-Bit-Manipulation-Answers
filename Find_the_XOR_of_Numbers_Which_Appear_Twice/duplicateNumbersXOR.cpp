#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
       int count = 0 ;
       int exor = 0 ;
       int countArr[100] = {0};
       for(int i = 0 ; i < nums.size() ; i++){
        if(++countArr[nums[i]] == 2) exor = exor ^ nums[i];
       } 

       return exor;
    }
    
    int main(){
    	
    	vector<int>& nums = {1,2,2,1};
    	cout<<duplicateNumbersXOR(nums);
	}
};
