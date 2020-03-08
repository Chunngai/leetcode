"""
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

 

示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

链接：https://leetcode-cn.com/problems/zero-matrix-lcci
"""

# category: arrays

class Solution:  # passed
    def setZeroes(self, matrix: List[List[int]]) -> None:
        height = len(matrix)
        width = len(matrix[0])

        zero_idxs = []

        for row_idx in range(height):
            for col_idx in range(width):
                if matrix[row_idx][col_idx] == 0:
                    zero_idxs.append((row_idx, col_idx))

        for row_idx, col_idx in zero_idxs:
            matrix[row_idx] = [0 for i in range(width)]

            for row_idx_ in range(height):
                matrix[row_idx_][col_idx] = 0
