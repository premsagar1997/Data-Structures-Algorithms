/**
Tree -> Tree can be defined as a collection of entities (node) linked together to simulate a hierarchy.

Sibling -> Children of same parent

Degree -> Degree of node is number of children of that node

Degree of tree -> Maximum degree among all nodes

Depth of node -> length of path from root to that node

Height of node -> number of edges in the longest path from that node to leaf

Height ot tree -> height of root node

Level of node -> depth of node

Ancestor -> any predecessor node on the path from root to that node

Decendant -> any successor node on the path from that node to leaf node

Number of egdes -> if there are N number of node then there will be (N-1) edges

---------------------------------------------------------------------
Binary Tree -> each node can have atmost 2 children

Maximum number of nodes possible at any level i is 2^i

Maximum number of nodes in tree of height h = (2^(h+1) - 1)

Minimum number of nodes in tree of height h = (h + 1)

Types of Binary tree ->
1. Full/Proper/Strict Binary Tree
2. Complete Binary Tree
3. Perfect Binary Tree
4. Degenerate Binary Tree

1. Full binary tree -> Each node have either 0 or 2 children

2. Complete binary tree -> all levels are completely filled(except possibly the last level) and the last level has nodes as left as possible

3. Perfect binary tree -> all internal nodes have 2 children and all leaves are at same level

4. Degenerate binary tree(Skewed binary tree) -> each internal have only one child
    left skewed binary tree - These are those skewed binary tree in which all the nodes are having a left child or no child at all.
    right skewed binary tree - These are those skewed binary tree in which all the nodes are having a right child or no child at all.


------------------------------------------
Array representation of binary tree:-
Note:- If tree is not complete binary tree then first of all have to make it complete binary tree

1. If array index starts from 0:-
If a node is at index i:
left child = ((2*i)+1)
right child = ((2*1)+2)
parent = floor value of [(i-1)/2]

2. If array index starts from 1:-
If a node is at index i:
left child = (2*i)
right child = ((2*1)+1)
parent = floor value of [i/2]

*/