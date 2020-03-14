"""
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

链接：https://leetcode-cn.com/problems/longest-increasing-subsequence
"""

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if not nums:
            return 0

        LIS = [1 for _ in nums]  # the init values are 1 not 0.

        for i in range(1, len(nums)):
            # max_ = rsts[0]
            # for j in range(0, i):
            #     if nums[j] < nums[i]:
            #         max_ = max(rsts[j] + 1, max_)
            # rsts[i] = max_

            LIS[i] = max([(LIS[j] + 1 if nums[j] < nums[i] else 1) for j in range(0, i)])

        return max(LIS)

# n: expr + (expr if condition else expr). () needed.
