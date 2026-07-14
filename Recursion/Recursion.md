# Recursion

Recursion is a programming technique where a **function calls itself** to solve a problem.

Instead of solving the whole problem at once, it solves **smaller instances of the same problem**.

---

## Definition

> Recursion is a method of solving computational problems where the solution depends on solutions to smaller instances of the same problem.

---

# Every Recursive Function Has Two Parts

## 1. Base Case

The **smallest problem** whose answer is already known.

It **stops the recursion**.

```cpp
if (n == 0) {
    return 1;
}
```

---

## 2. Recursive Case

Reduce the problem into a smaller version of itself.

```cpp
return n * factorial(n - 1);
```

---

# How to Think About Recursion

Whenever writing recursion, ask yourself:

### Step 1

**What is the smallest problem?**

Example:

```text
0! = 1
```

This becomes the base case.

### Step 2

**How can I express the current problem using a smaller problem?**

Example:

```text
n! = n × (n-1)!
```

### Step 3

Make sure every recursive call moves **towards the base case**.

Correct:

```cpp
factorial(n-1);
```

Wrong:

```cpp
factorial(n+1);
```

---

# Factorial Example

Mathematically,

```text
5! = 5 × 4 × 3 × 2 × 1
```

Recursive relation:

```text
factorial(n) = n × factorial(n-1)
```

Base case:

```text
factorial(0) = 1
```

Code:

```cpp
int factorial(int n) {
    if (n == 0)
        return 1;

    return n * factorial(n-1);
}
```

---

# Recursion in Memory (Call Stack)

Every function call is stored in **Stack Memory**.

Example:

```cpp
factorial(3);
```

Calls are made like this:

```text
Top of Stack
┌──────────────────────┐
│ factorial(0)         │ ← Base case
├──────────────────────┤
│ factorial(1)         │
├──────────────────────┤
│ factorial(2)         │
├──────────────────────┤
│ factorial(3)         │
└──────────────────────┘
Bottom of Stack
```

Once the base case is reached, functions return **backwards**.

```text
factorial(0) = 1
        ↑
factorial(1) = 1
        ↑
factorial(2) = 2
        ↑
factorial(3) = 6
```

This is called **Stack Unwinding**.

---

# Infinite Recursion

If there is **no base case**, the function keeps calling itself forever.

```cpp
void print() {
    cout << "Hello";
    print();
}
```

This eventually causes a **Stack Overflow** because stack memory becomes full.

---

# General Recursive Template

```cpp
returnType function(parameters) {

    // Base Case
    if (smallestProblem)
        return answer;

    // Recursive Case
    return function(smallerProblem);
}
```

---

# Key Points

- A recursive function calls itself.
- Every recursive function needs a **base case**.
- The base case stops recursion.
- Each recursive call should solve a **smaller problem**.
- Function calls are stored in **stack memory**.
- After reaching the base case, functions return one by one (**stack unwinding**).

---

# Quick Revision

```text
Recursion =
Current Problem
      ↓
Smaller Problem
      ↓
Smaller Problem
      ↓
Base Case
      ↓
Return Answers Back
```

### Memory Trick

> **Solve one small part, trust recursion to solve the rest.**