### <center> [最小的k个数](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/) </center>

### -题目-
> 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

### -示例1-
> 输入：arr = [3,2,1], k = 2  
输出：[1,2] 或者 [2,1]

### -示例2-
> 输入：arr = [0,1,2,1], k = 1  
输出：[0]

### -限制-
> 0 <= k <= arr.length <= 10000  
0 <= arr[i] <= 10000

---

### -方法1-
+ sort之后取前k个。

### -ac代码-
```py
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        return sorted(arr)[:k]
```

### -复杂度-
+ $T(n) = O(n log n)$
+ $S(n) = O(1)$
