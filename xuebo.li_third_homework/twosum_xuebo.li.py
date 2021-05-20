from typing import List


class TwoSum:
    @staticmethod
    def cal(nums_origin: List[int], target: int) -> List[int]:
        """
        :param nums_origin: Given list
        :param target: Target number
        :return: Calculation results, if fails, return None
        """
        record = dict()
        length = len(nums_origin)
        for index in range(length):
            if target - nums_origin[index] in record:
                return [record[target - nums_origin[index]], index]
            record[nums_origin[index]] = index
        return []


nums = [2, 7, 13, 24]
target = 9
ret = TwoSum
result = ret.cal(nums, target)
if not result:
    print("Not Found！")
else:
    print(f"Found: {result}")
