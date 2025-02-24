#Python code:

from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        ans = strs[0]  # Start with the first word
        for s in strs[1:]:  # Iterate from the second word onwards
            while not s.startswith(ans):  # Keep reducing ans until it's a prefix
                ans = ans[:-1]
                if not ans:  # If ans becomes empty, return ""
                    return ""
        
        return ans