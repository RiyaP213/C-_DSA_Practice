# Pointer Arithmetic

Pointer arithmetic means moving a pointer through memory using operations like:

```text
++
--
+
-
comparison
```

A pointer stores a **memory address**.

Memory addresses are usually shown in **hexadecimal**, like:

```text
0x01ef100
0x01ef104
0x01ef108
```

The exact address can change every time the program runs, but the idea is the same.

---

## Big Idea

Pointer arithmetic moves by **elements**, not by raw bytes.

Example:

```cpp
int arr[3] = {10, 20, 30};
```

If `int` takes 4 bytes, memory may look like this:

```text
Value:      10          20          30
Index:      arr[0]      arr[1]      arr[2]
Address:    0x01ef100   0x01ef104   0x01ef108
```

So if:

```cpp
int* ptr = arr;
```

then:

```text
ptr points to arr[0]      → 0x01ef100
ptr + 1 points to arr[1]  → 0x01ef104
ptr + 2 points to arr[2]  → 0x01ef108
```

Even though we write:

```cpp
ptr + 1
```

the address moves by **4 bytes** because `ptr` is an `int*`.

So:

```text
int*    moves by 4 bytes usually
char*   moves by 1 byte
double* moves by 8 bytes usually
```

Main rule:

```text
Pointer arithmetic counts elements, not bytes.
```

---

# Pointer vs Array Name

Pointers and arrays are related, but they are not exactly the same.

```text
Pointer:
A variable that stores an address.
It can be moved and reassigned.

Array name:
Represents the starting address of the array.
It is fixed and cannot be reassigned.
```

Example:

```cpp
int arr[3] = {10, 20, 30};

int* ptr = arr;
```

Here:

```cpp
ptr
```

and:

```cpp
arr
```

both point to the first element.

But:

```cpp
ptr++; // allowed
arr++; // error
```

Because `ptr` is a normal pointer variable, but `arr` is a fixed array name.

---

# 1. Increment and Decrement

## Normal Pointer

A normal pointer can move forward and backward.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};

    int* ptr = arr; // ptr points to arr[0]

    cout << *ptr << endl; // 10

    ptr++; // moves to arr[1]

    cout << *ptr << endl; // 20

    ptr--; // moves back to arr[0]

    cout << *ptr << endl; // 10

    return 0;
}
```

What happens:

```text
ptr starts at arr[0]
ptr++ moves to arr[1]
ptr-- moves back to arr[0]
```

If the address of `arr[0]` is:

```text
0x01ef100
```

then:

```text
ptr++ moves from 0x01ef100 to 0x01ef104
```

because `int` usually takes 4 bytes.

So:

```text
ptr++ does not mean address + 1 byte.
ptr++ means move to the next element.
```

---

## Array Name

The array name cannot be incremented or decremented.

```cpp
int arr[3] = {10, 20, 30};

arr++; // error
arr--; // error
```

Why?

Because `arr` is the fixed starting address of the array.

But this is allowed:

```cpp
int* ptr = arr;
ptr++;
```

Key difference:

```text
Pointer can move.
Array name cannot move.
```

---

# 2. Addition

## Normal Pointer

We can add numbers to a pointer.

```cpp
ptr + 1
```

means move 1 element forward.

```cpp
ptr + 2
```

means move 2 elements forward.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    int* ptr = arr;

    cout << *ptr << endl;       // 10
    cout << *(ptr + 1) << endl; // 20
    cout << *(ptr + 2) << endl; // 30
    cout << *(ptr + 3) << endl; // 40

    return 0;
}
```

Memory picture if `arr[0]` starts at `0x01ef100`:

```text
arr[0] = 10 → 0x01ef100
arr[1] = 20 → 0x01ef104
arr[2] = 30 → 0x01ef108
arr[3] = 40 → 0x01ef10c
```

So:

```text
ptr + 1 → next int → 4 bytes ahead
ptr + 2 → two ints ahead → 8 bytes ahead
ptr + 3 → three ints ahead → 12 bytes ahead
```

---

## Array Name

Array indexing uses pointer arithmetic.

These are the same:

```cpp
arr[i]
```

and:

```cpp
*(arr + i)
```

Example:

```cpp
int arr[4] = {10, 20, 30, 40};

cout << arr[2];      // 30
cout << *(arr + 2);  // 30
```

So:

```text
arr[0] == *(arr + 0)
arr[1] == *(arr + 1)
arr[2] == *(arr + 2)
```

But this is not allowed:

```cpp
arr = arr + 1; // error
```

because the array name cannot be reassigned.

This is allowed:

```cpp
int* ptr = arr;
ptr = ptr + 1;
```

because `ptr` is a normal pointer.

---

# 3. Subtraction

## Normal Pointer

We can subtract from a pointer.

```cpp
ptr - 1
```

means move 1 element backward.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    int* ptr = arr + 3; // points to arr[3]

    cout << *ptr << endl;       // 40
    cout << *(ptr - 1) << endl; // 30
    cout << *(ptr - 2) << endl; // 20
    cout << *(ptr - 3) << endl; // 10

    return 0;
}
```

Memory idea:

```text
If ptr points to 0x01ef10c,
ptr - 1 points to 0x01ef108.
```

Because it moves back by one `int`, usually 4 bytes.

---

## Array Name

We can use subtraction in expressions.

```cpp
int arr[4] = {10, 20, 30, 40};

cout << *(arr + 3);     // 40
cout << *(arr + 3 - 1); // 30
```

But we cannot change the array name itself.

```cpp
arr = arr - 1; // error
```

---

## Subtracting Two Pointers

If two pointers point inside the same array, we can subtract them.

The result tells how many **elements** are between them.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    int* p1 = &arr[1]; // points to 20
    int* p2 = &arr[4]; // points to 50

    cout << p2 - p1 << endl; // 3

    return 0;
}
```

Why output is `3`:

```text
p1 points to index 1
p2 points to index 4

4 - 1 = 3
```

Important:

```text
Pointer subtraction gives element difference, not byte difference.
```

Only subtract pointers from the same array.

---

# 4. Comparison

## Comparing Normal Pointers

Pointers can be compared.

```cpp
p1 == p2
```

means both point to the same address.

```cpp
p1 != p2
```

means they point to different addresses.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;

    int* p1 = &a;
    int* p2 = &a;
    int* p3 = &b;

    cout << (p1 == p2) << endl; // 1, true
    cout << (p1 == p3) << endl; // 0, false

    return 0;
}
```

---

## Comparing Pointers in the Same Array

Pointers inside the same array can be compared using:

```cpp
<
>
<=
>=
```

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    int* start = &arr[0];
    int* end = &arr[3];

    if (start < end) {
        cout << "start comes before end" << endl;
    }

    return 0;
}
```

This works because both pointers belong to the same array.

---

## Comparing Array Name and Pointer

An array name can be compared with a pointer.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};

    int* ptr = arr;

    if (ptr == arr) {
        cout << "ptr points to the first element of arr" << endl;
    }

    return 0;
}
```

Here:

```cpp
ptr == arr
```

is true because both represent the address of `arr[0]`.

---

## Pointer Loop Using Comparison

Pointer comparison is often used to loop through an array.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    int* ptr = arr;
    int* end = arr + 5;

    while (ptr < end) {
        cout << *ptr << " ";
        ptr++;
    }

    return 0;
}
```

Output:

```text
10 20 30 40 50
```

Explanation:

```text
ptr starts at arr[0]
end points one step after the last element
keep printing while ptr < end
move ptr forward each time
```

Important:

```cpp
arr + 5
```

points one step after the last element.

It is only used as a stopping point.

Do not dereference it:

```cpp
*(arr + 5); // bad
```

because it is outside the array.

---

# Difference Table

| Operation       | Normal Pointer        | Array Name                           |
| --------------- | --------------------- | ------------------------------------ |
| `ptr++`         | Allowed               | `arr++` not allowed                  |
| `ptr--`         | Allowed               | `arr--` not allowed                  |
| `ptr + 1`       | Allowed               | `arr + 1` allowed in expressions     |
| `ptr = ptr + 1` | Allowed               | `arr = arr + 1` not allowed          |
| `ptr - 1`       | Allowed               | `arr - 1` allowed in expressions     |
| `ptr = ptr - 1` | Allowed               | `arr = arr - 1` not allowed          |
| `p2 - p1`       | Allowed if same array | Works with addresses from same array |
| `ptr == arr`    | Allowed               | Compares addresses                   |
| `ptr < end`     | Allowed if same array | Used in pointer loops                |

---

# Summary

## Pointer Arithmetic Rules

```text
ptr++       → move to next element
ptr--       → move to previous element
ptr + i     → move i elements forward
ptr - i     → move i elements backward
p2 - p1     → number of elements between two pointers
```

---

## Normal Pointer vs Array Name

```text
Normal pointer:
- Can be incremented
- Can be decremented
- Can be reassigned
- Can use pointer arithmetic

Array name:
- Can be used in pointer arithmetic expressions
- Cannot be incremented
- Cannot be decremented
- Cannot be reassigned
```

---

## Most Important Formula

```cpp
arr[i] == *(arr + i)
```

This means array indexing is based on pointer arithmetic.

---

## My Reminder

Pointer arithmetic moves by **elements**, not by raw bytes.

Example:

```text
int arr[3] = {10, 20, 30};

If arr[0] is at 0x01ef100:

arr[0] → 0x01ef100
arr[1] → 0x01ef104
arr[2] → 0x01ef108
```

Even though the address jumps by 4 bytes, we write:

```cpp
ptr++;
```

because `ptr++` means:

```text
go to the next element
```

not:

```text
go to the next byte
```

Memory trick:

```text
Pointer arithmetic counts elements, not bytes.
```
