/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
*/

//Cpp code - Brute force: using nested loops and shifting left whenever duplicate is found
//Time complexity - O(n^2)

#include<iostream>>
#include<vector>

using namespace std;

class Solution{
public:
  int removeDuplicates(vector<int>& nums){
    if(nums.empty()) return 0;  //return 0 as vector is empty
    int k=0;
    for(int i=0;i<nums.size();i++){ //iterate through entire array
      bool isDuplicate = false; //check whether current element is unique or not
      for(int j=0;j<k;j++){ //iterate to check current element is present in k elements of nums
        if(nums[i]==nums[j]){ //if duplicate found
          isDuplicate = true;
          break;
        }
      }
      if(!isDuplicate){ //if duplicate not found add current element to unique list
        nums[k++]=nums[i]; //placing element in kth position and incrementing k
      }
    }
    return k;
  }
};


//Optimal approach
//using two pointer apprach, TIme complexity - O(n)

class Solution{
  public:
    int removeDuplicates(vector<int>& nums){
      if(nums.empty()) return 0;  //return 0 as vector is empty
      int k=1; //second pointer - considering 1st element as always unique
      for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){ //comapre with previous element
          nums[k++]=nums[i];
        }
      }
      return k;
    }
  };