class Solution:
  def lenlastWord(self, s:str)->int:
    return len(s.strip().split()[-1])
