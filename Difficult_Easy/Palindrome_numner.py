class Solution:
    def isPalindrome(self, x: int) -> bool:
        # Step 1: Quick rejections
        if x < 0 or (x % 10 == 0 and x != 0):
            return False

        # Step 2: Reverse only half of the number
        reversed_half = 0
        while x > reversed_half:
            reversed_half = reversed_half * 10 + x % 10
            x //= 10  # Remove the last digit

        # Step 3: Check for palindrome condition
        return x == reversed_half or x == reversed_half // 10  # Handle odd & even-length numbers