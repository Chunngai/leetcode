"""
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

 

示例 1：

输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
所有字符串中都仅包含小写英文字母

链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
"""

# class Solution:  # passed
#     def countCharacters(self, words: List[str], chars: str) -> int:
#         if not words:
#             return 0
#         if not chars:
#             return 0

#         cat_str = ''

#         chars_dict = collections.Counter(chars)

#         for word in words:
#             chars_dict_ = copy.deepcopy(chars_dict)
#             flag = True
#             for char in word:
#                 if chars_dict_[char] > 0:
#                     chars_dict_[char] -= 1
#                 else:
#                     flag = False
#                     break

#             if flag:
#                 cat_str += word


        # return len(cat_str)

class Solution:  # modified with solution from: https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/solution/pin-xie-dan-ci-by-leetcode-solution/
    def countCharacters(self, words: List[str], chars: str) -> int:
        if not words or not chars:
            return 0

        rst = 0  # (1)

        chars_dict = collections.Counter(chars)
        for word in words:
            word_dict = collections.Counter(word)
            for char in word:
                if chars_dict[char]  < word_dict[char]:  # (2)
                    break
            else:
                rst += len(word)


        return rst

# n: for-else: the else clause is executed when the seq is iterated over, not executed when break
