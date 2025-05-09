/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution{
public:
    bool containsDuplicates(vector<int> nums){
        unordered_set<int> seen;
        for(auto& iter:nums){
            if(seen.find(iter) != seen.end()){
                return true;
            }
            seen.insert(iter);
        }
        return false;
    }

    // time complexity: O(n) as we traverse the array once
    // space complexity: O(n) as we use a hash set to store the elements

    /*Optimal Solution*/

    bool containsDuplicatesOptimal(vector<int> nums){
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]==nums[i-1]){
              return true;
            }
        }
        return false;
    }
    // time complexity: O(nlogn) as we sort the array
    // space complexity: O(1) as we do not use any extra space
};