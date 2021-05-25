"""addBinary function"""


class Solution:
    """..."""

    def addBinary(self, a: str, b: str) -> str:
        """Define for binary summation function.
        :param a: binary string
        :param b: binary string
        :return: add binary string
        """

        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        return bin(x)[2:]


if __name__ == '__main__':
    add = Solution()
    print(add.addBinary("1010", "1011"))
