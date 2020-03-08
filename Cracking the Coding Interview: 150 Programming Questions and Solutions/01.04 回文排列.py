"""
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

回文串不一定是字典当中的单词。

 

示例1：

输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）

链接：https://leetcode-cn.com/problems/palindrome-permutation-lcci
"""

# category: strings

# class Solution:  # passed
#     def canPermutePalindrome(self, s: str) -> bool:
#         chr_dict = {}
#         for char in s:
#             if char in chr_dict:
#                 chr_dict[char] += 1
#             else:
#                 chr_dict[char] = 1

#         odd = 0
#         for value in chr_dict.values():
#             if value % 2 == 1:
#                 odd += 1

#         return odd <= 1

class Solution:  # passed with solution: Counter(), from: https://leetcode-cn.com/problems/palindrome-permutation-lcci/solution/python3jie-ti-by-d_points/
    def canPermutePalindrome(self, s: str) -> bool:
        chr_number = collections.Counter(s)

        odd = 0
        for value in chr_number.values():
            if value % 2 == 1:
                odd += 1

        return odd <= 1

# n: collections.Counter(str) returns a dict whose k-v is chr-number
# n: collections.Counter(str).keys() = dict(collections.Counter(str)).keys(). the same for values
