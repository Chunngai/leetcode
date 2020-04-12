"""
实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

示例 1：

输入: s = "leetcode"
输出: false 
示例 2：

输入: s = "abc"
输出: true
限制：

0 <= len(s) <= 100
如果你不使用额外的数据结构，会很加分。

链接：https://leetcode-cn.com/problems/is-unique-lcci
"""

# category: strings

# class Solution:  # passed but used set
#     def isUnique(self, astr: str) -> bool:
#         astr_ = ''.join(sorted(set(astr), key=astr.index))
        
#         return astr == astr_

class Solution:  # passed with solution: bit operation, from https://leetcode-cn.com/problems/is-unique-lcci/solution/wei-yun-suan-fang-fa-si-lu-jie-shao-by-zhen-zhu-ha/
    def isUnique(self, astr: str) -> bool:
        mark = 0  # treat it as a 26 bit bool array
        for char in astr:
            offset = ord(char) - ord('a')  # \in {0...00, 0...10, 1...00}

            if (mark & (1 << offset)) != 0:  # 1 << offset = 10...0 (offset 0s)
                return False
            else:
                mark |= (1 << offset)

        return True

# n: copy structs: .copy()
# n: sorted(list)
# n: set can be sorted
# n: ord(char): ascii number of the char
