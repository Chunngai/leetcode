"""
字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

 

示例 1:

输入: 
first = "pale"
second = "ple"
输出: True
 

示例 2:

输入: 
first = "pales"
second = "pal"
输出: False

链接：https://leetcode-cn.com/problems/one-away-lcci
"""

# category: strings

class Solution:  # passed
    def oneEditAway(self, first: str, second: str) -> bool:
        if first == second:
            return True
        
        if len(first) == len(second):
            replace = 0
            for i in range(len(first)):
                if first[i] != second[i]:
                    replace += 1

            return replace <= 1

        # be careful for being out of bounds when using str[i+1:]
        # if len(first) != len(second): 
            # i = 0
            # while i < len(first) and i < len(second):
            #     if first[i] != second[i]:
            #         break
            #     first = first[i + 1:] if i + 1 < len(first) else ""
            #     second = second[i + 1:] if i + 1 < len(second) else ""
            #     i += 1

            # first = ''.join(list(reversed(first)))
            # second = ''.join(list(reversed(second)))

            # i = 0
            # while i < len(first) and i < len(second):
            #     if first[i] != second[i]:
            #         break
            #     first = first[i + 1:] if i + 1 < len(first) else ""
            #     second = second[i + 1:] if i + 1 < len(second) else ""
            #     i += 1

            # return (len(first) == 1 and len(second) == 0) or (len(first) == 0 and len(second) == 1)

        if len(first) != len(second): 
            short_str = first if len(first) < len(second) else second
            long_str = first if len(first) > len(second) else second

            i = 0
            while i < len(short_str):
                if short_str[i] != long_str[i]:
                    break
                i += 1

            if short_str[i:] == long_str[i + 1:]:
                return True
            else:
                return False
            

# n:
#   str((reversed("")))
#   '<reversed object at 0x7f17b533d6d0>'
#   ''.join(list(reversed("")))
#   ''
