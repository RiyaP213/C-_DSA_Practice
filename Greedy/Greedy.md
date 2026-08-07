# Greedy Algorithms

## Greedy Approach

A **Greedy Algorithm** builds a solution step by step by always choosing the option that looks best **at the current moment**.

> **Greedy = choose the local optimum at every step and hope it leads to the global optimum.**

Once we make a choice, we usually **do not go back and reconsider it**.

```text
Choose best option now
        ↓
Take it
        ↓
Move forward
        ↓
Repeat
```

Simple intuition:

If we try to score the best marks possible in every semester, hopefully by the end of university we also get the best overall result.

---

## Local Optimum vs Global Optimum

**Local Optimum** → best choice at the current step.

**Global Optimum** → best overall solution.

Example:

```text
arr = {1, 2, 5, 7, 3, 8, 6}

largest:

1 → 2 → 5 → 7 → 7 → 8 → 8

Final largest = 8
```

At every step we keep the best value we have seen so far.

---

# When Does Greedy Work?

This is the main challenge with Greedy.

A problem should satisfy:

### 1. Greedy Choice Property

> We can make the best choice now and that choice never needs to be reconsidered later.

```text
Choose → Commit → Move forward
```

### 2. Optimal Substructure

A problem has **optimal substructure** if it can be divided into smaller subproblems whose optimal solutions are part of the overall optimal solution.

```text
Optimal solution to smaller problems
                ↓
        helps build
                ↓
Optimal solution to whole problem
```

If these properties don't hold, Greedy may not work.

---

# Greedy vs Other Approaches

```text
GREEDY
Choose once → move forward
Fast, but we must prove the choice is safe


DYNAMIC PROGRAMMING
Consider different possibilities
Store results of subproblems
Safer when one greedy choice cannot be guaranteed


DIVIDE & CONQUER
Split → Solve → Merge


BACKTRACKING
Try → Undo → Try again
```

The big difference:

```text
Greedy       → choose and DON'T go back
Backtracking → choose and MAY go back
```

---

# General Greedy Structure

Most greedy problems look something like:

```text
1. Sort / prioritize data using some rule

2. Initialize answer

3. Pick the best available choice

4. If the choice is valid → take it

5. Move forward

6. Repeat
```

So often:

```text
SORT → PICK → CHECK → TAKE → REPEAT
```

The difficult part is figuring out:

> **What should I sort by / what is my greedy choice?**

---

# Classic Greedy Problems

## 1. Activity Selection

**Problem:** Select the maximum number of non-overlapping activities.

Greedy choice:

> Pick the activity that finishes earliest.

```text
Sort by earliest finish time
        ↓
Pick activity
        ↓
Pick next non-overlapping activity
```

---

## 2. Fractional Knapsack

**Problem:** Maximize the value inside a knapsack where fractions of items are allowed.

Greedy choice:

> Pick the item with the highest value / weight ratio.

```text
ratio = value / weight
```

Sort by highest ratio first.

Important:

```text
Fractional Knapsack → Greedy works ✅

0/1 Knapsack → Greedy does NOT generally work ❌
```

---

## 3. Coin Change

**Problem:** Find the minimum number of coins needed to make an amount.

Greedy choice:

> Always take the largest denomination <= remaining amount.

Example:

```text
Amount = 93

Take 50 → remaining 43
Take 20 → remaining 23
Take 20 → remaining 3
Take 2  → remaining 1
Take 1  → remaining 0
```

Important:

Greedy does **not** work for every possible coin system.

Example:

```text
Coins = {1, 3, 4}
Amount = 6

Greedy:
4 + 1 + 1 = 3 coins

Better:
3 + 3 = 2 coins
```

So we cannot blindly use Greedy.

---

## 4. Job Sequencing with Deadlines

Each job has:

```text
deadline
profit
```

Goal:

> Maximize total profit.

Greedy idea:

```text
Sort jobs by highest profit
        ↓
Schedule each job as late as possible
before its deadline
```

---

## 5. Huffman Coding

Goal:

> Minimize total encoding length.

Greedy choice:

> Always merge the two least frequent characters/nodes.

```text
Take 2 smallest frequencies
        ↓
Merge them
        ↓
Put result back
        ↓
Repeat
```

Usually uses a **Min Heap / Priority Queue**.

---

# Greedy in Graphs

## Minimum Spanning Tree (MST)

Two important greedy algorithms:

### Kruskal

> Pick the smallest edge that does NOT form a cycle.

```text
smallest edge
     ↓
cycle?

No → take it
Yes → skip it
```

### Prim

> Pick the smallest edge connecting the visited part to an unvisited node.

Both are Greedy algorithms.

---

## Cut Property

For MST:

> The smallest safe edge crossing a cut can be chosen as part of an MST.

This helps explain why the greedy choices in MST algorithms work.

---

# Dijkstra's Algorithm

Greedy choice:

> Pick the node with the minimum tentative distance.

Important:

```text
Works when edge weights >= 0
```

Negative edge weights can break Dijkstra's greedy logic.

---

# Time Complexity

Many Greedy algorithms first **sort** the data.

Sorting:

```text
O(n log n)
```

Then we usually traverse once:

```text
O(n)
```

Therefore overall:

```text
O(n log n)
```

is very common.

Space complexity depends on the problem:

```text
O(1) or O(n)
```

---

# Very Important: Greedy Must Be Justified

Just because a choice **looks best now** doesn't mean it gives the best final answer.

Whenever we use Greedy, we should be able to explain:

> **Why can I make this choice now and never regret it later?**

One common way is an **exchange argument**:

```text
Take an optimal solution

↓

Replace one of its choices
with our greedy choice

↓

Show the solution does not become worse

↓

Therefore the greedy choice is safe
```

You don't need to memorize the proof for every problem right now — just remember that **Greedy needs justification**.

---

# Quick Revision Table

| Problem | Greedy Choice |
|---|---|
| Activity Selection | Earliest finish time |
| Fractional Knapsack | Highest value/weight ratio |
| Coin Change | Largest valid coin |
| Job Sequencing | Highest profit |
| Huffman Coding | Two smallest frequencies |
| Kruskal | Smallest edge without cycle |
| Prim | Smallest edge from visited set |
| Dijkstra | Minimum tentative distance |

---

# Greedy Mind Map

```text
GREEDY

Best choice NOW
      ↓
Commit
      ↓
Don't go back
      ↓
Repeat


To work properly:

Greedy Choice Property
        +
Optimal Substructure


Common structure:

SORT / PRIORITIZE
      ↓
PICK BEST
      ↓
IS IT VALID?
      ↓
TAKE IT
      ↓
REPEAT
```

### One line to remember

> **Greedy = make the best safe choice right now, commit to it, and keep moving forward.**