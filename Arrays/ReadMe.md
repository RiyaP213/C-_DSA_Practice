# Arrays

An array is a **linear data structure** that stores elements of the **same data type** in **contiguous memory**.

Array elements are accessed using their **index**.

```cpp
int marks[5] = {1, 2, 3, 4, 5};
```

Indexing starts from `0`.

```cpp
marks[0]; // first element
marks[1]; // second element
marks[4]; // last element
```

---

## Creating an Array

### 1. Declare an array

```cpp
int marks[50];
```

This creates an integer array of size `50`.

---

### 2. Declare and initialize an array

```cpp
int marks[5] = {1, 2, 3, 4, 5};
```

This creates an array of size `5` and stores the given values.

---

### 3. Let C++ decide the size

```cpp
int marks[] = {1, 2, 3};
```

Here, C++ automatically decides the size as `3`.

Important: this is **not dynamic**. The size is fixed at compile time and stays the same.

---

## Size of an Array

Example:

```cpp
int marks[5] = {1, 2, 3, 4, 5};
```

Usually, an `int` takes **4 bytes**.

So:

```cpp
sizeof(marks);
```

will give:

```text
20
```

Because:

```text
5 elements × 4 bytes = 20 bytes
```

To find the number of elements in an array:

```cpp
int length = sizeof(marks) / sizeof(marks[0]);
```

This is better than:

```cpp
int length = sizeof(marks) / sizeof(int);
```

because `sizeof(marks[0])` still works even if the array type changes later.

---

## Passing Values to Functions

In C++, normal variables are passed **by value** by default.

This means a **copy** of the original variable is passed into the function.

So if we modify the variable inside the function, the original variable does not change.

Example:

```cpp
#include <iostream>
using namespace std;

void change(int x) {
    x = 100;
}

int main() {
    int a = 10;

    change(a);

    cout << a; // Output: 10

    return 0;
}
```

Here, `a` is still `10` because only a copy was changed.

---

## Passing by Reference

If we want the function to modify the original variable, we can pass by reference.

```cpp
#include <iostream>
using namespace std;

void change(int &x) {
    x = 100;
}

int main() {
    int a = 10;

    change(a);

    cout << a; // Output: 100

    return 0;
}
```

Here, the original variable changes because `x` refers to the same memory as `a`.

---

## Passing Using Pointers

We can also modify the original variable using pointers.

```cpp
#include <iostream>
using namespace std;

void change(int* x) {
    *x = 100;
}

int main() {
    int a = 10;

    change(&a);

    cout << a; // Output: 100

    return 0;
}
```

Explanation:

```cpp
&a
```

means address of `a`.

```cpp
*x
```

means value at that address.

---

## Passing Arrays to Functions

Arrays behave differently from normal variables.

When we pass an array to a function, the whole array is **not copied**.

Instead, the function receives the **address of the first element**.

These two function declarations mean almost the same thing:

```cpp
void printArray(int arr[], int size)
```

```cpp
void printArray(int* arr, int size)
```

Both mean:

```text
The function receives a pointer to the first element of the array.
```

Example:

```cpp
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int marks[5] = {1, 2, 3, 4, 5};

    printArray(marks, 5);

    return 0;
}
```

---

## Array Indexing and Pointers

Inside a function:

```cpp
arr[0]
arr[1]
arr[2]
```

is easier to write than:

```cpp
*arr
*(arr + 1)
*(arr + 2)
```

But they are related.

```cpp
arr[i] == *(arr + i)
```

So:

```cpp
arr[0] == *(arr + 0)
arr[1] == *(arr + 1)
arr[2] == *(arr + 2)
```

---

## Modifying Arrays Inside Functions

Since arrays are passed as a pointer to the first element, changes made inside the function affect the original array.

Example:

```cpp
#include <iostream>
using namespace std;

void changeArray(int arr[], int size) {
    arr[0] = 100;
}

int main() {
    int marks[3] = {1, 2, 3};

    changeArray(marks, 3);

    cout << marks[0]; // Output: 100

    return 0;
}
```

The original array changed because the function accessed the same array memory.

---

## Important: `sizeof` Inside a Function

If we use `sizeof` on an array inside `main()`, it gives the full size of the array in bytes.

Example:

```cpp
int marks[5] = {1, 2, 3, 4, 5};

cout << sizeof(marks); // 20
```

But inside a function, the array becomes like a pointer.

So this will not give the full array size:

```cpp
void printArray(int arr[]) {
    cout << sizeof(arr); // gives size of pointer, not full array
}
```

That is why we should always pass the size separately:

```cpp
void printArray(int arr[], int size)
```

---

## My Confusion / Important Reminder

I was confused because normal variables are passed by value, but arrays behave differently.

Clear version:

```text
Normal variables:
A copy is passed by default.

Arrays:
The whole array is not copied.
The function receives the address of the first element.
So changes to array elements inside the function affect the original array.
```

Simple rule:

```text
Normal variable → passed by value by default
Array → passed as a pointer to the first element
```

That is why we always pass the array size separately into the function.
