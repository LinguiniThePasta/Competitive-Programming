# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def reverseOddLevels(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        queue = []
        queue.append(root)
        level = 0
        while True:
            if (level % 2 == 1):
                for i in range(len(queue)/2):
                    queue[i].val, queue[-i-1].val = queue[-i-1].val, queue[i].val

            childQueue = []
            while len(queue) > 0:
                curNode = queue.pop()
                if (curNode.left is None):
                    break
                childQueue.append(curNode.left)
                childQueue.append(curNode.right)
            if len(childQueue) == 0:
                break

            queue += childQueue
            level += 1
        return root
