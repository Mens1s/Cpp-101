#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        for(int idx = 0; idx < nums.size() - 1 ; idx++){
            if(nums[idx] == nums[idx+1]){
                nums.erase(nums.begin()+idx);
                idx--;
            }
        }
    }

    int main(){
        vector<int> nums = {1,1,1,2,3,4,5,5,6,7,8,9,9};
        removeDuplicates(nums);
        for(auto a : nums)
            cout << a; 
        return 0;
    }