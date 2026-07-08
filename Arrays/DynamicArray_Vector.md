# Dynamic Memory Allocation & Vectors

---

# Why do we need Dynamic Memory Allocation?

Normally, arrays need a fixed size known **before the program starts (compile time).**

```cpp
int arr[10];
```

Sometimes we don't know the size until the user runs the program.

Example:

```cpp
int n;
cin >> n;

// Not standard C++
int arr[n];
```

Since the size is only known **during runtime**, we use **Dynamic Memory Allocation (DMA).**

---

# Dynamic Memory Allocation

Dynamic Memory Allocation allocates memory **during runtime** instead of compile time.

Syntax:

```cpp
int n;
cin >> n;

int *arr = new int[n];
```

Here,

- `arr` is a pointer.
- `new int[n]` creates an array of size `n` in heap memory.
- `arr` stores the address of the first element.

Example:

```cpp
int n;
cin >> n;

int *arr = new int[n];

for(int i=0;i<n;i++){
    cin>>arr[i];
}

for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}

delete[] arr;
```

---

# Stack vs Heap Memory

## Stack Memory

When we declare normal variables,

```cpp
int x = 5;

int arr[5];
```

they are stored in **Stack Memory**.

### Properties

- Memory allocated automatically.
- Deleted automatically when function ends.
- Faster.
- Limited memory.

---

## Heap Memory

When we use

```cpp
new
```

memory is allocated in **Heap Memory**.

Example:

```cpp
int *arr = new int[100];
```

### Properties

- Allocated manually.
- Must be deleted manually.
- Larger memory.
- Slightly slower than stack.

---

# What happens in Memory?

Normal Array

```
Stack

arr
-----------------
1
2
3
4
5
```

Everything is inside the stack.

When `main()` ends,

everything disappears automatically.

---

Dynamic Array

```
Stack

arr
 |
 |-------------

Heap

1
2
3
4
5
```

Notice:

Only the pointer is in the stack.

The actual array is inside the heap.

---

# Memory Leak

Suppose we write

```cpp
int *arr = new int[100];
```

When the function finishes,

the pointer inside the stack disappears.

But the array inside heap still exists.

Now there is **no pointer pointing to that memory.**

That memory can never be used again.

This is called a **Memory Leak.**

Effects:

- Wastes RAM
- Reduces available memory
- Slows down programs
- Can crash long-running applications

---

# Deleting Dynamic Memory

For a single variable

```cpp
int *ptr = new int;

delete ptr;
```

For an array

```cpp
int *arr = new int[10];

delete[] arr;
```

Remember:

```cpp
delete ptr;
delete[] arr;
```

NOT

```cpp
delete arr[];
```

---

# Dynamic 2D Arrays

We can also create matrices dynamically.

Instead of storing integers directly,

we first store pointers to every row.

Step 1

Create an array of row pointers.

```cpp
int **matrix = new int*[rows];
```

Memory:

```
matrix

↓

Row 0 pointer

Row 1 pointer

Row 2 pointer
```

No actual matrix exists yet.

Only row addresses are reserved.

---

Step 2

Allocate every row separately.

```cpp
for(int i=0;i<rows;i++){
    matrix[i]=new int[cols];
}
```

Memory becomes

```
matrix

↓

Row0 ---> [][][]

Row1 ---> [][][]

Row2 ---> [][][]
```

Now every row points to a dynamic array.

---

# Filling the Matrix

```cpp
int x=1;

for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){

        matrix[i][j]=x++;

    }
}
```

---

# Accessing Elements

Normal notation

```cpp
matrix[2][2];
```

Pointer arithmetic

```cpp
*(*(matrix+2)+2)
```

Explanation

```
matrix+2

↓

Go to row 2

*(matrix+2)

↓

Get address of row 2

*(matrix+2)+2

↓

Move to column 2

*(*(matrix+2)+2)

↓

Actual value
```

---

# Deleting a Dynamic 2D Array

Every row was created using `new`.

So every row must be deleted first.

```cpp
for(int i=0;i<rows;i++){
    delete[] matrix[i];
}

delete[] matrix;
```

Delete in reverse order of creation.

---

# STL (Standard Template Library)

STL provides ready-made data structures and algorithms.

Examples

- Vector
- Stack
- Queue
- Map
- Set
- Pair

---

# Vector

A vector is a **dynamic array**.

Unlike arrays,

vectors automatically increase their size whenever needed.

Include

```cpp
#include<vector>
```

Syntax

```cpp
vector<int> vec;
```

---

# Advantages over Arrays

- Dynamic size
- Automatic memory management
- No manual delete
- STL functions available
- Stored contiguously in memory

---

# Creating Vectors

Empty vector

```cpp
vector<int> vec1;
```

Initialize directly

```cpp
vector<int> vec2 = {1,2,3,4};
```

Create vector of size 10 filled with -1

```cpp
vector<int> vec3(10,-1);
```

Output

```
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
```

---

# Size vs Capacity

## Size

Number of elements currently inside vector.

```cpp
vec.size();
```

---

## Capacity

Amount of memory currently allocated.

```cpp
vec.capacity();
```

---

Example

Initially

```cpp
vector<int> v;
```

```
Size = 0
Capacity = 0
```

After

```cpp
v.push_back(1);
```

```
Size = 1

Capacity = 1
```

After

```cpp
v.push_back(2);
```

```
Size = 2

Capacity = 2
```

After

```cpp
v.push_back(3);
```

```
Size = 3

Capacity = 4
```

After

```cpp
v.push_back(4);
```

```
Size = 4

Capacity = 4
```

After

```cpp
v.push_back(5);
```

```
Size = 5

Capacity = 8
```

So capacity generally doubles whenever it becomes full.

---

# Why is push_back() O(1)?

Sometimes vector has to create a larger array and copy everything.

That copying takes O(n).

But it **doesn't happen every insertion.**

Since resizing is rare,

Average (Amortized) Time Complexity

```
O(1)
```

---

# pop_back()

Removes last element.

```cpp
v.pop_back();
```

Example

Before

```
1 2 3 4
```

After

```
1 2 3
```

Notice

```
Size decreases

Capacity stays the same
```

---

# 2D Vectors

A 2D vector is simply

**A vector whose elements are themselves vectors.**

Syntax

```cpp
vector<vector<int>> matrix;
```

Example

```cpp
vector<vector<int>> matrix={
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
```

Printing

```cpp
for(int i=0;i<matrix.size();i++){

    for(int j=0;j<matrix[i].size();j++){

        cout<<matrix[i][j]<<" ";

    }

    cout<<endl;
}
```

Output

```
1 2 3
4 5 6
7 8 9
```

---

# Memory Representation of 2D Vector

```
matrix

↓

Vector

↓

Row Vector 0 ---> 1 2 3

Row Vector 1 ---> 4 5 6

Row Vector 2 ---> 7 8 9
```

Each row is an independent vector.

---

# Advantage over 2D Arrays

2D arrays

Every row must have the same number of columns.

```
3 x 3

✔
```

2D vectors

Rows can have different sizes.

Example

```cpp
vector<vector<int>> matrix = {

    {1,2},

    {3,4,5,6},

    {7}

};
```

Perfectly valid.

These are called **Jagged Arrays.**

---

# Summary

- Normal arrays have fixed size.
- Dynamic arrays are allocated at runtime using `new`.
- Dynamic arrays are stored in heap memory.
- Heap memory must be manually deleted.
- Forgetting to delete causes memory leaks.
- `delete` is for one variable.
- `delete[]` is for arrays.
- Dynamic 2D arrays use pointer-to-pointer (`int**`).
- Vectors are dynamic arrays provided by STL.
- Vectors automatically resize.
- `size()` = elements stored.
- `capacity()` = allocated memory.
- Capacity usually doubles when full.
- `push_back()` is amortized **O(1)**.
- `pop_back()` decreases size but not capacity.
- A 2D vector is a vector of vectors.
- Unlike 2D arrays, rows in a 2D vector can have different lengths.
