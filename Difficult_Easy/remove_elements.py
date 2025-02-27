#here we will follow a different approach - swapping left and right when val is envountered 
from typing import List

class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        left, right = 0, len(nums)

        while left < right:
            if nums[left] == val:
                nums[left] = nums[right - 1]  # Swap with the last valid element
                right -= 1  # Reduce the size
            else:
                left += 1  # Move to next element

        return right  # Length of the updated array