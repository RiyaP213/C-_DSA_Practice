# Object-Oriented Programming (OOP)

Object-Oriented Programming (OOP) is a programming paradigm where we model real-world entities as **objects**.

The two main concepts are:

- **Class** → Blueprint or template.
- **Object** → An actual instance created from the class.

---

## Class

A class defines:

- **Properties (Attributes/Data Members)** → Data an object stores.
- **Member Functions (Methods)** → Actions an object can perform.

Example:

```cpp
class Student {
public:
    string name;
    int age;

    void study() {
        cout << name << " is studying";
    }
};
```

Here,

Properties:

```text
name
age
```

Member Function:

```text
study()
```

---

## Object

Objects are created from a class.

```cpp
Student s1;
Student s2;
Student s3;
```

Each object has its **own copy of the data**.

Example:

```text
s1.name = "Riya"
s2.name = "Alex"
s3.name = "John"
```

Although the data is different, every object can use the same member functions.

```cpp
s1.study();
s2.study();
s3.study();
```

---

## Real-Life Analogy

```text
Blueprint  → Class
House      → Object

Recipe     → Class
Cake       → Object

Cookie Cutter → Class
Cookies       → Objects

Car Design → Class
Cars       → Objects
```

---

# C++ Strings

Unlike C-style strings (`char[]`), C++ provides a built-in **String class**.

```cpp
#include <string>
```

The `string` class is part of the **Standard Template Library (STL)**.

When we write

```cpp
string name = "Riya";
```

we are actually creating an **object** of the `string` class.

Just like:

```cpp
Student s1;
```

creates an object of the `Student` class,

```cpp
string name;
```

creates an object of the predefined `string` class.

---

## Why is `string` a Class?

The `string` class already contains:

### Data (Properties)

- Characters
- Current length
- Capacity (allocated memory)

### Member Functions

Examples:

```cpp
length()
size()
substr()
find()
push_back()
pop_back()
append()
clear()
empty()
```

These functions are already written by the C++ library, so we simply use them.

Example:

```cpp
string name = "Riya";

cout << name.length();
```

Output

```
4
```

We never wrote a `length()` function—it already exists inside the `string` class.

---

# Advantages of C++ Strings over C Strings

| C String (`char[]`) | C++ `string` |
|----------------------|--------------|
| Fixed size | Dynamic size |
| Uses `'\0'` | Null terminator handled internally |
| Cannot assign using `=` after declaration | Can assign using `=` |
| Uses `strcpy()`, `strcat()`, `strcmp()` | Uses built-in member functions and operators |
| Less convenient | Easier and safer to use |

---

## Features of C++ Strings

- Objects of the predefined `string` class.
- Dynamic (size can change during runtime).
- Supports member functions.
- Supports operators like `+`, `==`, `<`, `>`, etc.
- Characters are stored contiguously in memory.

---

## Example

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {

    string first = "Hello";
    string second = " World";

    cout << first + second << endl;

    return 0;
}
```

Output

```
Hello World
```

---

# Key Takeaways

- **Class** = Blueprint.
- **Object** = Instance created from a class.
- A class contains **properties** and **member functions**.
- `string` is a predefined **class** in the C++ Standard Library.
- Every variable of type `string` is an **object** of the `string` class.
- We use the object's member functions (e.g., `length()`, `find()`, `substr()`) to work with strings easily.





# Taking Input in C++ Strings

## 1. Using `cin`

```cpp
string str;
cin >> str;

cout << str;
```

### Example

Input

```
Hello
```

Output

```
Hello
```

---

### Problem with `cin`

`cin` stops reading as soon as it encounters a whitespace character.

Whitespace includes:

- Space `' '`
- Tab `'\t'`
- Newline `'\n'`

Example

```cpp
string str;
cin >> str;
```

Input

```
Apna College
```

Output

```
Apna
```

Only `"Apna"` is stored because `cin` stops at the first space.

---

## 2. Using `getline()`

To read an entire line (including spaces), use `getline()`.

Syntax

```cpp
getline(cin, str);
```

Example

```cpp
string str;

getline(cin, str);

cout << str;
```

Input

```
Apna College
```

Output

```
Apna College
```

Unlike `cin`, `getline()` continues reading until it encounters a newline (`'\n'`).

---

## 3. Using a Delimiter

By default, `getline()` stops at a newline.

You can specify your own stopping character (delimiter).

Syntax

```cpp
getline(cin, str, '$');
```

Example

```cpp
string str;

getline(cin, str, '$');

cout << str;
```

Input

```
Hi, Hello $ Namaste
```

Output

```
Hi, Hello
```

The `$` is **not stored** in the string.

Everything after `$` remains in the input buffer.

---

# Accessing Characters

Since strings are stored contiguously in memory, each character has an index.

Example

```cpp
string str = "Hello";
```

|Index|0|1|2|3|4|
|-----|--|--|--|--|--|
|Char|H|e|l|l|o|

---

## Using `[]`

```cpp
cout << str[0];
```

Output

```
H
```

Example

```cpp
cout << str[1];
cout << str[2];
```

Output

```
e
l
```

---

## Using `.at()`

```cpp
cout << str.at(2);
```

Output

```
l
```

`.at()` and `[]` both access characters by index.

Example

```cpp
cout << str[2];
cout << str.at(2);
```

Output

```
l
l
```

> **Difference**
>
> - `[]` performs no bounds checking.
> - `.at()` checks whether the index is valid and throws an exception if it isn't.
> - Therefore, `.at()` is generally safer.

---

# Traversing a String

## Method 1 - Using a Normal `for` Loop

```cpp
string str = "Apna";

for(int i = 0; i < str.length(); i++) {
    cout << str[i] << " ";
}
```

Output

```
A p n a
```

---

## Method 2 - Using a Range-based (for-each) Loop

Syntax

```cpp
for(char ch : str) {
    // use ch
}
```

Example

```cpp
string str = "Apna";

for(char ch : str) {
    cout << ch << " ";
}
```

Output

```
A p n a
```

### How it works

Think of it as:

```
Take each character from the string,
store it in variable ch,
execute the loop body.
```

Iteration:

```
ch = 'A'
ch = 'p'
ch = 'n'
ch = 'a'
```

No indexing is required.

---

# Common Member Functions

## 1. `length()`

Returns the number of characters in the string.

```cpp
string str = "Apna College!";

cout << str.length();
```

Output

```
13
```

---

## 2. `substr(startIndex, size)`

Returns a substring starting from `startIndex`.

Syntax

```cpp
str.substr(startIndex, size)
```

Example

```cpp
string str = "Helloworld";

cout << str.substr(1, 5);
```

Output

```
ellow
```

Explanation

```
H e l l o w o r l d
0 1 2 3 4 5 6 7 8 9

Start at index 1 → e

Take 5 characters

e l l o w
```

---

## 3. `find()`

Searches for the first occurrence of a word or character.

Syntax

```cpp
str.find("word");
```

Example

```cpp
string str = "I love coding in C++ & Java";

cout << str.find("C++");
```

Output

```
17
```

This means `"C++"` begins at index **17**.

---

### Starting the Search from an Index

Syntax

```cpp
str.find("word", startIndex);
```

Example

```cpp
string str = "I love C++ and C++";

cout << str.find("C++", 10);
```

Output

```
15
```

The search starts from index `10`, ignoring earlier occurrences.

---

## What if the Word Doesn't Exist?

Example

```cpp
string str = "I love C++";

cout << str.find("Python");
```

Output (may look like)

```
18446744073709551615
```

This looks strange, but it is actually **`string::npos`**.

`find()` does **NOT** return an `int`.

It returns a special unsigned integer type:

```cpp
string::size_type
```

When the word is **not found**, it returns

```cpp
string::npos
```

which represents the **largest possible unsigned integer**.

On a 64-bit computer, that value is

```
18446744073709551615
```

---

### Why is it `-1`?

Internally,

```
string::npos == (size_t)-1
```

Since `size_t` is **unsigned**, the binary representation of `-1`

```
111111111111111111111111...
```

is interpreted as the **largest unsigned number**, giving

```
18446744073709551615
```

If converted to a signed integer, it becomes

```
-1
```

So conceptually,

```
Not found
        ↓
string::npos
        ↓
(size_t)-1
        ↓
Largest unsigned value
```

---

### Correct Way to Check

Never compare with `-1`.

Instead use

```cpp
if(str.find("Python") == string::npos)
{
    cout << "Not Found";
}
```

This is the standard and safest approach in C++.



Note:
Whenever you write object.function(), you are calling a member function of that object's class.

string str = "Hello";

str.length();   // member function
str.find("ll"); // member function
str.substr(1,3);// member function

Here, str is an object of the string class, and length(), find(), and substr() are member functions belonging to that class.