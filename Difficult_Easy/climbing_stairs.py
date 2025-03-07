class Solution:
  def climb_stairs(self, n:int)->int:
    if(n==1 or n==2):
      return n
    prev1, prev2 = 2, 1
    for _ in range(3, n+1):
      prev1, prev2 = prev1+prev2, prev1

    return prev1
