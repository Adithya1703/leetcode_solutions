/*
You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.

 

Example 1:

Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
Output: 12
Explanation: We can replace 0's in the following way:
- Replace the two 0's in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
- Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
Example 2:

Input: nums1 = [2,0,2,0], nums2 = [1,4]
Output: -1
Explanation: It is impossible to make the sum of both arrays equal.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
0 <= nums1[i], nums2[i] <= 106
*/

/*
Throught Process:

as per question we need to replace 0 with positive integers so that both arrays have equal sum
and the sum is minimum.
So we can replace 0 with 1 and then we can replace the rest of the 0 with the difference of the sum of both arrays.
One thing to keep in mind is that if zero is not present in any of the array then we can return -1.
We can do this by first calculating the sum of both arrays and then replacing the 0's with 1 and the rest with the difference of the sum of both arrays.

then we can check if the sum of both arrays is equal or not.

so the approach is as follows:

Calculate: sum1 = sum of nums1
Calculate: sum2 = sum of nums2
Calculate: zero1 = number of 0's in nums1
Calculate: zero2 = number of 0's in nums2
Calculate: minPossibleSum1 = sum1 + zero1
Calculate: minPossibleSum2 = sum2 + zero2
Calculate: target = max(minPossibleSum1, minPossibleSum2)


Try to match at target = max(minPossibleSum1, minPossibleSum2)

See if we can reach target from both sides within limits.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    long long minEqualSum(vector<int>& nums1, vector<int>& nums2){
      long long sum1 = 0, sum2 = 0;
      int zero1 = 0, zero2 = 0;
      for(int num: nums1){
        if(num == 0) zero1++;
        else sum1 += num;
      }
      for(int num: nums2){
        if(num == 0) zero2++;
        else sum2 += num;
      }

      long long minsum1 = sum1+zero1, minsum2 = sum2+zero2;
      // If either array has no zero and its sum < the other filled one → not possible
      if(zero1 == 0 && minsum1 < minsum2) return -1;
      if(zero2 == 0 && minsum2 < minsum1) return -1;

      return max(minsum1, minsum2);

    }
    // Time complexity: O(n) where n is the length of the longest array
    // Space complexity: O(1) as we are not using any extra space
};