/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

//can solve this using fibonacci series approach

class Solution{
public:
  int climb_stairs(int n){
    if(n==1 || n==2) return n;
    int prev1=2, prev2=1, current;
    for(int i=3;i<=n;i++){ //as we already have F(1) and F(2) we start from 3
      current = prev2+prev1;
      prev2=prev1;
      prev1=current;
    }
    return current;
  }
};