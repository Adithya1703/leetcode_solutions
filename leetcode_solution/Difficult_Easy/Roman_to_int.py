#Python Code
#replace less than one chars and translate to numbers

class Solution:
    def romanToInt(self, s: str) -> int:
        translations = {
            "I": 1, "V": 5, "X": 10, "L": 50,
            "C": 100, "D": 500, "M": 1000
        }

        ans = 0
        prev = 0  # Track previous value

        for char in reversed(s):  # Iterate from right to left
            curr = translations[char]
            if curr < prev:  
                ans -= curr  # Subtract if smaller value precedes a larger value
            else:
                ans += curr  
            prev = curr  # Update previous character value
        
        return ans
#