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

Height tells us the longest path from a node down to a leaf.

```text
Height of leaf = 0
Height of 2 = 1
Height of 1 = 2
```

Some courses count height using levels instead of edges, so always check the convention.

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
        left = right = nullptr;
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
-1 = nullptr
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
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

int idx = -1;

Node* buildTree(vector<int>& nodes) {

    idx++;

    if (nodes[idx] == -1) {
        return nullptr;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);

    currNode->right = buildTree(nodes);

    return currNode;
}

int main() {

    vector<int> nodes = {
        1, 2, 4, -1, -1,
        5, -1, -1,
        3, -1,
        6, -1, -1
    };

    Node* root = buildTree(nodes);

    cout << "Root = " << root->data << endl;

    return 0;
}
```

Main idea:

```text
Read value

If -1
→ return nullptr

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

    if (root == nullptr) {
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

    if (root == nullptr) {
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

    if (root == nullptr) {
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
#include <queue>

void levelOrder(Node* root) {

    if (root == nullptr) {
        return;
    }

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {

        Node* curr = q.front();

        q.pop();

        cout << curr->data << " ";

        if (curr->left != nullptr) {
            q.push(curr->left);
        }

        if (curr->right != nullptr) {
            q.push(curr->right);
        }
    }
}
```

Main idea:

```text
Push root

Take front node

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

we can use `nullptr` as a marker to show where one level ends.

```cpp
void levelOrderByLevel(Node* root) {

    if (root == nullptr) {
        return;
    }

    queue<Node*> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {

        Node* curr = q.front();
        q.pop();

        if (curr == nullptr) {

            cout << endl;

            if (!q.empty()) {
                q.push(nullptr);
            }
        }
        else {

            cout << curr->data << " ";

            if (curr->left != nullptr) {
                q.push(curr->left);
            }

            if (curr->right != nullptr) {
                q.push(curr->right);
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
Preorder  → Root Left Right

Inorder   → Left Root Right

Postorder → Left Right Root

Level Order → BFS using Queue
```

Main recursive pattern:

```cpp
if (root == nullptr) {
    return;
}

process root;

function(root->left);

function(root->right);
```

This recursive structure will appear again and again in Binary Tree problems.