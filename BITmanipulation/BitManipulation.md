# Bit Manipulation (C++)

Bit manipulation means working directly with the binary representation (bits) of numbers.

A computer stores integers in binary using only `0`s and `1`s.

Example:

```text
Decimal 5 = 00000101
Decimal 3 = 00000011
```

---

# Bitwise Operators

| Operator | Name |
|----------|------|
| `&` | Bitwise AND |
| `|` | Bitwise OR |
| `^` | Bitwise XOR |
| `~` | Bitwise NOT (One's Complement) |
| `<<` | Left Shift |
| `>>` | Right Shift |

---

# Bitwise AND (`&`)

The AND operator compares corresponding bits.

It returns **1 only if both bits are 1**.

Truth Table:

| A | B | A & B |
|---|---|-------|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

It behaves similarly to multiplication.

Example:

```text
3 = 00000011
5 = 00000101
--------------
    00000001
```

```cpp
cout << (3 & 5);
```

Output

```text
1
```

---

# Bitwise OR (`|`)

**Do not confuse this with logical OR (`||`).**

The OR operator returns **1 if at least one bit is 1**.

Truth Table:

| A | B | A \| B |
|---|---|---------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

Example:

```text
3 = 00000011
5 = 00000101
--------------
    00000111
```

```cpp
cout << (3 | 5);
```

Output

```text
7
```

---

# Bitwise XOR (`^`)

XOR stands for **Exclusive OR**.

It returns **1 only when the bits are different**.

Truth Table:

| A | B | A ^ B |
|---|---|-------|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

> **Note:** `^` is **NOT** the power operator in C++. It is the Bitwise XOR operator.

Example:

```text
3 = 00000011
5 = 00000101
--------------
    00000110
```

```cpp
cout << (3 ^ 5);
```

Output

```text
6
```

Useful properties:

```text
x ^ 0 = x
x ^ x = 0
```

---

# Bitwise NOT (`~`) (One's Complement)

The NOT operator flips every bit.

```text
0 becomes 1
1 becomes 0
```

Example:

```text
6 = 00000110
```

Applying `~`

```text
11111001
```

The answer becomes

```text
-7
```

```cpp
cout << ~6;
```

Output

```text
-7
```

---

# Why does `~6 = -7`?

Integers are stored in memory using **32 bits** (usually).

For understanding, we'll use **8 bits**.

```text
6 = 00000110
```

Applying `~`

```text
11111001
```

The leftmost bit is called the **MSB (Most Significant Bit)**.

- MSB = 0 → Positive number
- MSB = 1 → Negative number

Since the MSB is 1, this represents a negative number.

To find its magnitude:

1. Take the One's Complement (flip all bits)

```text
11111001
↓

00000110
```

2. Add 1

```text
00000110
+       1
---------
00000111
```

Magnitude = 7

Therefore,

```text
11111001 = -7
```

This entire process is called **Two's Complement**.

> Positive numbers are stored normally.
>
> Negative numbers are stored using **Two's Complement**.

---

# Binary Shift Operators

There are two shift operators.

```cpp
<<
>>
```

---

# Left Shift (`<<`)

Moves every bit towards the **left**.

Zeros are added from the right.

Example:

```cpp
7 << 2
```

Binary representation:

```text
7 = 00000111
```

Shift left by 2 positions:

```text
00000111
↓

00011100
```

Decimal value:

```text
16 + 8 + 4 = 28
```

So,

```cpp
cout << (7 << 2);
```

Output

```text
28
```

### Shortcut

For non-negative numbers,

```text
a << b = a × 2^b
```

Example

```text
7 << 2

= 7 × 2²

= 7 × 4

= 28
```

---

# Right Shift (`>>`)

Moves every bit towards the **right**.

For positive numbers, zeros are inserted from the left.

Example

```cpp
28 >> 2
```

```text
28 = 00011100
```

Shift right by 2

```text
00011100
↓

00000111
```

Decimal value

```text
7
```

```cpp
cout << (28 >> 2);
```

Output

```text
7
```

### Shortcut

For non-negative numbers,

```text
a >> b = a / 2^b
```

Example

```text
28 >> 2

= 28 / 2²

= 28 / 4

= 7
```

Another example

```text
7 >> 1

= 7 / 2

= 3
```

(integer division)

---

# Complete Example

```cpp
#include <iostream>
using namespace std;

int main() {

    cout << (3 & 5) << endl;
    cout << (3 | 5) << endl;
    cout << (3 ^ 5) << endl;
    cout << (~6) << endl;

    cout << (7 << 2) << endl;
    cout << (28 >> 2) << endl;

    return 0;
}
```

Output

```text
1
7
6
-7
28
7
```

---

# Quick Revision

| Expression | Result |
|------------|--------|
| `3 & 5` | `1` |
| `3 \| 5` | `7` |
| `3 ^ 5` | `6` |
| `~6` | `-7` |
| `7 << 2` | `28` |
| `28 >> 2` | `7` |

---

# Important Points

- `&` behaves similar to multiplication.
- `|` behaves similar to addition.
- `^` means XOR, **not power**.
- `~` flips every bit.
- `|` and `||` are different operators.
- `~6 = -7` because negative numbers are stored using **Two's Complement**.
- `a << b = a × 2^b` (for non-negative numbers).
- `a >> b = a / 2^b` (for non-negative numbers).
- Shift operators work directly on the binary representation of numbers.









---

# Bit Mask

A **bit mask** is a binary number used to access, check, set, clear, or modify a particular bit of another number.

A bit mask usually contains:

- `1` at the bit position we want to access
- `0` at all other positions

Example:

```text
00000100
```

This mask targets the bit at index `2`.

Bit positions are counted from the right, starting at `0`.

```text
Bit index:  3 2 1 0
Binary:     1 1 0 1
```

---

# Check Whether a Number Is Odd or Even

The rightmost bit, also called the **least significant bit**, determines whether a number is odd or even.

- Rightmost bit is `1` → odd
- Rightmost bit is `0` → even

We can check the rightmost bit using the mask:

```text
00000001
```

Therefore, we perform:

```cpp
num & 1
```

## Odd-number example

```text
15 = 00001111
 1 = 00000001
--------------
     00000001
```

The result is `1`, so `15` is odd.

## Even-number example

```text
6 = 00000110
1 = 00000001
-------------
    00000000
```

The result is `0`, so `6` is even.

## Code

```cpp
#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    if (num & 1) {
        cout << "Odd";
    } else {
        cout << "Even";
    }

    return 0;
}
```

The condition:

```cpp
if (num & 1)
```

works because:

- any non-zero value is treated as `true`
- `0` is treated as `false`

---

# Get the i-th Bit

Getting the i-th bit means checking whether the bit at index `i` is `0` or `1`.

## Step 1: Create a bit mask

Start with:

```text
1 = 00000001
```

Move this `1` to position `i` using left shift:

```cpp
int bitMask = 1 << i;
```

Therefore:

```text
bitMask = 2^i
```

## Step 2: Use bitwise AND

```cpp
num & bitMask
```

Because the mask contains `0` everywhere except position `i`, all unrelated bits become `0`.

Only the i-th bit is checked.

---

## Example: Get bit at index 2 of 6

```text
num = 6
```

Binary representation:

```text
6 = 00000110
```

Here:

```text
i = 2
```

Create the bit mask:

```text
1 << 2
```

```text
00000001 << 2
=
00000100
```

Now perform AND:

```text
  00000110
& 00000100
------------
  00000100
```

The result is non-zero, so the bit at index `2` is `1`.

```text
Bit index:  3 2 1 0
Binary 6:   0 1 1 0
                ↑
```

Therefore:

```text
getIthBit(6, 2) = 1
```

---

## Code

```cpp
#include <iostream>
using namespace std;

int getIthBit(int num, int i) {
    int bitMask = 1 << i;

    if (num & bitMask) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    cout << getIthBit(6, 2);

    return 0;
}
```

Output:

```text
1
```

A shorter version is:

```cpp
int getIthBit(int num, int i) {
    return (num & (1 << i)) != 0;
}
```

The expression:

```cpp
(num & (1 << i)) != 0
```

returns:

- `true`, which becomes `1`, when the bit is set
- `false`, which becomes `0`, when the bit is not set

---

# Your Get i-th Bit Program

Your code follows the correct logic:

```cpp
#include <iostream>
using namespace std;

int getIthBit(int n, int i) {
    int mask = 1 << i;

    if (n & mask) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, i;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Enter the position of the bit to be checked: ";
    cin >> i;

    int bit = getIthBit(n, i);

    cout << "The " << i << "th bit of "
         << n << " is: " << bit << endl;

    return 0;
}
```

Remember that bit indexing starts from `0`.

For example, for `6`:

```text
6 = 0110
```

```text
Bit index:  3 2 1 0
Bit value:  0 1 1 0
```

Therefore:

```text
getIthBit(6, 0) = 0
getIthBit(6, 1) = 1
getIthBit(6, 2) = 1
getIthBit(6, 3) = 0
```

---

# Set the i-th Bit

Setting the i-th bit means changing the bit at position `i` to `1`.

Other bits must remain unchanged.

We use the bitwise OR operator:

```cpp
num | bitMask
```

## Why OR is used

The OR rules are:

```text
0 | 1 = 1
1 | 1 = 1
0 | 0 = 0
1 | 0 = 1
```

The mask contains:

- `1` at the position we want to set
- `0` everywhere else

Therefore:

- the targeted bit becomes `1`
- every other bit remains unchanged

---

## Example: Set bit at index 2 of 10

```text
num = 10
```

Binary representation:

```text
10 = 00001010
```

Create the mask:

```text
1 << 2 = 00000100
```

Apply OR:

```text
  00001010
| 00000100
------------
  00001110
```

```text
00001110 = 14
```

Therefore:

```text
setIthBit(10, 2) = 14
```

---

## Code

```cpp
#include <iostream>
using namespace std;

int setIthBit(int num, int i) {
    int bitMask = 1 << i;

    return num | bitMask;
}

int main() {
    cout << setIthBit(10, 2);

    return 0;
}
```

Output:

```text
14
```

---

## Another example

Set bit `0` of `6`.

```text
6 = 00000110
```

Mask:

```text
1 << 0 = 00000001
```

Apply OR:

```text
  00000110
| 00000001
------------
  00000111
```

```text
00000111 = 7
```

Therefore:

```text
setIthBit(6, 0) = 7
```

If the selected bit is already `1`, the number remains unchanged.

Example:

```text
setIthBit(6, 1)
```

```text
  00000110
| 00000010
------------
  00000110
```

The result is still `6`.

---

# Quick Revision

## Check odd or even

```cpp
num & 1
```

- non-zero → odd
- zero → even

## Create a mask for the i-th bit

```cpp
1 << i
```

## Get the i-th bit

```cpp
(num & (1 << i)) != 0
```

## Set the i-th bit

```cpp
num | (1 << i)
```

---

# Important Pattern

Most bit-manipulation operations follow two steps:

```text
1. Create the correct bit mask
2. Combine it with the number using a bitwise operator
```

| Operation | Mask | Operator |
|---|---|---|
| Check odd/even | `1` | `&` |
| Get i-th bit | `1 << i` | `&` |
| Set i-th bit | `1 << i` | `|` |