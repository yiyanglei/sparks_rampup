"""addBinary function"""

class Solution:
    def addBinary(self, a, b):
        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        print(bin(x)[2:])

if __name__ == '__main__':
    add = Solution()
    add.addBinary("1010", "1011")
