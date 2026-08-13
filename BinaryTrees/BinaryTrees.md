Yes. You want the **raw Markdown text directly in the chat**, inside one code block, so when you copy it into `BinaryTrees.md`, VS Code sees the actual `#`, `##`, ` ```cpp `, etc.

Copy everything inside this block:

````markdown
# Binary Trees

## What is a Binary Tree?

Arrays, vectors, linked lists, stacks and queues are **linear data structures**.

A tree is a **hierarchical data structure**.

A simple real-life example is folders on a laptop:

```text
Documents
├── College
│   ├── Maths
│   └── Finance
└── Work
    ├── Reports
    └── Projects
```

In a **general tree**, one node can have many children.

In a **binary tree**, every node can have a maximum of **2 children**.

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

---

## Important Terms

```text
        1          ← Root
      /   \
     2     3
    / \     \
   4   5     6     ← Leaf Nodes
```

- **Root** → topmost node
- **Edge / Branch** → line connecting two nodes
- **Parent** → node above another node
- **Child** → node below another node
- **Left Child** → child on the left
- **Right Child** → child on the right
- **Sibling** → nodes with the same parent
- **Leaf Node** → node with no children
- **Ancestor** → any node above another node
- **Descendant** → any node below another node
- **Subtree** → smaller tree inside the main tree

Example:

```text
Ancestors of 5 = 2, 1

Descendants of 2 = 4, 5
```

---

## Level, Depth and Height

```text
Level 0:        1

Level 1:      2   3

Level 2:     4 5   6
```

### Depth

Depth tells us how far a node is from the root.

```text
Depth of 1 = 0
Depth of 2 = 1
Depth of 5 = 2
```

### Height

Height is the **maximum distance from the root to a leaf**.

Height can be calculated in terms of:

```text
1. Number of nodes
2. Number of edges
```

Example:

```text
        1
       /
      2
     /
    4
```

Longest path:

```text
1 → 2 → 4
```

Therefore:

```text
Height in terms of nodes = 3
Height in terms of edges = 2
```

---

# Node Structure

Every node stores:

```text
data
left pointer
right pointer
```

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};
```

---

# Building a Binary Tree from Preorder

Suppose the preorder sequence is:

```text
1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1
```

Here:

```text
-1 = NULL
```

The tree becomes:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

Preorder follows:

```text
ROOT → LEFT → RIGHT
```

Code:

```cpp
int idx = -1;

Node* buildTree(vector<int> nodes) {

    idx++;

    if(nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}
```

Main idea:

```text
Read value

If -1
→ return NULL

Otherwise
→ create node
→ build left subtree
→ build right subtree
→ return node
```

---

# Tree Traversal

Traversal means visiting every node in the tree.

There are 4 important traversals.

```text
DFS
├── Preorder
├── Inorder
└── Postorder

BFS
└── Level Order
```

---

# Preorder Traversal

Order:

```text
ROOT → LEFT → RIGHT
```

For:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

Output:

```text
1 2 4 5 3 6
```

Code:

```cpp
void preorder(Node* root) {

    if(root == NULL) {
        return;
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}
```

Time Complexity:

```text
O(n)
```

---

# Inorder Traversal

Order:

```text
LEFT → ROOT → RIGHT
```

Output:

```text
4 2 5 1 3 6
```

Code:

```cpp
void inorder(Node* root) {

    if(root == NULL) {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}
```

Time Complexity:

```text
O(n)
```

---

# Postorder Traversal

Order:

```text
LEFT → RIGHT → ROOT
```

Output:

```text
4 5 2 6 3 1
```

Code:

```cpp
void postorder(Node* root) {

    if(root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}
```

Time Complexity:

```text
O(n)
```

---

# Easy Way to Remember DFS Traversals

Only the position of the **root** changes.

```text
Preorder
ROOT → LEFT → RIGHT

Inorder
LEFT → ROOT → RIGHT

Postorder
LEFT → RIGHT → ROOT
```

Memory trick:

```text
PRE  → Root first

IN   → Root in the middle

POST → Root last
```

Preorder, Inorder and Postorder are all **DFS — Depth First Search**.

---

# Level Order Traversal

Level Order is **BFS — Breadth First Search**.

We visit the tree level by level.

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

Output:

```text
1 2 3 4 5 6
```

We use a **queue**.

```cpp
void levelOrder(Node* root) {

    if(root == NULL) {
        return;
    }

    queue<Node*> Q;

    Q.push(root);

    while(!Q.empty()) {

        Node* curr = Q.front();
        Q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL) {
            Q.push(curr->left);
        }

        if(curr->right != NULL) {
            Q.push(curr->right);
        }
    }
}
```

Main idea:

```text
Push root

Take front node

Pop it

Print it

Push left child

Push right child

Repeat
```

---

# Printing Level by Level

If we want:

```text
1
2 3
4 5 6
```

we can push `NULL` into the queue to track where a level ends.

```cpp
void levelOrder(Node* root) {

    if(root == NULL) {
        return;
    }

    queue<Node*> Q;

    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()) {

        Node* curr = Q.front();
        Q.pop();

        if(curr == NULL) {

            cout << endl;

            if(!Q.empty()) {
                Q.push(NULL);
            }
        }
        else {

            cout << curr->data << " ";

            if(curr->left != NULL) {
                Q.push(curr->left);
            }

            if(curr->right != NULL) {
                Q.push(curr->right);
            }
        }
    }
}
```

Output:

```text
1
2 3
4 5 6
```

---

# DFS vs BFS

```text
DFS
→ Depth First Search
→ go deep first
→ Preorder
→ Inorder
→ Postorder
→ usually recursion / stack
```

```text
BFS
→ Breadth First Search
→ go level by level
→ Level Order
→ usually queue
```

---

# Height of a Binary Tree

Height is the **maximum distance from the root to a leaf**.

We can calculate height using recursion.

Main idea:

```text
Call left subtree
Call right subtree
Combine the answers
```

For every node:

```text
height
=
max(left subtree height, right subtree height)
+
1
```

Code:

```cpp
int height(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt, rightHt) + 1;

    return currHt;
}
```

Example:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

At node `2`:

```text
leftHt  = height(4) = 1
rightHt = height(5) = 1

currHt = max(1, 1) + 1
       = 2
```

At node `1`:

```text
leftHt  = 2
rightHt = 2

currHt = max(2, 2) + 1
       = 3
```

Therefore:

```text
Height = 3 nodes / levels
```

Time Complexity:

```text
O(n)
```

---

# Count Total Number of Nodes

Question:

```text
Count the total number of nodes in a binary tree.
```

Main idea:

```text
Count nodes in left subtree
+
Count nodes in right subtree
+
1 for current node
```

Code:

```cpp
int count(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftCount = count(root->left);
    int rightCount = count(root->right);

    return leftCount + rightCount + 1;
}
```

For:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

```text
Total nodes = 6
```

Formula:

```text
count
=
leftCount + rightCount + 1
```

Time Complexity:

```text
O(n)
```

---

# Sum of Nodes

Question:

```text
Find the sum of all node values in the tree.
```

Main idea:

```text
Sum of left subtree
+
Sum of right subtree
+
current node's data
```

Code:

```cpp
int sum(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    return leftSum + rightSum + root->data;
}
```

For:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

```text
Sum = 1 + 2 + 3 + 4 + 5 + 6

Sum = 21
```

Formula:

```text
sum
=
leftSum + rightSum + root->data
```

Time Complexity:

```text
O(n)
```

---

# Diameter of a Binary Tree

Diameter means the **longest path between any two nodes** in a tree.

Example:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

One longest path is:

```text
4 → 2 → 1 → 3 → 6
```

Diameter in terms of nodes:

```text
5
```

The diameter can occur in 3 places:

```text
1. Through the current root

2. Completely inside the left subtree

3. Completely inside the right subtree
```

There are two approaches:

```text
Approach 1 → O(n²)

Approach 2 → O(n)
```

---

# Diameter Approach 1 — O(n²)

For the current root:

```text
current diameter
=
height(left subtree)
+
height(right subtree)
+
1
```

Then calculate:

```text
diameter of left subtree

diameter of right subtree
```

Finally take the maximum.

Code:

```cpp
int diam1(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int currDiam =
        height(root->left)
        + height(root->right)
        + 1;

    int leftDiam = diam1(root->left);
    int rightDiam = diam1(root->right);

    return max(
        currDiam,
        max(leftDiam, rightDiam)
    );
}
```

Main idea:

```text
currDiam
→ diameter passing through current root

leftDiam
→ best diameter inside left subtree

rightDiam
→ best diameter inside right subtree
```

Then:

```text
answer
=
max(currDiam, leftDiam, rightDiam)
```

### Why is this O(n²)?

Because for every node we call `height()` again.

So we repeatedly calculate the height of the same subtrees.

```text
diameter traversal
+
repeated height traversals
=
O(n²)
```

---

# Diameter Approach 2 — O(n)

The problem with Approach 1 is:

```text
We keep recalculating height.
```

Instead, calculate:

```text
diameter + height
```

at the same time.

We return:

```cpp
pair<int, int>
```

where:

```text
first  = diameter
second = height
```

So each recursive call returns:

```text
(diameter, height)
```

Code:

```cpp
pair<int, int> diam2(Node* root) {

    if(root == NULL) {
        return make_pair(0, 0);
    }

    //(diameter, height)

    pair<int, int> leftInfo =
        diam2(root->left);      // (LD, LH)

    pair<int, int> rightInfo =
        diam2(root->right);     // (RD, RH)

    int currDiam =
        leftInfo.second
        + rightInfo.second
        + 1;

    int finalDiam =
        max(
            currDiam,
            max(leftInfo.first, rightInfo.first)
        );

    int finalHt =
        max(
            leftInfo.second,
            rightInfo.second
        ) + 1;

    return make_pair(finalDiam, finalHt);
}
```

Remember:

```text
leftInfo.first
→ Left Diameter

leftInfo.second
→ Left Height

rightInfo.first
→ Right Diameter

rightInfo.second
→ Right Height
```

Current diameter:

```text
currDiam
=
left height
+
right height
+
1
```

Final diameter:

```text
finalDiam
=
max(
    current diameter,
    left diameter,
    right diameter
)
```

Final height:

```text
finalHt
=
max(left height, right height)
+
1
```

Time Complexity:

```text
O(n)
```

Why?

```text
Each node is visited once.

Height and diameter are calculated together.
```

---

# Subtree of Another Tree

Question:

```text
Is one binary tree a subtree of another binary tree?
```

Example:

Main Tree:

```text
        1
      /   \
     2     3
    / \
   4   5
```

Subtree:

```text
     2
    / \
   4   5
```

Answer:

```text
true
```

Main idea:

```text
Search through the main tree.

When:

root->data == subRoot->data

check whether the two trees are identical.
```

If they are identical:

```text
return true
```

Otherwise:

```text
search left subtree

search right subtree
```

---

# Check if Two Trees are Identical

Before solving the subtree problem, we need a helper function.

Two trees are identical when:

```text
Their current nodes are equal

AND

Their left subtrees are identical

AND

Their right subtrees are identical
```

Code:

```cpp
bool isIdentical(Node* root1, Node* root2) {

    if(root1 == NULL && root2 == NULL) {
        return true;
    }
    else if(root1 == NULL || root2 == NULL) {
        return false;
    }

    if(root1->data != root2->data) {
        return false;
    }

    return isIdentical(root1->left, root2->left)
        && isIdentical(root1->right, root2->right);
}
```

Understand the base cases:

```text
root1 = NULL
root2 = NULL

→ both trees ended together
→ true
```

But:

```text
root1 = NULL
root2 = node

OR

root1 = node
root2 = NULL

→ structures are different
→ false
```

Then:

```text
root1->data != root2->data

→ values are different
→ false
```

Otherwise recursively compare:

```text
left with left

AND

right with right
```

---

# Check if One Tree is a Subtree

Code:

```cpp
bool isSubtree(Node* root, Node* subRoot) {

    if(root == NULL && subRoot == NULL) {
        return true;
    }
    else if(root == NULL || subRoot == NULL) {
        return false;
    }

    if(root->data == subRoot->data) {

        if(isIdentical(root, subRoot)) {
            return true;
        }
    }

    int isLeftSubtree =
        isSubtree(root->left, subRoot);

    if(!isLeftSubtree) {
        return isSubtree(root->right, subRoot);
    }

    return true;
}
```

Example:

```cpp
int main() {

    vector<int> nodes = {
        1, 2, 4, -1, -1,
        5, -1, -1,
        3, -1,
        6, -1, -1
    };

    Node* root = buildTree(nodes);

    Node* subRoot = new Node(2);

    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    cout << isSubtree(root, subRoot) << endl;

    return 0;
}
```

Output:

```text
1
```

Because in C++:

```text
true  = 1
false = 0
```

---

# Main Recursive Pattern in Binary Trees

A lot of binary tree problems are actually following the **same recursive structure**.

```text
BASE CASE

↓
```

Then:

```text
SOLVE LEFT SUBTREE

↓

SOLVE RIGHT SUBTREE

↓

COMBINE BOTH ANSWERS

↓

RETURN
```

General structure:

```cpp
answer function(Node* root) {

    if(root == NULL) {
        return baseAnswer;
    }

    answer left = function(root->left);

    answer right = function(root->right);

    return combine(left, right);
}
```

We have already seen this pattern repeatedly.

### Height

```text
leftHt = height(left)

rightHt = height(right)

return max(leftHt, rightHt) + 1
```

### Count

```text
leftCount = count(left)

rightCount = count(right)

return leftCount + rightCount + 1
```

### Sum

```text
leftSum = sum(left)

rightSum = sum(right)

return leftSum + rightSum + root->data
```

### Diameter

```text
Get information from left subtree

Get information from right subtree

Combine the information

Return diameter + height
```

So the important pattern is:

```text
LEFT
+
RIGHT
+
CURRENT NODE
```

or more generally:

```text
RECURSE LEFT

RECURSE RIGHT

COMBINE
```

---

# Quick Revision

```text
Binary Tree
→ maximum 2 children

Root
→ top node

Leaf
→ no children

Sibling
→ same parent

Ancestor
→ above

Descendant
→ below

Subtree
→ smaller tree inside tree
```

Traversals:

```text
Preorder
→ Root Left Right

Inorder
→ Left Root Right

Postorder
→ Left Right Root

Level Order
→ BFS using Queue
```

Important recursive problems:

```text
Height
→ max(leftHt, rightHt) + 1

Count Nodes
→ leftCount + rightCount + 1

Sum Nodes
→ leftSum + rightSum + root->data
```

Diameter:

```text
Longest path between any two nodes

Approach 1
→ calculate height repeatedly
→ O(n²)

Approach 2
→ calculate diameter + height together
→ O(n)
```

Subtree:

```text
Find possible matching root

↓

Check if trees are identical

↓

If not, search left and right
```

Most important recursive pattern:

```text
BASE CASE

↓

LEFT SUBTREE

↓

RIGHT SUBTREE

↓

COMBINE

↓

RETURN
```
````
