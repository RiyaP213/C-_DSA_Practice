# C++ Maps and Binary Tree Problems

# Maps

## What is a Map?

A `map` is a special container provided by the **C++ STL — Standard Template Library**.

We will study maps in much more detail later in the Hashmaps chapter.

For now, the important idea is:

```text
Map
→ stores KEY-VALUE pairs
```

Example:

```text
Key     Value
1       10
2       20
3       30
```

Think of it like:

```text
key → value
```

A key is used to find its corresponding value.

---

## Including Map

To use a map:

```cpp
#include <map>
```

Example:

```cpp
#include <iostream>
#include <map>
using namespace std;
```

---

## Declaring a Map

```cpp
map<int, int> m;
```

This means:

```text
key   = int
value = int
```

So:

```cpp
map<int, int> m;
```

stores:

```text
int → int
```

For example:

```text
1 → 100
2 → 200
3 → 300
```

---

## Inserting Values into a Map

We can insert a value using:

```cpp
m[key] = value;
```

Example:

```cpp
map<int, int> m;

m[1] = 10;
m[2] = 20;
m[3] = 30;
```

Now the map contains:

```text
1 → 10
2 → 20
3 → 30
```

---

## Accessing Values Using Keys

We access the value using its key:

```cpp
cout << m[key];
```

Example:

```cpp
cout << m[2];
```

Output:

```text
20
```

Because:

```text
2 → 20
```

---

# map.count()

We can check whether a key exists using:

```cpp
m.count(key)
```

It gives:

```text
1 → key is present
0 → key is not present
```

Example:

```cpp
if(m.count(2)) {
    cout << "Key exists";
}
```

Or:

```cpp
if(m.count(2) == 0) {
    cout << "Key does not exist";
}
```

This becomes important in **Top View of a Binary Tree**.

---

# Looping Through a Map

We can loop through the map using:

```cpp
for(auto it : m) {
    cout << it.first << " " << it.second << endl;
}
```

Here:

```text
it.first  → key

it.second → value
```

Example:

```cpp
map<int, int> m;

m[1] = 10;
m[2] = 20;
m[3] = 30;

for(auto it : m) {
    cout << it.first << " " << it.second << endl;
}
```

Output:

```text
1 10
2 20
3 30
```

---

# Important Property of map

A normal C++ `map` stores its keys in **sorted order**.

For example:

```cpp
map<int, int> m;

m[2] = 20;
m[-1] = 10;
m[1] = 30;
m[0] = 40;
```

When we iterate:

```text
-1
0
1
2
```

The keys come out in sorted order.

This property is very useful for the **Top View of a Binary Tree** because horizontal distances must eventually be printed from:

```text
left → right
```

---

# Quick Map Revision

```text
#include <map>

map<int, int> m;

m[key] = value;

m[key]
→ access value

m.count(key)
→ check whether key exists

it.first
→ key

it.second
→ value
```

Loop:

```cpp
for(auto it : m) {
    cout << it.first << " " << it.second << endl;
}
```

---

# Top View of a Binary Tree

## What is Top View?

Imagine looking at a binary tree **from above**.

The nodes visible from the top form the **Top View**.

Example:

```text
        1
      /   \
     2     3
    / \   / \
   4   5 4   6
```

From the top, the visible nodes are:

```text
4 2 1 3 6
```

Some nodes are hidden behind other nodes when viewed vertically from above.

---

# Another Top View Example

Consider:

```text
        1
       / \
      2   3
       \
        4
         \
          5
           \
            6
```

The top view is:

```text
2 1 3 6
```

Nodes `4` and `5` are hidden because another node occurs above them at the same horizontal position.

This gives us the key idea:

```text
For every vertical position,
keep the FIRST node visible from the top.
```

---

# Horizontal Distance

To solve Top View, we assign every node a **Horizontal Distance — HD**.

The root starts at:

```text
HD = 0
```

If we move left:

```text
HD = parent HD - 1
```

If we move right:

```text
HD = parent HD + 1
```

So:

```text
                1
              HD = 0
             /      \
            2        3
         HD=-1     HD=+1
```

For a bigger tree:

```text
              1
            HD=0
           /    \
          2      3
       HD=-1   HD=+1
       /  \       \
      4    5       6
   HD=-2 HD=0    HD=+2
```

---

# Why Horizontal Distance Works

Nodes with the same horizontal distance lie on the same vertical line.

For example:

```text
HD = -2 → 4

HD = -1 → 2

HD = 0  → 1, 5

HD = +1 → 3

HD = +2 → 6
```

For Top View, at:

```text
HD = 0
```

we see:

```text
1
```

not:

```text
5
```

because `1` is above `5`.

Therefore:

```text
For every HD,
store only the FIRST node encountered.
```

---

# Why BFS is Useful

We want to encounter nodes:

```text
top → bottom
```

So we use **Level Order Traversal / BFS**.

BFS processes:

```text
Level 1
then
Level 2
then
Level 3
...
```

Therefore the first node encountered for a particular horizontal distance is the node visible from the top.

---

# Data Structures for Top View

We need:

```cpp
queue<pair<Node*, int>> Q;
```

The queue stores:

```text
(node, horizontal distance)
```

Example:

```text
(Node*, HD)
```

We also need:

```cpp
map<int, int> m;
```

The map stores:

```text
HD → node data
```

So:

```text
key   = horizontal distance
value = node value
```

---

# Top View Algorithm

Start with:

```text
root → HD = 0
```

Push:

```text
(root, 0)
```

into the queue.

Then repeatedly:

```text
1. Take front element

2. Get:
   node
   horizontal distance

3. Check whether this HD already exists in map

4. If it does NOT exist
   → this is the first node at this HD
   → store it

5. Push left child with:
   HD - 1

6. Push right child with:
   HD + 1

7. Continue BFS
```

---

# Top View Code

```cpp
#include <queue>
#include <map>

void topView(Node* root) {

    queue<pair<Node*, int>> Q; // (node, HD)

    map<int, int> m; // (HD, node->data)

    Q.push(make_pair(root, 0));

    while(!Q.empty()) {

        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int currHD = curr.second;

        if(m.count(currHD) == 0) { // HD -> add in map
            m[currHD] = currNode->data;
        }

        if(currNode->left != NULL) {

            pair<Node*, int> left =
                make_pair(currNode->left, currHD - 1);

            Q.push(left);
        }

        if(currNode->right != NULL) {

            pair<Node*, int> right =
                make_pair(currNode->right, currHD + 1);

            Q.push(right);
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }

    cout << endl;
}
```

---

# Understanding the Queue

This line:

```cpp
queue<pair<Node*, int>> Q;
```

may look complicated.

Break it down:

```text
queue< ... >
```

means we have a queue.

Inside the queue we store:

```cpp
pair<Node*, int>
```

The pair contains:

```text
first  → Node*

second → int
```

For this problem:

```text
first  → node

second → horizontal distance
```

So:

```cpp
pair<Node*, int> curr = Q.front();
```

Then:

```cpp
Node* currNode = curr.first;
int currHD = curr.second;
```

---

# Why We Check map.count()

This is the most important part:

```cpp
if(m.count(currHD) == 0) {
    m[currHD] = currNode->data;
}
```

Suppose:

```text
HD = 0
```

has already been stored.

Then another node later appears at:

```text
HD = 0
```

We do NOT replace the original node.

Why?

Because Top View wants:

```text
FIRST node at each horizontal distance
```

BFS guarantees that the first one encountered is the highest visible node.

---

# Why map is Perfect Here

At the end we may have:

```text
HD    Node

-2 → 4
-1 → 2
 0 → 1
+1 → 3
+2 → 6
```

Since `map` keeps keys sorted, iterating through:

```cpp
for(auto it : m)
```

automatically visits:

```text
-2
-1
0
1
2
```

which corresponds to:

```text
LEFT → RIGHT
```

Therefore the output becomes:

```text
4 2 1 3 6
```

---

# Top View Pattern

```text
Top View

BFS
+
Horizontal Distance
+
Map
```

Remember:

```text
Root
HD = 0

Left
HD - 1

Right
HD + 1
```

and:

```text
First occurrence of HD
→ store in map

HD already exists
→ ignore
```

---

# Kth Level of a Binary Tree

Suppose we want to print all nodes at level `K`.

Example:

```text
        1          Level 1
      /   \
     2     3       Level 2
    / \     \
   4   5     6     Level 3
```

If:

```text
K = 3
```

Output:

```text
4 5 6
```

---

# Main Idea

We recursively travel through the tree while keeping track of:

```text
currLevel
```

When:

```text
currLevel == K
```

we print the node.

---

# Kth Level Code

```cpp
void KthHelper(Node* root, int K, int currLevel) {

    if(root == NULL) {
        return;
    }

    if(currLevel == K) {
        cout << root->data << " ";
        return;
    }

    KthHelper(root->left, K, currLevel + 1);  // left

    KthHelper(root->right, K, currLevel + 1); // right
}

void KthLevel(Node* root, int K) {

    KthHelper(root, K, 1);

    cout << endl;
}
```

---

# Understanding Kth Level Recursion

Initially:

```text
root
currLevel = 1
```

Every time we move downward:

```text
currLevel + 1
```

So:

```text
        1
        ↓
   currLevel = 1

      /     \

     2       3
     ↓       ↓
 curr=2    curr=2

   / \       \

  4   5       6
  ↓   ↓       ↓
curr=3      curr=3
```

When:

```cpp
currLevel == K
```

we have reached the required level.

---

# Why Return After Printing?

Notice:

```cpp
if(currLevel == K) {
    cout << root->data << " ";
    return;
}
```

Once we reach level `K`, we don't need to explore below that node.

So we return immediately.

---

# Kth Level Complexity

Every relevant node may be visited.

```text
Time Complexity = O(n)
```

Recursive call stack depends on tree height:

```text
Space Complexity = O(h)
```

where:

```text
h = height of tree
```

---

# Lowest Common Ancestor — LCA

The **Lowest Common Ancestor** of two nodes is the lowest node in the tree that is an ancestor of both nodes.

Consider:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

For:

```text
n1 = 4
n2 = 6
```

Their ancestors are:

```text
4 → 4, 2, 1

6 → 6, 3, 1
```

The common ancestor is:

```text
1
```

Therefore:

```text
LCA(4, 6) = 1
```

---

For:

```text
n1 = 4
n2 = 5
```

Paths are:

```text
1 → 2 → 4

1 → 2 → 5
```

The last common node is:

```text
2
```

Therefore:

```text
LCA(4, 5) = 2
```

---

# LCA — Approach 1

The first approach is:

```text
Find root → n1 path

Find root → n2 path

Compare both paths

Last common value
→ LCA
```

For:

```text
n1 = 4
n2 = 5
```

we get:

```text
path1:

1 → 2 → 4


path2:

1 → 2 → 5
```

Compare:

```text
1 == 1
2 == 2
4 != 5
```

The last equal node was:

```text
2
```

So:

```text
LCA = 2
```

---

# Finding Root-to-Node Path

We first need a function that finds the path from the root to a target node.

```cpp
bool rootToNodePath(Node* root, int n, vector<int> &path) {

    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);

    if(root->data == n) {
        return true;
    }

    int isLeft = rootToNodePath(root->left, n, path);

    int isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight) {
        return true;
    }

    path.pop_back();

    return false;
}
```

---

# Understanding rootToNodePath()

This function is a good example of **backtracking inside a tree**.

First:

```cpp
path.push_back(root->data);
```

We say:

```text
"Assume this node belongs to the correct path."
```

Then search:

```cpp
rootToNodePath(root->left, n, path);

rootToNodePath(root->right, n, path);
```

If either subtree finds the target:

```cpp
if(isLeft || isRight) {
    return true;
}
```

then the current node really does belong to the path.

But if neither side finds the target:

```cpp
path.pop_back();
```

We undo our choice.

That is backtracking.

---

# rootToNodePath Pattern

```text
Choose
↓
path.push_back()

Explore
↓
left
right

Success?
↓
return true

Failure?
↓
Undo choice
path.pop_back()
```

This is the same general idea seen in backtracking problems.

---

# LCA Approach 1 Code

```cpp
int LCA(Node* root, int n1, int n2) {

    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);

    rootToNodePath(root, n2, path2);

    int lca = -1;

    for(int i = 0, j = 0;
        i < path1.size() && j < path2.size();
        i++, j++) {

        if(path1[i] != path2[j]) {
            return lca;
        }

        lca = path1[i];
    }

    return lca;
}
```

Example:

```cpp
int n1 = 4;
int n2 = 5;

cout << "lca = " << LCA(root, n1, n2) << endl;
```

Output:

```text
lca = 2
```

---

# LCA Approach 1 Complexity

Finding both paths requires traversing the tree.

```text
Time Complexity = O(n)
```

We also store the paths:

```text
Space Complexity = O(n)
```

in the worst case.

---

# LCA — Approach 2

There is another approach where we find the LCA directly using recursion.

We don't explicitly create two path vectors.

The idea is:

```text
Search left subtree

Search right subtree

Use what comes back
```

---

# LCA Approach 2 Code

```cpp
Node* LCA2(Node* root, int n1, int n2) {

    if(root == NULL) {
        return NULL;
    }

    if(root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);

    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;
}
```

---

# Understanding LCA Approach 2

This is an important recursive tree pattern.

Each recursive call can return:

```text
NULL
```

or:

```text
a Node*
```

`NULL` means:

```text
"I didn't find either target in this subtree."
```

A node pointer means:

```text
"I found something relevant in this subtree."
```

---

## Base Case

```cpp
if(root == NULL) {
    return NULL;
}
```

No tree:

```text
→ nothing found
```

---

## Target Found

```cpp
if(root->data == n1 || root->data == n2) {
    return root;
}
```

If the current node itself is one of the targets:

```text
return that node upward
```

---

## Search Both Sides

```cpp
Node* leftLCA = LCA2(root->left, n1, n2);

Node* rightLCA = LCA2(root->right, n1, n2);
```

Now we ask:

```text
What came back from the left?

What came back from the right?
```

---

## Both Sides Return Something

```cpp
if(leftLCA != NULL && rightLCA != NULL) {
    return root;
}
```

This means:

```text
one target was found on the left

AND

one target was found on the right
```

Therefore the current root is where the two paths meet.

So:

```text
current root = LCA
```

---

## Only One Side Returns Something

```cpp
return leftLCA == NULL ? rightLCA : leftLCA;
```

This means:

```text
If left is NULL
→ return right

Otherwise
→ return left
```

We simply propagate the useful result upward.

---

# LCA Approach 2 Mental Model

```text
left result       right result       action

NULL              NULL               return NULL

node              NULL               return node

NULL              node               return node

node              node               return root
```

The final case:

```text
node + node
```

means:

```text
the two targets split into different subtrees

therefore current node is their LCA
```

---

# Minimum Distance Between Two Nodes

Now suppose we want the minimum distance between two nodes.

Consider:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

Suppose:

```text
n1 = 4
n2 = 6
```

The path is:

```text
4 → 2 → 1 → 3 → 6
```

Number of edges:

```text
4
```

So:

```text
minimum distance = 4
```

---

# Main Idea for Minimum Distance

First find:

```text
LCA(n1, n2)
```

Then:

```text
distance from LCA → n1

+

distance from LCA → n2
```

Therefore:

```text
Minimum Distance
=
dist(LCA, n1)
+
dist(LCA, n2)
```

---

# Finding Distance From a Node

We use:

```cpp
int dist(Node* root, int n) {

    if(root == NULL) {
        return -1;
    }

    if(root->data == n) {
        return 0;
    }

    int leftDist = dist(root->left, n);

    if(leftDist != -1) {
        return leftDist + 1;
    }

    int rightDist = dist(root->right, n);

    if(rightDist != -1) {
        return rightDist + 1;
    }

    return -1;
}
```

---

# Understanding dist()

The function returns:

```text
-1
→ target not found

0
→ current node IS the target

positive number
→ distance to target
```

Suppose the target is found:

```text
target
→ returns 0
```

Its parent receives:

```text
0
```

and returns:

```text
0 + 1 = 1
```

The parent's parent returns:

```text
1 + 1 = 2
```

So distance builds up while recursion returns upward.

---

# Why -1?

We need some value that means:

```text
"target does not exist in this subtree"
```

So we use:

```text
-1
```

because a real distance cannot be negative.

---

# Minimum Distance Code

```cpp
int minDist(Node* root, int n1, int n2) {

    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);

    int dist2 = dist(lca, n2);

    return dist1 + dist2;
}
```

Example:

```cpp
int n1 = 4;
int n2 = 6;

cout << "min dist = "
     << minDist(root, n1, n2);
```

Output:

```text
min dist = 4
```

---

# Minimum Distance Pattern

```text
n1
 \
  \
   LCA
  /
 /
n2
```

Find:

```text
LCA → n1 = dist1

LCA → n2 = dist2
```

Then:

```text
answer = dist1 + dist2
```

---

# Kth Ancestor of a Node

Suppose we have:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

For node:

```text
5
```

its ancestors are:

```text
1st ancestor → 2

2nd ancestor → 1
```

So:

```text
node = 5
K = 2
```

Answer:

```text
1
```

---

# Main Idea

This problem is similar to the `dist()` function.

We search for the target node.

When we find it:

```text
distance = 0
```

Then as recursion returns upward:

```text
parent       → distance 1

grandparent  → distance 2

...
```

When:

```text
distance == K
```

we have found the Kth ancestor.

---

# Kth Ancestor Code

```cpp
int KthAncestor(Node* root, int node, int K) {

    if(root == NULL) {
        return -1;
    }

    if(root->data == node) {
        return 0;
    }

    int leftDist =
        KthAncestor(root->left, node, K);

    int rightDist =
        KthAncestor(root->right, node, K);

    if(leftDist == -1 && rightDist == -1) {
        return -1;
    }

    int validVal =
        leftDist == -1 ? rightDist : leftDist;

    if(validVal + 1 == K) {

        cout << "Kth Ancestor : "
             << root->data << endl;
    }

    return validVal + 1;
}
```

Example:

```cpp
int node = 5;
int K = 2;

KthAncestor(root, node, K);
```

Output:

```text
Kth Ancestor : 1
```

---

# Understanding Kth Ancestor

The most important part is understanding what the recursive function returns.

```text
-1
→ target node does not exist in this subtree

0
→ current node is the target

1
→ current node is 1 edge above target

2
→ current node is 2 edges above target

3
→ current node is 3 edges above target
```

---

# Step-by-Step Example

For:

```text
node = 5
K = 2
```

Tree:

```text
        1
       /
      2
       \
        5
```

At node `5`:

```cpp
if(root->data == node) {
    return 0;
}
```

So:

```text
5 returns 0
```

Back at node `2`:

```text
validVal = 0
```

Then:

```text
validVal + 1 = 1
```

So node `2` is:

```text
1st ancestor
```

It returns:

```text
1
```

Back at node `1`:

```text
validVal = 1
```

Then:

```text
validVal + 1 = 2
```

Now:

```cpp
if(validVal + 1 == K)
```

becomes true.

Therefore:

```text
Kth Ancestor = 1
```

---

# Why validVal?

After searching:

```cpp
int leftDist = ...
int rightDist = ...
```

usually only one side contains the target.

For example:

```text
leftDist  = -1
rightDist = 2
```

We want:

```text
2
```

So:

```cpp
int validVal =
    leftDist == -1 ? rightDist : leftDist;
```

means:

```text
If left is invalid
→ use right

Otherwise
→ use left
```

---

# Kth Ancestor Recursive Pattern

```text
Find target
↓
return 0

Move upward
↓
distance + 1

If distance == K
↓
current node is Kth ancestor
```

This is another example where the useful information is generated **while recursion unwinds**.

---

# Transform to Sum Tree

A **Sum Tree transformation** changes every node so that its new value becomes the sum of all values in its original:

```text
left subtree
+
right subtree
```

The node's own original value is NOT included in its new value.

---

# Example

Original tree:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

After transformation:

```text
        20
       /  \
      9    6
     / \    \
    0   0    0
```

---

# Why Leaves Become 0

Consider node `4`.

It has:

```text
no left subtree
no right subtree
```

Therefore:

```text
sum = 0
```

So:

```text
4 → 0
```

Similarly:

```text
5 → 0

6 → 0
```

---

# Node 2

Originally:

```text
      2
     / \
    4   5
```

Everything below node `2` is:

```text
4 + 5
```

Therefore:

```text
2 → 9
```

---

# Node 3

Originally:

```text
3
 \
  6
```

Everything below node `3` is:

```text
6
```

Therefore:

```text
3 → 6
```

---

# Root Node

Originally:

```text
        1
      /   \
     2     3
    / \     \
   4   5     6
```

Everything below root is:

```text
2 + 3 + 4 + 5 + 6
```

Therefore:

```text
2 + 3 + 4 + 5 + 6 = 20
```

So:

```text
1 → 20
```

---

# The Important Difficulty

While transforming the tree, we are changing:

```cpp
root->data
```

But the parent still needs the node's **original value**.

So the recursive function needs to do two things:

```text
MODIFY
→ current node

RETURN
→ current node's OLD value
```

This is the key idea behind the lecture implementation.

---

# Transform to Sum Tree Code

```cpp
int transform(Node* root) { // O(n)

    if(root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);

    int rightOld = transform(root->right);

    int currOld = root->data;

    root->data = leftOld + rightOld;

    if(root->left != NULL) {
        root->data += root->left->data;
    }

    if(root->right != NULL) {
        root->data += root->right->data;
    }

    return currOld;
}
```

---

# Understanding transform()

This function works **bottom-up**.

The recursive calls happen first:

```cpp
int leftOld = transform(root->left);

int rightOld = transform(root->right);
```

So before changing the current node:

```text
left subtree has already been transformed

right subtree has already been transformed
```

---

# What Does transform() Return?

This is extremely important.

```cpp
return currOld;
```

The function does NOT return the transformed value.

It returns:

```text
the ORIGINAL value of the current node
```

Why?

Because the parent needs that original value.

---

# leftOld vs root->left->data

After:

```cpp
int leftOld = transform(root->left);
```

we have two different pieces of information.

```text
leftOld
```

contains:

```text
original value of the left child
```

But:

```cpp
root->left->data
```

now contains:

```text
transformed value of left child
```

which represents:

```text
sum of everything below the left child
```

Therefore:

```text
leftOld
+
root->left->data
```

gives:

```text
sum of the entire original left subtree
```

---

# Same Logic for Right Subtree

Similarly:

```text
rightOld
+
root->right->data
```

gives:

```text
sum of the entire original right subtree
```

---

# Why This Line Comes First

```cpp
root->data = leftOld + rightOld;
```

This adds the original values of the immediate children.

Then:

```cpp
if(root->left != NULL) {
    root->data += root->left->data;
}
```

adds everything originally below the left child.

And:

```cpp
if(root->right != NULL) {
    root->data += root->right->data;
}
```

adds everything originally below the right child.

Together:

```text
new root value

=

original left child
+
everything below left child
+
original right child
+
everything below right child
```

which is exactly:

```text
sum of original left subtree
+
sum of original right subtree
```

---

# Step-by-Step Transform Example

Consider:

```text
      2
     / \
    4   5
```

First recursion reaches `4`.

Node `4`:

```text
leftOld = 0
rightOld = 0
currOld = 4
```

Then:

```text
4 becomes 0
```

and returns:

```text
4
```

Node `5` does the same:

```text
5 becomes 0

returns 5
```

Now back at node `2`:

```text
leftOld  = 4
rightOld = 5
currOld  = 2
```

Then:

```cpp
root->data = leftOld + rightOld;
```

So:

```text
2 becomes:

4 + 5 = 9
```

Its children already contain:

```text
0 and 0
```

so nothing else is added.

Finally node `2` returns:

```text
2
```

its original value.

---

# Root Calculation

Eventually root `1` receives:

```text
leftOld  = 2

rightOld = 3
```

But its children have already transformed:

```text
root->left->data  = 9

root->right->data = 6
```

So:

```text
root->data
=
2 + 3
+
9
+
6
```

Therefore:

```text
root->data = 20
```

Exactly what we need.

---

# Why This is Postorder-Like

The transformation requires information from both children **before** solving the current node.

So conceptually:

```text
LEFT
↓
RIGHT
↓
ROOT
```

This is the same bottom-up structure as **Postorder Traversal**.

The general pattern is:

```cpp
solve left;

solve right;

solve current node;
```

---

# Transform to Sum Tree Complexity

Every node is visited once.

```text
Time Complexity = O(n)
```

The recursive call stack depends on tree height:

```text
Space Complexity = O(h)
```

where:

```text
h = height of tree
```

Worst-case skewed tree:

```text
O(n)
```

Balanced tree:

```text
O(log n)
```

---

# Important Patterns From These Problems

These problems introduce several recurring Binary Tree patterns.

## Pattern 1 — BFS + Extra Information

Top View:

```text
queue stores:

(node, horizontal distance)
```

Pattern:

```cpp
queue<pair<Node*, int>>
```

The queue doesn't have to store only a node.

It can store:

```text
node + additional state
```

---

## Pattern 2 — Map for Position Information

Top View:

```text
HD → node
```

The map lets us associate:

```text
some property / coordinate
→
some value
```

---

## Pattern 3 — Carry Information Downward

Kth Level:

```text
currLevel
```

When recursion goes downward:

```text
currLevel + 1
```

So information is passed:

```text
parent → child
```

---

## Pattern 4 — Return Information Upward

Examples:

```text
LCA

Distance between nodes

Kth Ancestor

Sum Tree
```

The recursive call solves a subtree and returns useful information to its parent.

Pattern:

```cpp
leftResult = function(root->left);

rightResult = function(root->right);

// use results to solve current node
```

---

## Pattern 5 — -1 Means "Not Found"

Used in:

```text
dist()

KthAncestor()
```

Pattern:

```text
-1
→ invalid / target not found

0 or greater
→ valid distance
```

---

## Pattern 6 — NULL Means "Nothing Found"

Used in recursive LCA:

```text
NULL
→ neither target found

Node*
→ useful node found
```

---

## Pattern 7 — Backtracking in Trees

Used in:

```cpp
rootToNodePath()
```

Pattern:

```cpp
path.push_back(root->data);

// explore

path.pop_back();
```

Meaning:

```text
choose

explore

if wrong
→ undo
```

---

## Pattern 8 — Bottom-Up Tree Recursion

Used heavily in:

```text
LCA

distance

Kth ancestor

Sum Tree
```

Think:

```text
Go down the tree first

↓ ↓ ↓

Base case

↑ ↑ ↑

Use returned information while coming back up
```

This is one of the most important ideas in Binary Trees.

---

# Quick Revision

## Maps

```text
map
→ stores key-value pairs

map<int, int> m;

m[key] = value

m[key]
→ access value

m.count(key)
→ check whether key exists

it.first
→ key

it.second
→ value

map keys
→ sorted
```

---

## Top View

```text
BFS
+
Horizontal Distance
+
Map
```

```text
Root  → HD = 0

Left  → HD - 1

Right → HD + 1
```

Store:

```text
first node for each HD
```

---

## Kth Level

Carry:

```text
currLevel
```

When:

```text
currLevel == K
```

print node.

---

## Lowest Common Ancestor

Approach 1:

```text
root → n1 path

root → n2 path

last common node
→ LCA
```

Approach 2:

```text
search left

search right

both non-NULL
→ current root is LCA

only one non-NULL
→ propagate it upward
```

---

## Minimum Distance

```text
LCA = LCA(n1, n2)

dist1 = dist(LCA, n1)

dist2 = dist(LCA, n2)

answer = dist1 + dist2
```

---

## Kth Ancestor

```text
target found
→ return 0

move upward
→ +1

when distance == K
→ current node is Kth ancestor
```

---

## Transform to Sum Tree

```text
New node value
=
sum of original left subtree
+
sum of original right subtree
```

Leaves:

```text
→ 0
```

Function:

```text
MODIFIES
→ node into its Sum Tree value

RETURNS
→ node's original value
```

---

# Core Tree Recursion Mental Model

When you see a Binary Tree problem, ask:

```text
1. What is my base case?

2. What do I need from the left subtree?

3. What do I need from the right subtree?

4. What should the current node do with those answers?

5. What should the current node return to its parent?
```

A huge number of Binary Tree problems eventually become:

```cpp
if(root == NULL) {
    return baseValue;
}

auto left = solve(root->left);

auto right = solve(root->right);

auto answer = combine(left, right, root);

return answer;
```

The specific meaning of:

```text
left
right
answer
```

changes from problem to problem.

But the recursive structure stays remarkably similar.