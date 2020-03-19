"""
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。

在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:

输入:
"abccccdd"

输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
"""

# class Solution:  # wa for "aabfiejdebdcdc"
#     def longestPalindrome(self, s: str) -> int:
#         count = collections.Counter(s)

#         max_len = 0
#         for value in count.values():
#             print(value, value % 2)
#             max_len += value if value % 2 == 0 else 0


#         max_len += 1 if sorted(list(count.values()))[0] == 1 else 0

#         return max_len

# class Solution:  # wa. s: "aabbbccc": we can take 2 c's
#     def longestPalindrome(self, s: str) -> int:
#         count = collections.Counter(s)`

#         max_len = 0

#         for key, value in count.items():
#             print(f"key: {key}, value: {value}, value % 2: {value % 2}")

#         for value in count.values():
#             max_len += value if value % 2 == 0 else 0

#         for value in sorted(list(count.values()))[::-1]:
#             if value % 2 == 1:
#                 max_len += value
#                 break

#         return max_len

class Solution:
    def longestPalindrome(self, s: str) -> int:

        # Builds a dict.
        counter = collections.Counter(s)

        max_len = 0
        for value in counter.values():
            max_len += 2 * (value // 2)

        if (len(s) - max_len) != 0:
            max_len += 1

        return max_len

# n: keys() should be converted to list to sort
