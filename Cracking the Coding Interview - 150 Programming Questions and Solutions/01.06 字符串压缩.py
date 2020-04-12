"""
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。

链接：https://leetcode-cn.com/problems/compress-string-lcci
"""

# category: strings

class Solution:  # passed
    def compressString(self, S: str) -> str:
        if not S:
            return S

        the_last_one = S[0]
        count = 1
        new_str = ''

        for char in S[1:] + ' ':  # a ' ' is needed or given "aabcccccaaa", "a2b1c5" will be returned but not "a2b1c5a3"
            if char == the_last_one:
                count += 1
            else:
                new_str += f"{the_last_one}{count}"
                the_last_one = char
                count = 1

        return new_str if len(new_str) < len(S) else S

# n: return S if S == '': invalid syntax. else ... is needed
