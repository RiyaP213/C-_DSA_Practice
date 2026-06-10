# Pointer Arithmetic

Pointer arithmetic means doing operations like `++`, `--`, `+`, and `-` on pointers.

A pointer stores an address.

```cpp
int x = 10;
int* ptr = &x;
```

Here:

```cpp
ptr
```

stores the address of `x`.

```cpp
*ptr
```

means the value at that address.

---

## Important Idea

When we do arithmetic on a pointer, it does **not** move by 1 byte normally.

It moves by the size of the data type it points to.

Example:

```cpp
int* ptr;
ptr++;
```

If `int` is 4 bytes, then `ptr++` moves forward by **4 bytes**.

If:

```cpp
char* ptr;
ptr++;
```

then `ptr++` moves forward by **1 byte**, because `char` is 1 byte.

If:

```cpp
double* ptr;
ptr++;
```

then `ptr++` moves forward by **8 bytes**, because `double` is usually 8 bytes.

---

# 1. Increment and Decrement Operators

## 1A. Increment and Decrement on Normal Pointers

A normal pointer can be incremented or decremented.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};

    int* ptr = arr; // ptr points to arr[0]

    cout << *ptr << endl; // 10

    ptr++; // move to next integer

    cout << *ptr << endl; // 20

    ptr--; // move back to previous integer

    cout << *ptr << endl; // 10

    return 0;
}
```

Explanation:

```text
ptr starts at arr[0]
ptr++ moves to arr[1]
ptr-- moves back to arr[0]
```

Since `ptr` is an `int*`, each increment moves by the size of `int`.

Usually:

```text
ptr++ means move forward by 4 bytes
ptr-- means move backward by 4 bytes
```

---

## 1B. Increment and Decrement with Arrays

An array name behaves like a pointer to the first element.

Example:

```cpp
int arr[3] = {10, 20, 30};
```

Here:

```cpp
arr
```

represents the address of the first element.

So:

```cpp
arr == &arr[0]
```

But the array name itself cannot be incremented or decremented.

This is not allowed:

```cpp
arr++; // ERROR
```

because `arr` is fixed.

Correct way:

```cpp
int* ptr = arr;
ptr++; // allowed
```

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};

    int* ptr = arr;

    cout << *ptr << endl; // 10

    ptr++;

    cout << *ptr << endl; // 20

    return 0;
}
```

Important:

```text
Array name = fixed starting address
Normal pointer = movable address holder
```

---

# 2. Addition and Subtraction

## 2A. Addition with Normal Pointers

We can add an integer to a pointer.

```cpp
ptr + 1
```

means move to the next element.

```cpp
ptr + 2
```

means move two elements forward.

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

This works because:

```cpp
*(ptr + i)
```

means:

```text
Go i elements ahead and get the value.
```

---

## 2B. Addition with Arrays

Array indexing uses pointer arithmetic internally.

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
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    cout << arr[0] << endl;       // 10
    cout << *(arr + 0) << endl;   // 10

    cout << arr[1] << endl;       // 20
    cout << *(arr + 1) << endl;   // 20

    cout << arr[2] << endl;       // 30
    cout << *(arr + 2) << endl;   // 30

    return 0;
}
```

So:

```text
arr[0] == *(arr + 0)
arr[1] == *(arr + 1)
arr[2] == *(arr + 2)
```

But remember:

```cpp
arr = arr + 1; // ERROR
```

because the array name cannot be reassigned.

This is allowed:

```cpp
int* ptr = arr;
ptr = ptr + 1;
```

because `ptr` is a normal pointer variable.

---

## 2C. Subtraction with Normal Pointers

We can subtract from a pointer.

```cpp
ptr - 1
```

means move one element backward.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[4] = {10, 20, 30, 40};

    int* ptr = arr + 3; // ptr points to arr[3]

    cout << *ptr << endl;       // 40
    cout << *(ptr - 1) << endl; // 30
    cout << *(ptr - 2) << endl; // 20
    cout << *(ptr - 3) << endl; // 10

    return 0;
}
```

---

## 2D. Subtraction with Arrays

We can use subtraction with an array name in expressions.

Example:

```cpp
int arr[4] = {10, 20, 30, 40};
```

This is allowed:

```cpp
*(arr + 3)
```

This gives:

```cpp
40
```

And this is also allowed:

```cpp
*(arr + 3 - 1)
```

This gives:

```cpp
30
```

But this is not allowed:

```cpp
arr = arr + 1; // ERROR
```

because the array name cannot be reassigned.

---

## 2E. Subtracting Two Pointers

If two pointers point inside the same array, we can subtract them.

The result tells how many elements are between them.

Example:

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

Explanation:

```text
p1 points to index 1
p2 points to index 4

p2 - p1 = 4 - 1 = 3
```

Important:

```text
Pointer subtraction gives difference in number of elements, not bytes.
```

Do not subtract pointers from different arrays.

---

# 3. Comparison of Pointers

Pointers can be compared.

## 3A. Comparing Normal Pointers

We can compare whether two pointers store the same address.

```cpp
p1 == p2
```

means both point to the same location.

```cpp
p1 != p2
```

means they point to different locations.

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

## 3B. Comparing Pointers Inside the Same Array

Pointers inside the same array can be compared using `<`, `>`, `<=`, and `>=`.

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

This works because both pointers point inside the same array.

---

## 3C. Comparing Array Name and Pointer

An array name can be compared with a pointer.

Example:

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

## 3D. Pointer Loop Using Comparison

Pointer comparison is often used to loop through an array.

Example:

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

It is used as a stopping point.

Do not dereference it:

```cpp
*(arr + 5) // BAD
```

because it is outside the array.

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
int* moves by 4 bytes usually
char* moves by 1 byte
double* moves by 8 bytes usually
```

Memory trick:

```text
Pointer arithmetic counts elements, not bytes.
```
