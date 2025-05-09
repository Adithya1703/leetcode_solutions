/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool containsDuplicates(vector<int>& nums, int k){
        unordered_map<int, int> indexMap;
        for(int i=0;i<nums.size();i++){
            if(indexMap.count(nums[i]) && i-indexMap[nums[i]]<=k){
              return true;
            }
            indexMap[nums[i]] = i;
        }
        return true;
    }
    // time complexity: O(n) as we traverse the array once
    // space complexity: O(n) as we use a hash map to store the elements

    /*Optimal Solution*/
    // The optimal solution uses a sliding window approach to keep track of the last k elements seen.
    // This reduces the space complexity to O(k) instead of O(n).
    bool containsDuplicatesOptimal(vector<int>& nums, int k){
        unordered_map<int, int> indexMap;
        for(int i=0;i<nums.size();i++){
            if(indexMap.count(nums[i]) && i-indexMap[nums[i]]<=k){
              return true;
            }
            indexMap[nums[i]] = i;
            if(indexMap.size() > k){
                indexMap.erase(nums[i-k]);
            }
        }
        return false;
    }
};