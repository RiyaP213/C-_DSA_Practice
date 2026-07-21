# Backtracking

## Definition

Backtracking is a **systematic problem-solving technique** where you:

1. Build a solution step by step.
2. Stop as soon as you realise the current path cannot lead to a valid solution.
3. Undo the last choice (**backtrack**).
4. Try a different choice.

---

## When to Use Backtracking

Use backtracking when:

- You need to explore many possible choices.
- You can eliminate ("prune") choices that cannot lead to a valid solution.
- The solution space can be represented as a decision tree.

---

## Core Idea

```text
Choose
↓
Explore (Recursion)
↓
Undo (Backtrack)
```

Typical pattern:

```cpp
makeChoice();

solve();

undoChoice();
```

---

## Types of Backtracking Problems

### 1. Decision Problems

**Goal:** Determine whether **at least one valid solution exists**.

**Output:** `Yes` or `No`

Examples:

- Is there a path from source to destination?
- Can a Sudoku puzzle be solved?
- Can the target word be found in the grid?
- Is there a subset with sum = K?

Template:

```cpp
bool solve(...) {

    if (solutionFound)
        return true;

    for (every possible choice) {

        if (choice is valid) {

            makeChoice();

            if (solve(...))
                return true;

            undoChoice();
        }
    }

    return false;
}
```

---

### 2. Optimization Problems

**Goal:** Find the **best** valid solution.

Examples:

- Minimum cost path
- Shortest path
- Maximum score
- Minimum number of moves

Template:

```cpp
void solve(...) {

    if (solutionComplete) {
        bestAnswer = min(bestAnswer, currentAnswer);
        return;
    }

    for (every possible choice) {

        if (choice is valid) {

            makeChoice();

            solve(...);

            undoChoice();
        }
    }
}
```

---

### 3. Enumeration Problems

**Goal:** Find or count **all valid solutions**.

Examples:

- Print all permutations
- Print all subsets
- Count all paths from source to destination
- N-Queens (print all solutions)

Template:

```cpp
void solve(...) {

    if (solutionComplete) {
        printSolution();
        count++;
        return;
    }

    for (every possible choice) {

        if (choice is valid) {

            makeChoice();

            solve(...);

            undoChoice();
        }
    }
}
```

---

## General Pseudocode

```text
backtrack(current_state)

    if current_state is a complete solution:
        record solution
        return

    for each possible choice

        if choice is valid

            make choice

            backtrack(updated_state)

            undo choice
```

---

## Classical Backtracking Problems

- Permutations
- Combinations
- Subsets
- N-Queens
- Sudoku Solver
- Rat in a Maze
- Word Search
- Knight's Tour

---

## Backtracking vs Recursion

| Recursion | Backtracking |
|-----------|--------------|
| Solves a problem by breaking it into smaller subproblems. | Explores different choices to build a solution. |
| No need to undo work. | Must undo every choice before trying another. |
| Example: Merge Sort, Fibonacci | Example: N-Queens, Sudoku, Permutations |

---

## Key Takeaway

Backtracking follows one simple pattern:

```text
Choose
↓
Explore
↓
Undo
↓
Try another choice
```

Think of it as **DFS (Depth-First Search) on a decision tree**.

At every node:

1. Make a choice.
2. Explore recursively.
3. Undo the choice.
4. Try the next possibility.