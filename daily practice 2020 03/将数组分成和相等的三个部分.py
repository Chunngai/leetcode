"""
给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。

形式上，如果可以找出索引 i+1 < j 且满足 (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1]) 就可以将数组三等分。

 

示例 1：

输出：[0,2,1,-6,6,-7,9,1,2,0,1]
输出：true
解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
示例 2：

输入：[0,2,1,-6,6,7,9,-1,2,0,1]
输出：false
示例 3：

输入：[3,3,6,5,-2,2,5,1,-9,4]
输出：true
解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4

链接：https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
"""

# class Solution:  # wa for [1,-1,1,-1] (output: i, j = 0, 2)
#     def canThreePartsEqualSum(self, A: List[int]) -> bool:
#         for i in range(len(A)):
#             for j in range(i + 1, len(A)):
#                 if sum(A[:i]) == sum(A[i:j]) == sum(A[j:]):
#                     return True

#         return False

# class Solution:  # (1) wa for time limit
#     def canThreePartsEqualSum(self, A: List[int]) -> bool:
#         for i in range(1, len(A)):
#             for j in range(i + 1, len(A)):
#                 if sum(A[:i]) == sum(A[i:j]) == sum(A[j:]):
#                     return True

#         return False

# class Solution:  # (2) passed with solution from: https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/solution/1013-jiang-shu-zu-fen-cheng-he-xiang-deng-de-san-2/
#     def canThreePartsEqualSum(self, A: List[int]) -> bool:

#         sum_A = sum(A)

#         if sum_A % 3 != 0:
#             return False

#         sum_A_one_third = sum_A / 3
#         for i in range(1, len(A)):
#             if sum(A[:i]) == sum_A_one_third:
#                 for j in range(i + 1, len(A)):
#                     if sum(A[i:j]) == sum_A_one_third:  # [i:j] guarantees 3 slices
#                         return True

#         return False

# n: two loops may be O(n)
# n: consider T(n) of built-ins

# class Solution:  # (3) wa for time limit. improved the way to sum from (1)
#     def canThreePartsEqualSum(self, A: List[int]) -> bool:

#         sum_A = sum(A)

#         if sum_A % 3 != 0:
#             return False

#         sum_A_one_third = sum_A / 3
#         sum_i = 0
#         for i in range(0, len(A) - 2):
#             sum_i += A[i]
#             sum_j = 0
#             for j in range(i + 1, len(A) - 1):
#                 sum_j += A[j]
#                 if sum_i == sum_j == sum_A_one_third:
#                     return True

#         return False

class Solution:  # (4) passed. improved the way to sum like (3) from (2)
    def canThreePartsEqualSum(self, A: List[int]) -> bool:

        sum_A = sum(A)

        if sum_A % 3 != 0:
            return False

        sum_A_one_third = sum_A / 3
        sum_i = 0
        for i in range(0, len(A) - 2):
            sum_i += A[i]
            if sum_i == sum_A_one_third:
                sum_j = 0
                for j in range(i + 1, len(A) - 1):  # range(i + 1, len(A) - 1) won't guarantee 3 slices this case
                    sum_j += A[j]
                    if sum_j == sum_A_one_third:
                        return True

        return False

