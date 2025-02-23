/*Given an array ofintegers Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.*/

//Code in cpp

//Brute force approach: time complexity - O(n^2)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // Return indices of the two numbers
                }
            }
        }
        return {}; // Return an empty vector if no solution is found
    }
};

//Optimal Solution:using hash_table, time complexity - O(n)

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map<int, int> numMap; // {value -> index}

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (numMap.find(comp) != numMap.end()) {
                return {numMap[comp], i}; // Corrected order
            }
            numMap[nums[i]] = i; // Store value with its index
        }
        return {}; // No solution found
    }
};
