````md
# Pairs in C++

## What is a Pair?

A **pair** is an STL utility used to store **two related objects together**.

Example:

```text
start = {0, 1, 3}
end   = {9, 2, 4}
```

We can represent each activity as:

```text
(0, 9)
(1, 2)
(3, 4)
```

A pair can contain:

- Same data types → `(int, int)`
- Different data types → `(int, string)`

Pairs are defined in:

```cpp
#include <utility>
```

---

## Syntax

```cpp
pair<T1, T2> p;
```

Examples:

```cpp
pair<int, int> p1;

pair<int, string> p2;
```

---

# Initializing a Pair

### Using constructor

```cpp
pair<int, int> p(10, 20);
```

### Using braces

```cpp
pair<int, int> p{10, 20};
```

or:

```cpp
pair<int, int> p = {10, 20};
```

### Using `make_pair()`

```cpp
pair<int, int> p = make_pair(10, 20);
```

---

# Accessing Elements

A pair has two public members:

```text
first
second
```

Example:

```cpp
pair<int, int> p = {10, 20};

cout << p.first << endl;   // 10
cout << p.second << endl;  // 20
```

---

# Pair Inside Containers

Pairs are commonly stored inside other STL containers.

Example:

```cpp
vector<pair<int, int>> v;

v.push_back({1, 10});
v.push_back({2, 20});
```

Loop through them:

```cpp
for (auto p : v) {
    cout << p.first << " " << p.second << endl;
}
```

Output:

```text
1 10
2 20
```

---

# Sorting Pairs

Suppose:

```cpp
vector<pair<int, int>> v = {
    {2, 3},
    {1, 5},
    {1, 2}
};
```

We can directly sort:

```cpp
sort(v.begin(), v.end());
```

C++ sorts pairs:

```text
first → compare first values

if first values are equal
        ↓
second → compare second values
```

So:

```text
Before:

(2,3) (1,5) (1,2)

After:

(1,2) (1,5) (2,3)
```

---

# Custom Sorting of Pairs

Sometimes we don't want to sort using `first`.

For Activity Selection, we want to sort according to the **ending time**.

If:

```text
pair = {start, end}
```

then:

```text
first  = start
second = end
```

Comparator:

```cpp
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}
```

Meaning:

> Sort pairs according to their `second` value in ascending order.

---

# Simple Comparator Example

For normal integers:

```cpp
bool compare(int a, int b) {
    return a > b;
}
```

Then:

```cpp
sort(v.begin(), v.end(), compare);
```

sorts in descending order.

So the comparator basically tells `sort()`:

> **Which element should come before the other?**

---

# Pair Inside Map

A map internally works with:

```cpp
pair<const Key, Value>
```

Example:

```cpp
map<int, string> mp;

mp[1] = "A";
mp[2] = "B";
```

When looping:

```cpp
for (auto p : mp) {
    cout << p.first << " " << p.second << endl;
}
```

Here:

```text
p.first  → key
p.second → value
```

Output:

```text
1 A
2 B
```

---

# Nested Pairs

A pair can contain another pair.

```cpp
pair<int, pair<int, int>> p = {
    1,
    {2, 3}
};
```

Structure:

```text
p
│
├── first = 1
│
└── second
      │
      ├── first  = 2
      └── second = 3
```

Access:

```cpp
cout << p.first;          // 1

cout << p.second.first;   // 2

cout << p.second.second;  // 3
```

---

# Why are Pairs Useful?

Pairs are useful when we want to keep **two related values together** without creating a whole new class.

Very common in algorithms.

Examples:

```text
(start, end)       → Activity Selection

(node, weight)     → Graph

(value, index)     → Array problems

(distance, node)   → Dijkstra

(profit, deadline) → Greedy problems
```

So pairs are especially common in:

```text
Greedy Algorithms
Graphs
Priority Queues
Maps
Sorting problems
```

---

# Activity Selection Using Pairs

Previously we had:

```cpp
start = {0, 1, 2};
end   = {9, 2, 4};
```

Instead, we can combine the related values:

```text
(0,9)
(1,2)
(2,4)
```

Here:

```text
first  → starting time
second → ending time
```

We then sort by ending time because Activity Selection uses:

> **Earliest finishing activity first.**

---

## Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// Comparator:
// Sort activities according to ending time.
bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {

    vector<int> start = {0, 1, 2};
    vector<int> end   = {9, 2, 4};

    // Each pair stores:
    // {start time, end time}
    vector<pair<int, int>> activity;

    for (int i = 0; i < start.size(); i++) {
        activity.push_back(make_pair(start[i], end[i]));
    }

    cout << "Before sorting:\n";

    for (int i = 0; i < activity.size(); i++) {
        cout << "A" << i
             << ": "
             << activity[i].first
             << ", "
             << activity[i].second
             << endl;
    }

    // Sort according to ending time
    sort(activity.begin(), activity.end(), compare);

    cout << "\nSorted by ending time:\n";

    for (int i = 0; i < activity.size(); i++) {
        cout << activity[i].first
             << ", "
             << activity[i].second
             << endl;
    }

    return 0;
}
```

Output:

```text
Before sorting:

A0: 0, 9
A1: 1, 2
A2: 2, 4

Sorted by ending time:

1, 2
2, 4
0, 9
```

---

# Quick Revision

```text
PAIR
│
├── stores 2 related values
│
├── pair<T1,T2>
│
├── first
│
└── second
```

Example:

```cpp
pair<int, int> p = {10, 20};

p.first;   // 10
p.second;  // 20
```

Inside vector:

```cpp
vector<pair<int, int>> v;
```

Add:

```cpp
v.push_back({1, 10});
```

Sort normally:

```cpp
sort(v.begin(), v.end());
```

Custom sort:

```cpp
sort(v.begin(), v.end(), compare);
```

### Memory line

> **Pair = keep two related values together — `(start,end)`, `(node,weight)`, `(value,index)`, `(distance,node)`.**
````
