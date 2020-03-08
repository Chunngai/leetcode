"""
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。

链接：https://leetcode-cn.com/problems/coin-change
"""

# category: dp

# class Solution:  # wa for coins = [1, 2, 5] and amount = 11. greedy search is not proper.
#     def coinChange(self, coins: List[int], amount: int) -> int:
#         if not coins:
#             return -1

#         count = 0
#         for value in sorted(coins)[::-1]:  # [::-1]. sorted()
#             count_i = int(amount / value)

#             count += count_i
#             amount -= value * count_i

#         if amount == 0:
#             return count
#         else:
#             return -1

class Solution:  # passed with solution: https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp_rst = [float("inf") for _ in range(amount + 1)]

        # Boundary condition.
        dp_rst[0] = 0

        # Recursive part.
        for coin_idx in range(len(coins)):
            for amount_ in range(len(dp_rst)):
                if amount_ >= coins[coin_idx]:
                    dp_rst[amount_] = min(dp_rst[amount_], dp_rst[amount_ - coins[coin_idx]] + 1)

        if dp_rst[amount] < float("inf"):
            return dp_rst[amount]
        else:
            return -1
