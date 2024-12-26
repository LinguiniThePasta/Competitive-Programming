# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def checkSwaps(queueNode):
    queue = [i.val for i in queueNode]

    if len(queue) < 2:
        return 0
    ans = 0
    sortedQueue = sorted(queue)
    hashmap = defaultdict(int)
    for index, item in enumerate(queue):
        hashmap[item] = index

    for i in range(len(queue)):
        if (queue[i] == sortedQueue[i]):
            continue
        ans += 1
        #swap the queue elements
        #swap the hashmap indexes
        j = hashmap[sortedQueue[i]]
        temp = queue[i]
        queue[i] = sortedQueue[i]
        queue[j] = temp
        hashmap[temp] = j
        hashmap[queue[i]] = i
    return ans

class Solution(object):
    def minimumOperations(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        queue = [root]
        ans = 0
        while True:
            ans += checkSwaps(queue)
            childQueue = []
            while len(queue) > 0:
                curNode = queue.pop(0)
                if curNode.left is not None:
                    childQueue.append(curNode.left)
                if curNode.right is not None:
                    childQueue.append(curNode.right)
            if len(childQueue) == 0:
                break
            queue = childQueue
        return ans