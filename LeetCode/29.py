class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == divisor:
            return 1
        elif dividend == divisor * -1:
            return -1
        elif divisor == 1:
            return dividend
        elif divisor == -1 and dividend > -2**31:
            return dividend * -1
        elif abs(dividend) < abs(divisor):
            return 0
        elif dividend == -2**31 and divisor == -1:
            return 2**31 -1
        a = abs(dividend)
        b = abs(divisor)
        q = 1
        ans = 0
        while a >= b:
            q = 1
            while b * q <= a:
                q *= 2
            ans += q // 2
            a -= b * (q / 2)

        if divisor * dividend < 0:
            return ans * -1
        return ans
