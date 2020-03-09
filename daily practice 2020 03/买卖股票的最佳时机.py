"""
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
"""

# category: arrays

# class Solution:  # wa for [2,4,1]. may not be min and max
#     def maxProfit(self, prices: List[int]) -> int:
#         if not prices:  # []
#             return 0

#         # Finds the min value.
#         min_value = min(prices)

#         # Finds a max value after the found min value.
#         max_value = max(prices[prices.index(min_value):])

#         rst = max_value - min_value

#         return rst if rst > 0 else 0

# class Solution:  # wa due to time limit
#     def maxProfit(self, prices: List[int]) -> int:
#         if not prices:
#             return 0

#         max_value = 0
#         for buy_idx in range(len(prices)):
#             for sell_idx in range(buy_idx + 1, len(prices)):
#                 max_value = max(prices[sell_idx] - prices[buy_idx], max_value)

#         return max_value

# class Solution:  # passed
#     def maxProfit(self, prices: List[int]) -> int:
#         max_value = 0
#         for buy_idx in range(len(prices)):
#                 max_value = max(max(prices[buy_idx:]) - prices[buy_idx], max_value)

#         return max_value

class Solution:  # passed with less time, with solution from: [7,6,4,3,1]
    def maxProfit(self, prices: List[int]) -> int:
        min_value = float("inf")
        max_profit = 0

        for price in prices:
            min_value = min(price, min_value)
            max_profit = max(max_profit, price - min_value)

        return max_profit

# t: find out how to find the max in an unordered list in a short time
