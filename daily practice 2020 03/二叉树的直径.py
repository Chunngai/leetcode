"""
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过根结点。

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

注意：两结点之间的路径长度是以它们之间边的数目表示。

链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# class Solution:  # wa. the distance may not go through the root!
#     def maxD(self, root: TreeNode) -> int:
#         if not root:  # root is None
#             return 0

#         # if (not root.left and not root.right) is True, (root.right is None) is also True
#         # if root.right is None:
#         #     return self.maxD(root.left) + 1
#         # elif root.left is None:
#         #     return self.maxD(root.right) + 1
#         # elif root.left is None and root.right is None:
#         #     return 0

#         if not root.left and not root.right:
#             return 0
#         elif not root.right:
#             return self.maxD(root.left) + 1
#         elif not root.left:
#             return self.maxD(root.right) + 1
#         else:
#             return max(self.maxD(root.left), self.maxD(root.right)) + 1

#     def diameterOfBinaryTree(self, root: TreeNode) -> int:
#         if not root:  # root: []
#             return 0

#         leftMax = self.maxD(root.left) + 1 if root.left is not None else 0
#         rightMax = self.maxD(root.right) + 1 if root.right is not None else 0

#         return leftMax + rightMax

# class Solution:  # passed
#     def __init__(self):
#         self.rst = 0

#     def maxD(self, root):
#         maxLD = self.maxD(root.left) + 1 if root.left else 0
#         maxRD = self.maxD(root.right) + 1 if root.right else 0

#         self.rst = max(self.rst, maxLD + maxRD)

#         return max(maxLD, maxRD)

#     def diameterOfBinaryTree(self, root: TreeNode) -> int:
#         if not root:
#             return 0

#         self.maxD(root)

#         return self.rst

class Solution:  # passed with solution from https://leetcode-cn.com/problems/diameter-of-binary-tree/solution/er-cha-shu-de-zhi-jing-by-leetcode-solution/
    def __init__(self):
        self.rst = 0

    def depth(self, root):
        if not root:
            return 0

        depthL = self.depth(root.left)
        depthR = self.depth(root.right)

        self.rst = max(self.rst, depthL + depthR)

        return max(depthL, depthR) + 1

    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0

        self.depth(root)

        return self.rst
