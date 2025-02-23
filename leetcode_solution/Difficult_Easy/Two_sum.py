#Brute Force: same approach as above
from typing import List

class Solution:
	def twoSum(self, nums: List[int], target:int)->List[int]:
		n=len(nums)
		for i in range(n):
			for j in range(i+1,n):
				if nums[i]+nums[j]==target:
					return [i, j]
		return []


#Optimal Solution: hash it with dictionary

class Solution:
	def twoSum(self, nums:List[int], target:int)->List[int]:
		num_index = {}
		for index, num in enumerate(nums):
			comp = target - num
			if comp in num_index:
				return [num_index[comp], index]
			num_index[num]=index
		return []

