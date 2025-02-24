class Solution:
    def isValid(self, s: str) -> bool:
        main = []
        
        for i in range(len(s)):
            if main and self.is_pair(main[-1], s[i]):  # Check if stack is non-empty
                main.pop()
            else:
                main.append(s[i])  # Push character onto stack
        
        return not main  # If stack is empty, return True; otherwise, return False

    def is_pair(self, last, cur):
        return (last == "(" and cur == ")") or \
               (last == "{" and cur == "}") or \
               (last == "[" and cur == "]")