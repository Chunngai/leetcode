"""
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出: [null,null,null,2,1,2]
示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出: [null,-1,-1]
 

限制：

1 <= push_back,pop_front,max_value的总操作数 <= 10000
1 <= value <= 10^5

链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
"""

# category: queues

import queue

# class MaxQueue:  # passed, but max(): O(n)

#     def __init__(self):
#         self.deque = queue.deque()

#     def max_value(self) -> int:
#         return max(self.deque) if self.deque else -1

#     def push_back(self, value: int) -> None:
#         self.deque.append(value)

#     def pop_front(self) -> int:
#         return self.deque.popleft() if self.deque else -1

# class MaxQueue:  # wa for [4, 2, 0, 3]

#     def __init__(self):
#         self.queue = queue.Queue()
#         self.queue_max = []

#     def max_value(self) -> int:
#         return self.queue_max[-1] if self.queue_max else -1

#     def push_back(self, value: int) -> None:
#         self.queue.put(value)

#         if self.queue_max and self.queue_max[-1] <= value:
#             self.queue_max.append(value)
#         if not self.queue_max:
#             self.queue_max.append(value)

#     def pop_front(self) -> int:
#         if self.queue.empty():
#             return -1

#         value = self.queue.get()

#         if self.queue_max and self.queue_max[-1] == value:
#             self.queue_max.pop()

#         return value

class MaxQueue:  # passed with solution: https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/solution/ru-he-jie-jue-o1-fu-za-du-de-api-she-ji-ti-by-z1m/

    def __init__(self):
        self.queue = queue.Queue()
        self.deque = queue.deque()

    def max_value(self) -> int:
        return self.deque[0] if self.deque else -1

    def push_back(self, value: int) -> None:
        self.queue.put(value)

        while self.deque and self.deque[-1] <= value:
            self.deque.pop()
        
        self.deque.append(value)

    def pop_front(self) -> int:
        if self.queue.empty():
            return -1

        value = self.queue.get()

        if self.deque and self.deque[0] == value:
            self.deque.popleft()

        return value

# t: basic operations of deque
# q: is there a func to judge if a deque is empty?
# a: no, but deque is True if deque is not empty else False
# n for 均摊时间复杂度:
#   if T(n) for most cases is O(1), and only one or two of very few are O(n), then the 均摊时间复杂度 is O(1)

# Your MaxQueue object will be instantiated and called as such:
# obj = MaxQueue()
# param_1 = obj.max_value()
# obj.push_back(value)
# param_3 = obj.pop_front()
