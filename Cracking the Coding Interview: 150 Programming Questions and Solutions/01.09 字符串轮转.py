"""
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

示例1:

 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True
示例2:

 输入：s1 = "aa", "aba"
 输出：False
提示：

字符串长度在[0, 100000]范围内。
说明:

你能只调用一次检查子串的方法吗？

链接：https://leetcode-cn.com/problems/string-rotation-lcci
"""

# category: arrays

class Solution:  # passed
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):  # s1 = "aa", s2 = "aba"
            return False
        if not s1 and not s2:  # s1 = "", s2 = ""
            return True

        s2 = s2 + s2
        for i in range(len(s2)):
            if s1 == s2[i:i+len(s1)]:
                return True
        return False
