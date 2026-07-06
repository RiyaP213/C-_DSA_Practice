# C Strings (`<cstring>`)

```cpp
#include <cstring>
```

The **`<cstring>`** header provides built-in functions for working with **C-style strings** (character arrays).

A C-style string is simply a character array that ends with the null character (`'\0'`).

Example:

```cpp
char str[] = "Hello";
```

Memory:

```
+---+---+---+---+---+----+
| H | e | l | l | o | \0 |
+---+---+---+---+---+----+
```

---

# Important Rule

A character array **cannot be assigned** a new string after declaration.

❌ Incorrect

```cpp
char str1[100];

str1 = "Apna College";
```

Output

```
error: array type 'char[100]' is not assignable
```

### Why?

Arrays have a fixed memory location.

When you declare

```cpp
char str1[100];
```

100 bytes of memory are allocated.

```
str1

+---+---+---+---+---+---+---+---+...
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
```

The array name always refers to this block of memory.

Doing

```cpp
str1 = "Apna College";
```

would mean making `str1` point somewhere else.

Arrays cannot change what they point to.

Instead, copy characters **into** the existing array using `strcpy()`.

---

# 1. strcpy()

Copies one string into another.

### Syntax

```cpp
strcpy(destination, source);
```

- **destination** → where the string will be copied
- **source** → string being copied

---

## Example 1

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char str1[100];

    strcpy(str1, "Apna College");

    cout << str1 << endl;

    return 0;
}
```

Output

```
Apna College
```

---

## Example 2

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char str1[100];
    char str2[100] = "Hello World";

    strcpy(str1, str2);

    cout << str1 << endl;

    return 0;
}
```

Output

```
Hello World
```

---

### Notes

- Copies every character including the null character (`'\0'`).
- Destination array must be large enough.

---

# 2. strcat()

Concatenates (joins) two strings.

### Syntax

```cpp
strcat(str1, str2);
```

The second string is appended to the first string.

---

## Example

```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {

    char str1[100] = "Hello ";
    char str2[100] = "World";

    strcat(str1, str2);

    cout << str1 << endl;

    return 0;
}
```

Output

```
Hello World
```

---

### Notes

- `str1` is modified.
- `str1` must have enough space to hold both strings.

---

# 3. strcmp()

Compares two strings lexicographically (dictionary order).

### Syntax

```cpp
strcmp(str1, str2);
```

Returns

- Negative value
- Zero
- Positive value

---

## How does `strcmp()` compare?

It compares the strings **character by character from left to right**.

As soon as it finds the **first different character**, it stops.

It returns

```
ASCII(first different character of str1)
-
ASCII(first different character of str2)
```

It **does not continue comparing the rest of the string.**

---

## Example 1

```cpp
char str1[] = "abc";
char str2[] = "abc";

cout << strcmp(str1, str2);
```

Comparison

```
a == a
b == b
c == c
```

Output

```
0
```

Because both strings are identical.

---

## Example 2

```cpp
char str1[] = "abc";
char str2[] = "xyz";

cout << strcmp(str1, str2);
```

Comparison

```
a   x
↑
First different character
```

ASCII values

```
'a' = 97
'x' = 120
```

Calculation

```
97 - 120 = -23
```

Output

```
-23
```

It **does not compare**

```
b with y
c with z
```

because it already found the first mismatch.

---

## Example 3

```cpp
char str1[] = "xyz";
char str2[] = "abc";

cout << strcmp(str1, str2);
```

Comparison

```
x   a
↑
First different character
```

ASCII values

```
'x' = 120
'a' = 97
```

Calculation

```
120 - 97 = 23
```

Output

```
23
```

---

## Example 4

```cpp
char str1[] = "mango";
char str2[] = "xyz";

cout << strcmp(str1, str2);
```

Comparison

```
m   x
↑
First different character
```

ASCII values

```
'm' = 109
'x' = 120
```

Calculation

```
109 - 120 = -11
```

Output

```
-11
```

---

## Important Note

The actual number returned is **not important**.

For example

```
abc vs xyz  → -23
mango vs xyz → -11
```

Both simply mean

```
str1 < str2
```

Always check

```cpp
if (strcmp(str1, str2) == 0)
```

or

```cpp
if (strcmp(str1, str2) < 0)
```

or

```cpp
if (strcmp(str1, str2) > 0)
```

Do **not** check for specific values like `-23` or `23`.

---

# Summary

| Function | Purpose |
|----------|---------|
| `strcpy(dest, src)` | Copies source string into destination |
| `strcat(str1, str2)` | Appends `str2` to `str1` |
| `strcmp(str1, str2)` | Compares two strings lexicographically |

---

# Quick Revision

```cpp
#include <cstring>
```

- `strcpy()` → Copy a string.
- `strcat()` → Join two strings.
- `strcmp()` → Compare two strings.
- Character arrays **cannot** be assigned using `=` after declaration.
- `strcmp()` compares **only until the first different character** and returns the ASCII difference of those two characters.