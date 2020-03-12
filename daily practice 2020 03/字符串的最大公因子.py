"""
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

 

示例 1：

输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：

输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：

输入：str1 = "LEET", str2 = "CODE"
输出：""
 

提示：

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] 和 str2[i] 为大写英文字母

链接：https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
"""

class Solution:
    # without (1): wa for
    # "ABCDEF"
    # "ABC"

    # without (2): wa for
    #   "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
    # "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"

    # (3) wa for
    # "LEET"
    # "CODE"
    # not len(str1) == len(str2)! "a", "b" have the same len but don't satisfy the requirements

    # (4) wa for
    # "ABCABCDDD"
    # "ABC"

    # with solution: https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/solution/zi-fu-chuan-de-zui-da-gong-yin-zi-by-leetcode-solu/

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # if len(str1) == len(str2):
        #     return str1
        # (3)

        # If the lens are equal, the strs may be the same or not satisfy the requirements.
        if len(str1) == len(str2):
            return str1 if str1 == str2 else ""

        # Finds the shorter and the longer.
        short_str, long_str = (str1, str2) if len(str1) < len(str2) else (str2, str1)

#        for i in range(1, len(short_str) + 1):
        for i in range(len(short_str), 0, -1):
            X = short_str[:i]

            # if len(short_str) % len(X) == 0 and len(long_str) % len(X) == 0 \
            #     and X == long_str[:i] \
            #     and X == long_str[i:i+len(X)]:  # (1)
            #         return X
            # (4)

            if len(short_str) % len(X) == 0 and len(long_str) % len(X) == 0 \
                and X * int(len(str1) / len(X)) == str1 \
                and X * int(len(str2) / len(X)) == str2:
                return X

        return ""


# n: iterate a seq from right to left: range(-1, len(seq) - 1, -1)
# n: a, b = (a, b) if condition else (b, a). () needed.
