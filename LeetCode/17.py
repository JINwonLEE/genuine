class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def helper(ind, comb, dig, l, digits, ans):
            if l == 0:
                return
            if ind == l:
                ans.append(comb)
                return
        
            for i in dig[(int)(digits[ind])]:
                comb = comb + i
                helper(ind + 1, comb, dig, l, digits, ans)
                comb = comb[:-1] 
            return 

        l = len(digits)
        ans = []
        dig = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        tmp = ""
        helper(0, tmp, dig, l, digits, ans)
    
        return ans
