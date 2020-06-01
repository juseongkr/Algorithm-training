class Solution:
    def romanToInt(self, s: str) -> int:
        num = { 'M': 1000, 'CM': 900, 'D': 500, 'CD': 400, 'C': 100, 'XC': 90, 'L': 50, 'XL': 40, 'X': 10, 'IX': 9, 'V': 5, 'IV': 4, 'I': 1 }

        ans = 0
        for key, value in num.items():
            while s.startswith(key):
                ans += value
                s = s[len(key):]
        return ans
