# Question can be accessed on: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1/

'''
# Node Class:
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
        '''
class Solution:
    #Function to find the height of a binary tree.
    def height(self, root):
        # code here
        
        def getMaxHeight(root = root, count=0):
            
            if(root == None):
                return count
            
            count += 1
            # left = getMaxHeight(root.left, count)
            # right = getMaxHeight(root.right, count)
            
            # if(left == None):
            #     return getMaxHeight(root.right, count)
            # if(right == None):
            #     return getMaxHeight(root.left, count)
                
            # return max(left,right)
            return max(getMaxHeight(root.left, count), getMaxHeight(root.right, count))
            
        return getMaxHeight()