"""
给定一幅由N × N矩阵表示的图像，其中每个像素的大小为4字节，编写一种方法，将图像旋转90度。

不占用额外内存空间能否做到？

 

示例 1:

给定 matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:

给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]

链接：https://leetcode-cn.com/problems/rotate-matrix-lcci
"""

# category: arrays

class Solution:  # passed with solution: zip(), from: https://leetcode-cn.com/problems/rotate-matrix-lcci/solution/yong-python-shun-shi-zhen-xuan-zhuan-by-2019_ncov/
    def rotate(self, matrix: List[List[int]]) -> None:
        matrix[:] = [list(reversed(row)) for row in zip(*matrix)]  # incorrect without [:]

# n for zip():
#   a = [1, 2, 3]
#   b = [8, 9]
#   zip(a, b) = [(1, 8), (2, 9)]
