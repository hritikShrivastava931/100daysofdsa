class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build(inorder, postorder):
    if not inorder:
        return None

    root_val = postorder[-1]
    root = Node(root_val)

    index = inorder.index(root_val)

    left_in = inorder[:index]
    right_in = inorder[index+1:]

    left_post = postorder[:len(left_in)]
    right_post = postorder[len(left_in):-1]

    root.left = build(left_in, left_post)
    root.right = build(right_in, right_post)

    return root

def preorder(root):
    if root is None:
        return
    print(root.val, end=" ")
    preorder(root.left)
    preorder(root.right)

n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))

root = build(inorder, postorder)
preorder(root)