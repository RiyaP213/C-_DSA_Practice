# Object-Oriented Programming in C++

Object-Oriented Programming, or **OOP**, is a way of organising code around **objects**.

An object contains:

- **Data** that describes it
- **Functions** that define what it can do

A class is the blueprint.  
An object is the real item created from that blueprint.

---

# One Big Realistic Example

Hi, let us look at one large and realistic piece of code. We will use it to understand the major OOP concepts in C++.

We will build a small banking system containing:

- Classes and objects
- Access modifiers
- Encapsulation
- Constructors
- Copy constructors
- Destructors
- Inheritance
- Polymorphism
- Abstraction
- Static members
- Friend functions
- Friend classes
- Operator overloading

```cpp
#include <iostream>
#include <string>

using namespace std;

// We declare Bank here because BankAccount refers to it
// before the complete Bank class is written.
class Bank;

// Abstract base class
class BankAccount {
private:
    // Private data cannot be directly accessed outside this class.
    string accountNumber;
    double balance;

protected:
    // Protected data can be accessed inside this class
    // and inside classes derived from this class.
    string ownerName;

    // Derived account classes may safely update the balance
    // using this protected function.
    void setBalance(double newBalance) {
        balance = newBalance;
    }

public:
    // Shared by every BankAccount object.
    static int totalAccounts;

    // Default constructor
    BankAccount() {
        accountNumber = "Not Assigned";
        ownerName = "Unknown";
        balance = 0;

        totalAccounts++;
    }

    // Parameterised constructor
    BankAccount(
        string accNo,
        string owner,
        double initialBalance
    ) {
        accountNumber = accNo;
        ownerName = owner;
        balance = initialBalance;

        totalAccounts++;
    }

    // Copy constructor
    BankAccount(const BankAccount& other) {
        accountNumber = other.accountNumber;
        ownerName = other.ownerName;
        balance = other.balance;

        totalAccounts++;
    }

    // Virtual destructor
    virtual ~BankAccount() {
        totalAccounts--;
    }

    // Getter
    string getAccountNumber() const {
        return accountNumber;
    }

    // Getter
    double getBalance() const {
        return balance;
    }

    // Setter
    void setOwnerName(string newOwnerName) {
        if (!newOwnerName.empty()) {
            ownerName = newOwnerName;
        }
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
    }

    // Pure virtual function
    // Every concrete derived account must define its own version.
    virtual void calculateMonthlyBenefit() = 0;

    // Virtual function
    virtual void displayAccountType() const {
        cout << "General Bank Account\n";
    }

    // Function overloading
    void display() const {
        cout << "Owner: " << ownerName << '\n';
        cout << "Balance: " << balance << '\n';
    }

    void display(bool showAccountNumber) const {
        cout << "Owner: " << ownerName << '\n';
        cout << "Balance: " << balance << '\n';

        if (showAccountNumber) {
            cout << "Account Number: "
                 << accountNumber
                 << '\n';
        }
    }

    // Operator overloading
    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }

    // The Bank class may access private members.
    friend class Bank;
};

// Static members are declared inside the class
// but defined outside the class.
int BankAccount::totalAccounts = 0;

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(
        string accNo,
        string owner,
        double initialBalance,
        double rate
    ) : BankAccount(accNo, owner, initialBalance) {
        interestRate = rate;
    }

    void calculateMonthlyBenefit() override {
        double interest =
            getBalance() * interestRate / 100;

        setBalance(getBalance() + interest);
    }

    void displayAccountType() const override {
        cout << "Savings Account\n";
    }
};

class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(
        string accNo,
        string owner,
        double initialBalance,
        double limit
    ) : BankAccount(accNo, owner, initialBalance) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        double availableAmount =
            getBalance() + overdraftLimit;

        if (amount > 0 && amount <= availableAmount) {
            setBalance(getBalance() - amount);
        }
    }

    void calculateMonthlyBenefit() override {
        cout << "No monthly interest for current account\n";
    }

    void displayAccountType() const override {
        cout << "Current Account\n";
    }
};

class Bank {
public:
    void inspectAccount(const BankAccount& account) {
        // Bank is a friend class, so it can directly access
        // private members of BankAccount.
        cout << "Account Number: "
             << account.accountNumber
             << '\n';

        cout << "Balance: "
             << account.balance
             << '\n';
    }
};

// Friend function example
class LoanApplication {
private:
    double requestedAmount;

public:
    LoanApplication(double amount) {
        requestedAmount = amount;
    }

    friend void reviewLoan(
        const LoanApplication& loan
    );
};

void reviewLoan(const LoanApplication& loan) {
    cout << "Reviewing loan of: "
         << loan.requestedAmount
         << '\n';
}

int main() {
    SavingsAccount savings(
        "SA101",
        "Riya",
        1000,
        5
    );

    CurrentAccount current(
        "CA202",
        "Alex",
        500,
        300
    );

    savings.deposit(200);
    savings.calculateMonthlyBenefit();

    current.withdraw(700);

    savings.display(true);
    current.display();

    if (savings > current) {
        cout << "Savings account has a higher balance\n";
    }

    // Base-class pointer used for runtime polymorphism
    BankAccount* accountPointer;

    accountPointer = &savings;
    accountPointer->displayAccountType();

    accountPointer = &current;
    accountPointer->displayAccountType();

    cout << "Total accounts: "
         << BankAccount::totalAccounts
         << '\n';

    Bank bank;
    bank.inspectAccount(savings);

    LoanApplication loan(5000);
    reviewLoan(loan);

    return 0;
}
```

---

# 1. Classes and Objects

## Class

A **class** is a blueprint or template used to create objects.

A class can define:

- Data members
- Member functions
- Constructors
- Destructors
- Access rules

Example:

```cpp
class Student {
public:
    string name;
    int age;

    void study() {
        cout << name << " is studying\n";
    }
};
```

The class describes what every `Student` object should contain.

---

## Object

An **object** is an actual instance of a class.

```cpp
Student s1;
Student s2;
```

Here:

- `Student` is the class
- `s1` is an object
- `s2` is another object

Each object receives its own copy of non-static data members.

```cpp
s1.name = "Riya";
s1.age = 22;

s2.name = "Alex";
s2.age = 20;
```

Both objects follow the same blueprint, but their values can be different.

---

# 2. Access Modifiers

Access modifiers decide where class members may be used.

The three main access modifiers are:

1. `public`
2. `private`
3. `protected`

Important:

> Members of a C++ `class` are private by default.

```cpp
class Example {
    int value;
};
```

Here, `value` is private.

Members of a C++ `struct` are public by default.

```cpp
struct Example {
    int value;
};
```

Here, `value` is public.

---

## Public

Public members may be accessed from outside the class through an object.

```cpp
class Person {
public:
    string name;
};
```

```cpp
Person person;
person.name = "Riya";
```

### Real use case

Use `public` for operations that users of the class are allowed to perform.

For a bank account:

```cpp
account.deposit(500);
account.withdraw(200);
account.getBalance();
```

These are valid actions that outside code should be able to request.

---

## Private

Private members may only be directly accessed inside the class itself.

```cpp
class BankAccount {
private:
    double balance;
};
```

Outside code cannot do this:

```cpp
BankAccount account;

// Error because balance is private
account.balance = -1000000;
```

Instead, the class controls access through public member functions.

```cpp
class BankAccount {
private:
    double balance;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
};
```

### Real use cases

Private members are useful for protecting:

- Bank balances
- Passwords
- PINs
- Salaries
- Security tokens
- Internal IDs
- Medical information
- Important program states

The purpose is not merely to hide data. The purpose is to stop outside code from placing the object into an invalid state.

---

## Protected

Protected members may be accessed:

- Inside the class itself
- Inside classes derived from that class

They cannot normally be accessed directly through an object from outside.

```cpp
class BankAccount {
protected:
    string ownerName;
};
```

```cpp
class SavingsAccount : public BankAccount {
public:
    void printOwner() {
        cout << ownerName;
    }
};
```

The derived class may use `ownerName`, but normal outside code cannot directly modify it.

### Real use case

Suppose a base class stores data needed by its child classes:

```cpp
class Employee {
protected:
    int employeeId;
};
```

Derived classes such as `Manager`, `Engineer`, and `Trader` may need the ID internally, while general outside code should not freely change it.

---

# 3. Getters and Setters

A getter reads private data.

A setter changes private data in a controlled way.

```cpp
class BankAccount {
private:
    double balance;

public:
    double getBalance() const {
        return balance;
    }

    void setBalance(double newBalance) {
        if (newBalance >= 0) {
            balance = newBalance;
        }
    }
};
```

---

## Why not make everything public?

If data is public, outside code may freely assign invalid values.

```cpp
account.balance = -5000;
```

If the value is private, a setter can apply validation.

```cpp
account.setBalance(-5000);
```

The function can reject the invalid balance.

---

## Getter

```cpp
double getBalance() const {
    return balance;
}
```

The `const` after the function means:

> This function promises not to modify the object.

It is useful for functions that only read data.

---

## Setter

```cpp
void setBalance(double amount) {
    if (amount >= 0) {
        balance = amount;
    }
}
```

A setter can:

- Validate input
- Reject invalid values
- Apply business rules
- Record changes
- Trigger additional actions
- Protect the internal state

---

# The Four Main Pillars of OOP

The four main pillars of OOP are:

1. Encapsulation
2. Inheritance
3. Polymorphism
4. Abstraction

---

# 4. Encapsulation

Encapsulation means:

> Wrapping data and the functions related to that data together inside a class, while controlling access to the data.

Example:

```cpp
class BankAccount {
private:
    double balance;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};
```

The `balance` and the functions that operate on it are kept together.

Encapsulation uses:

- Classes
- Objects
- Private members
- Protected members
- Public methods
- Getters
- Setters

---

## Why encapsulation matters

Without encapsulation:

```cpp
account.balance = -999999;
```

With encapsulation:

```cpp
account.deposit(500);
account.withdraw(200);
```

The class controls what is valid.

---

## Intuitive example

Think of a vending machine.

You can:

- Insert money
- Choose an item
- Collect the item

You do not directly modify:

- Internal wiring
- Coin counters
- Item-release motors
- Internal software

The machine exposes a public interface and hides its internal implementation.

That is encapsulation.

---

# 5. Constructors

A constructor is a special member function that runs automatically when an object is created.

Its main purpose is to initialise the object.

Constructor rules:

- It has the same name as the class
- It has no return type
- It runs automatically
- It may accept parameters
- It may be overloaded

---

## Default Constructor

A default constructor takes no arguments.

```cpp
class Student {
public:
    string name;
    int age;

    Student() {
        name = "Unknown";
        age = 0;
    }
};
```

```cpp
Student student;
```

When `student` is created, the constructor automatically sets:

```text
name = "Unknown"
age = 0
```

---

## Parameterised Constructor

A parameterised constructor accepts values.

```cpp
class Student {
public:
    string name;
    int age;

    Student(string n, int a) {
        name = n;
        age = a;
    }
};
```

```cpp
Student student("Riya", 22);
```

Now the object is immediately created with meaningful values.

---

## Constructor Initialiser List

A constructor initialiser list directly initialises members.

```cpp
class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a)
        : name(n), age(a) {
    }
};
```

This is generally cleaner and often more efficient than assigning values inside the constructor body.

Initialiser lists are required for:

- `const` data members
- Reference data members
- Base-class constructors
- Objects stored as class members when they have no default constructor

---

## Copy Constructor

A copy constructor creates a new object from an existing object.

Syntax:

```cpp
ClassName(const ClassName& other) {
    // Copy members
}
```

Example:

```cpp
class Student {
public:
    string name;
    int age;

    Student(string n, int a)
        : name(n), age(a) {
    }

    Student(const Student& other) {
        name = other.name;
        age = other.age;
    }
};
```

```cpp
Student s1("Riya", 22);
Student s2 = s1;
```

`s2` is created using the values stored in `s1`.

The parameter should normally be:

```cpp
const ClassName& other
```

Why?

- `const` prevents modification of the source object
- `&` avoids making an unnecessary additional copy

---

# 6. Shallow Copy and Deep Copy

Shallow and deep copying become important when a class owns dynamically allocated memory.

---

## Shallow Copy

A shallow copy copies the pointer address.

It does not create new heap memory.

```cpp
class Student {
public:
    int* marks;

    Student(int value) {
        marks = new int(value);
    }
};
```

Suppose we write:

```cpp
Student s1(90);
Student s2 = s1;
```

With a shallow copy, both pointers may point to the same memory.

```text
s1.marks ----\
              ---> same heap memory
s2.marks ----/
```

If we change the value through `s2`:

```cpp
*s2.marks = 50;
```

Then `s1` also appears to contain `50`, because both objects refer to the same memory.

Another serious problem occurs when both objects are destroyed:

- `s1` deletes the memory
- `s2` attempts to delete the same memory
- The program has undefined behaviour

---

## Deep Copy

A deep copy allocates separate memory for the copied object.

```cpp
class Student {
private:
    int* marks;

public:
    Student(int value) {
        marks = new int(value);
    }

    Student(const Student& other) {
        marks = new int(*other.marks);
    }

    ~Student() {
        delete marks;
    }

    int getMarks() const {
        return *marks;
    }
};
```

Now:

```text
s1.marks ---> separate memory containing 90
s2.marks ---> separate memory containing 90
```

The values are initially equal, but the memory locations are independent.

Changing one object does not affect the other.

---

# 7. Rule of Three

When a class manually manages a resource such as dynamic memory, it usually requires:

1. A destructor
2. A copy constructor
3. A copy assignment operator

This is called the **Rule of Three**.

Example copy assignment operator:

```cpp
Student& operator=(const Student& other) {
    if (this != &other) {
        delete marks;

        marks = new int(*other.marks);
    }

    return *this;
}
```

The condition:

```cpp
if (this != &other)
```

protects against self-assignment:

```cpp
s1 = s1;
```

Without that check, the object could delete its own memory before copying from it.

Modern C++ also has the **Rule of Five**, which adds:

4. Move constructor
5. Move assignment operator

---

# 8. Destructors

A destructor is a special function that runs automatically when an object is destroyed.

Syntax:

```cpp
~ClassName() {
    // Cleanup
}
```

Example:

```cpp
class Student {
public:
    Student() {
        cout << "Constructor called\n";
    }

    ~Student() {
        cout << "Destructor called\n";
    }
};
```

---

## When does a destructor run?

A destructor runs when:

- A local object goes out of scope
- A function finishes
- A dynamically allocated object is deleted
- The program cleans up global or static objects

---

## Why do we need destructors?

Ordinary variables are cleaned up automatically.

However, manually acquired resources may need explicit cleanup.

Resources may include:

- Dynamic memory
- Files
- Database connections
- Network connections
- Sockets
- Locks
- Operating-system resources

Example:

```cpp
class DynamicArray {
private:
    int* data;

public:
    DynamicArray(int size) {
        data = new int[size];
    }

    ~DynamicArray() {
        delete[] data;
    }
};
```

Without the destructor, the dynamically allocated array may remain in memory, producing a memory leak.

---

## Manual destruction

Normally, do not call a destructor directly like this:

```cpp
object.~ClassName();
```

The destructor may then run again automatically later, producing undefined behaviour.

For dynamically allocated objects, use `delete`.

```cpp
Student* student = new Student();

delete student;
```

`delete`:

1. Calls the destructor
2. Releases the allocated memory

For dynamically allocated arrays:

```cpp
Student* students = new Student[5];

delete[] students;
```

---

## Virtual Destructor

If a base class will be used polymorphically, its destructor should normally be virtual.

```cpp
class Base {
public:
    virtual ~Base() {
    }
};
```

Example:

```cpp
Base* ptr = new Derived();

delete ptr;
```

A virtual destructor ensures that:

1. The `Derived` destructor runs
2. The `Base` destructor runs

Without a virtual destructor, the derived-class cleanup may be skipped.

---

# 9. Inheritance

Inheritance allows one class to reuse and extend another class.

The original class is called:

- Base class
- Parent class
- Superclass

The new class is called:

- Derived class
- Child class
- Subclass

Example:

```cpp
class Animal {
public:
    void eat() {
        cout << "Eating\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Barking\n";
    }
};
```

```cpp
Dog dog;

dog.eat();
dog.bark();
```

The `Dog` receives the public and protected functionality of `Animal` and adds its own behaviour.

---

# Inheritance Access Modes

Syntax:

```cpp
class Derived : public Base {
};
```

The main inheritance modes are:

- Public inheritance
- Protected inheritance
- Private inheritance

---

## Public Inheritance

```cpp
class Derived : public Base {
};
```

General effect:

- Base public members remain public
- Base protected members remain protected
- Base private members cannot be directly accessed by the derived class

This is the most common inheritance mode.

It represents an **is-a** relationship.

Examples:

```text
SavingsAccount is a BankAccount
Dog is an Animal
Car is a Vehicle
Developer is an Employee
```

---

## Protected Inheritance

```cpp
class Derived : protected Base {
};
```

General effect:

- Base public members become protected
- Base protected members remain protected

Outside code cannot use those inherited members through a derived object.

---

## Private Inheritance

```cpp
class Derived : private Base {
};
```

General effect:

- Base public members become private
- Base protected members become private

This is less common for ordinary OOP modelling.

---

# 10. Types of Inheritance

## Single Inheritance

One child class inherits from one parent class.

```cpp
class Animal {
};

class Dog : public Animal {
};
```

```text
Animal
   |
  Dog
```

---

## Multilevel Inheritance

A class inherits from a class that already inherited from another class.

```cpp
class LivingBeing {
};

class Animal : public LivingBeing {
};

class Dog : public Animal {
};
```

```text
LivingBeing
     |
   Animal
     |
    Dog
```

Real example:

```text
Account
   |
BankAccount
   |
SavingsAccount
```

---

## Multiple Inheritance

One class inherits from multiple base classes.

```cpp
class Printer {
public:
    void print() {
        cout << "Printing\n";
    }
};

class Scanner {
public:
    void scan() {
        cout << "Scanning\n";
    }
};

class MultiFunctionDevice
    : public Printer,
      public Scanner {
};
```

```cpp
MultiFunctionDevice device;

device.print();
device.scan();
```

Real example:

A smart device may behave as:

- A camera
- A phone
- A GPS device

---

## Diamond Problem

Multiple inheritance may create ambiguity.

```cpp
class Person {
public:
    string name;
};

class Student : public Person {
};

class Employee : public Person {
};

class TeachingAssistant
    : public Student,
      public Employee {
};
```

`TeachingAssistant` receives two copies of `Person`:

```text
       Person
       /    \
 Student  Employee
       \    /
  TeachingAssistant
```

This can make access to `name` ambiguous.

Virtual inheritance can solve this:

```cpp
class Student : virtual public Person {
};

class Employee : virtual public Person {
};
```

Now both inheritance paths share one `Person` base object.

---

## Hierarchical Inheritance

Multiple child classes inherit from the same parent class.

```cpp
class BankAccount {
};

class SavingsAccount : public BankAccount {
};

class CurrentAccount : public BankAccount {
};

class FixedDepositAccount : public BankAccount {
};
```

```text
             BankAccount
            /     |      \
      Savings  Current  FixedDeposit
```

---

## Hybrid Inheritance

Hybrid inheritance combines multiple inheritance structures.

It may combine:

- Single inheritance
- Multilevel inheritance
- Multiple inheritance
- Hierarchical inheritance

Large programs may naturally develop hybrid inheritance structures.

---

# 11. Polymorphism

Polymorphism means:

> One interface can behave in different forms.

The word means **many forms**.

There are two broad categories:

1. Compile-time polymorphism
2. Runtime polymorphism

---

# 12. Compile-Time Polymorphism

In compile-time polymorphism, the compiler decides which function to use before the program runs.

Examples:

- Function overloading
- Operator overloading

---

# 13. Function Overloading

Function overloading means using the same function name with different parameter lists.

```cpp
class Printer {
public:
    void print(int value) {
        cout << "Integer: "
             << value
             << '\n';
    }

    void print(double value) {
        cout << "Double: "
             << value
             << '\n';
    }

    void print(string value) {
        cout << "String: "
             << value
             << '\n';
    }
};
```

```cpp
Printer printer;

printer.print(10);
printer.print(4.5);
printer.print("Hello");
```

The compiler chooses the correct function based on the supplied argument.

---

## Functions may differ by

- Number of parameters
- Types of parameters
- Order of parameter types

```cpp
void show(int x);

void show(double x);

void show(int x, int y);

void show(string text, int count);

void show(int count, string text);
```

---

## Return type alone is not enough

This is invalid:

```cpp
int calculate(int x);

double calculate(int x);
```

Both functions have the same name and parameter list.

The compiler cannot choose between them using only the expected return type.

---

# 14. Operator Overloading

Operator overloading allows operators to work with user-defined classes.

The `+` operator already works with integers:

```cpp
int result = 2 + 3;
```

We can define what `+` means for our own objects.

```cpp
class Money {
private:
    double amount;

public:
    Money(double value) {
        amount = value;
    }

    Money operator+(const Money& other) const {
        return Money(amount + other.amount);
    }

    double getAmount() const {
        return amount;
    }
};
```

```cpp
Money m1(100);
Money m2(50);

Money total = m1 + m2;

cout << total.getAmount();
```

The expression:

```cpp
m1 + m2
```

is essentially treated as:

```cpp
m1.operator+(m2)
```

---

## Why use operator overloading?

It allows custom objects to use clear and natural syntax.

Instead of:

```cpp
Money total = m1.add(m2);
```

we may write:

```cpp
Money total = m1 + m2;
```

---

## Comparison operator example

```cpp
bool operator>(const BankAccount& other) const {
    return balance > other.balance;
}
```

Then:

```cpp
if (account1 > account2) {
    cout << "Account 1 has more money";
}
```

---

## Important rule

Operator overloading should make intuitive sense.

Good examples:

```cpp
vector1 + vector2
money1 + money2
date1 < date2
account1 > account2
```

A confusing example would be:

```cpp
student1 * student2
```

unless multiplication has an obvious and meaningful interpretation.

---

# 15. Runtime Polymorphism

Runtime polymorphism is achieved using:

- Inheritance
- Function overriding
- Virtual functions
- Base-class pointers
- Base-class references

The actual function is selected at runtime according to the real object.

---

# 16. Function Overriding

Function overriding happens when a derived class provides its own implementation of a base-class function.

```cpp
class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows\n";
    }
};
```

---

## Why do we need overriding?

Every animal can make a sound, but different animals make different sounds.

The base class defines the common idea:

```cpp
makeSound()
```

Each derived class defines the specific behaviour.

---

## Relatable banking example

Every bank account can calculate a monthly benefit.

However:

- Savings accounts may add interest
- Current accounts may add no interest
- Reward accounts may add cashback

```cpp
class BankAccount {
public:
    virtual void calculateMonthlyBenefit() {
        cout << "General calculation\n";
    }
};

class SavingsAccount : public BankAccount {
public:
    void calculateMonthlyBenefit() override {
        cout << "Adding savings interest\n";
    }
};

class CurrentAccount : public BankAccount {
public:
    void calculateMonthlyBenefit() override {
        cout << "No interest added\n";
    }
};
```

The function name remains the same, while the behaviour changes according to the object.

---

# 17. Virtual Functions

A virtual function enables runtime polymorphism.

```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks\n";
    }
};
```

```cpp
class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks\n";
    }
};
```

Now:

```cpp
Animal* ptr = new Dog();

ptr->speak();
```

Output:

```text
Dog barks
```

Although `ptr` has type `Animal*`, it points to a `Dog`.

Because `speak()` is virtual, C++ selects the function using the real object type.

Without `virtual`, the base-class version may be called instead.

---

## Base-class pointer

A base-class pointer can point to a derived-class object.

```cpp
Dog dog;

Animal* ptr = &dog;
```

This allows one interface to control different object types.

```cpp
Dog dog;
Cat cat;

Animal* animals[2] = {
    &dog,
    &cat
};

for (Animal* animal : animals) {
    animal->speak();
}
```

Each object executes its own overridden function.

---

## The `override` keyword

Use:

```cpp
void speak() override
```

The `override` keyword tells the compiler:

> This function is intended to override a virtual function from the base class.

If the function signature is incorrect, the compiler reports an error.

```cpp
class Base {
public:
    virtual void show(int x) {
    }
};

class Derived : public Base {
public:
    // Error: this does not match show(int)
    void show(double x) override {
    }
};
```

This is useful because it prevents accidental mistakes.

---

# 18. Abstraction

Abstraction means:

> Showing only the necessary interface while hiding unnecessary implementation details.

Example:

```cpp
account.withdraw(500);
```

The user does not need to know:

- How the balance is stored
- How fraud checks work
- How the transaction is recorded
- How a database is updated
- How notifications are sent

The user only needs the simple operation:

```cpp
withdraw(500);
```

---

## Real-world example

When driving a car, you interact with:

- Steering wheel
- Brake
- Accelerator
- Gear controls

You do not directly operate:

- Fuel injection
- Engine timing
- Electrical circuits
- Cooling systems
- Internal gearbox components

The complicated implementation is hidden behind a simpler interface.

That is abstraction.

---

# 19. Abstract Classes

An abstract class is a class that cannot be directly instantiated.

A class becomes abstract when it contains at least one pure virtual function.

```cpp
class PaymentMethod {
public:
    virtual void pay(double amount) = 0;
};
```

This is invalid:

```cpp
PaymentMethod payment;
```

`PaymentMethod` is incomplete because it does not define how payment should occur.

Derived classes provide the implementations.

```cpp
class CardPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "Paid using card: "
             << amount
             << '\n';
    }
};

class UpiPayment : public PaymentMethod {
public:
    void pay(double amount) override {
        cout << "Paid using UPI: "
             << amount
             << '\n';
    }
};
```

---

# 20. Pure Virtual Functions

A pure virtual function is declared using `= 0`.

```cpp
virtual void pay(double amount) = 0;
```

This means:

> Every concrete derived class must provide its own implementation.

Example:

```cpp
class Shape {
public:
    virtual double area() const = 0;
};
```

Every shape must define how its area is calculated.

```cpp
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }
};
```

```cpp
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    double area() const override {
        return width * height;
    }
};
```

---

## Intuitive reason

There is no single universal formula for the area of every shape.

A circle and rectangle require different formulas.

However, every real shape must provide some area calculation.

Therefore, the base class enforces the rule:

```cpp
virtual double area() const = 0;
```

---

# 21. Interface-Like Design in C++

C++ does not have a separate `interface` keyword like some other languages.

An abstract class containing only pure virtual functions may act as an interface.

```cpp
class Printable {
public:
    virtual void print() const = 0;

    virtual ~Printable() = default;
};
```

Any concrete class inheriting from `Printable` must implement `print()`.

```cpp
class Report : public Printable {
public:
    void print() const override {
        cout << "Printing report\n";
    }
};
```

---

# 22. Static Keyword

A static data member belongs to the class itself rather than to each individual object.

```cpp
class BankAccount {
public:
    static int totalAccounts;
};
```

The member is declared inside the class and normally defined outside it.

```cpp
int BankAccount::totalAccounts = 0;
```

Access it using the class name:

```cpp
cout << BankAccount::totalAccounts;
```

---

## Normal member versus static member

A normal member belongs separately to each object.

```cpp
class Student {
public:
    string name;
};
```

```cpp
Student s1;
Student s2;
```

Each object has a separate name:

```text
s1.name
s2.name
```

A static member is shared.

```cpp
class Student {
public:
    static int studentCount;
};
```

There is only one value:

```text
Student::studentCount
```

Every `Student` object observes the same shared variable.

---

## Real uses of static members

Static members may be used for:

- Counting objects
- Generating IDs
- Shared limits
- Shared configuration
- Tracking total users
- Maintaining common cached data

Example:

```cpp
class User {
private:
    int id;

public:
    static int nextId;

    User() {
        id = nextId;
        nextId++;
    }

    int getId() const {
        return id;
    }
};

int User::nextId = 1;
```

Each new object receives a unique ID.

---

# 23. Static Member Functions

A static member function belongs to the class rather than a particular object.

```cpp
class Calculator {
public:
    static int add(int a, int b) {
        return a + b;
    }
};
```

Call it without creating an object:

```cpp
cout << Calculator::add(2, 3);
```

A static member function cannot directly access non-static members.

```cpp
class Example {
private:
    int value;

public:
    static void show() {
        // Error: no particular object's value exists here
        cout << value;
    }
};
```

A static function has no `this` pointer because it is not called for one particular object.

---

# 24. Static Local Variables

A static local variable is initialised once and keeps its value between function calls.

```cpp
void counter() {
    static int count = 0;

    count++;

    cout << count << '\n';
}
```

```cpp
counter();
counter();
counter();
```

Output:

```text
1
2
3
```

Without `static`, `count` would be recreated as `0` every time the function runs.

---

# 25. Friend Functions

A friend function is not a member of a class, but it is allowed to access the class's private and protected members.

```cpp
class Box {
private:
    double width;

public:
    Box(double w) {
        width = w;
    }

    friend void printWidth(const Box& box);
};
```

```cpp
void printWidth(const Box& box) {
    cout << box.width;
}
```

Although `width` is private, `printWidth()` may access it because it was declared as a friend.

---

## Why use a friend function?

Friend functions may be useful when:

- A non-member function logically requires internal access
- Overloading certain operators
- Closely related utility functions need controlled access
- Two components need special cooperation

A common example is overloading the output operator.

```cpp
class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a)
        : name(n), age(a) {
    }

    friend ostream& operator<<(
        ostream& output,
        const Student& student
    );
};
```

```cpp
ostream& operator<<(
    ostream& output,
    const Student& student
) {
    output << student.name
           << ", "
           << student.age;

    return output;
}
```

Now:

```cpp
Student student("Riya", 22);

cout << student;
```

---

## Important warning

Friendship weakens normal encapsulation boundaries.

Do not make many functions friends merely to avoid writing proper public methods.

Use friendship only when the relationship is justified.

---

# 26. Friend Classes

A friend class may access the private and protected members of another class.

```cpp
class Bank;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double amount) {
        balance = amount;
    }

    friend class Bank;
};
```

```cpp
class Bank {
public:
    void inspect(const BankAccount& account) {
        cout << account.balance;
    }
};
```

`Bank` may directly access the private balance.

---

## Real use case

Suppose:

- `BankAccount` protects customer information
- The central `Bank` class requires administrative access
- Ordinary outside code must not directly access that data

The `Bank` class can be given friendship without making the data public to everyone.

---

# 27. Composition: Has-A Relationship

Inheritance represents an **is-a** relationship.

```text
SavingsAccount is a BankAccount
Dog is an Animal
Developer is an Employee
```

Composition represents a **has-a** relationship.

```text
Car has an Engine
Bank has BankAccounts
Student has an Address
Computer has a Processor
```

Example:

```cpp
class Engine {
public:
    void start() {
        cout << "Engine started\n";
    }
};

class Car {
private:
    Engine engine;

public:
    void startCar() {
        engine.start();

        cout << "Car started\n";
    }
};
```

`Car` does not inherit from `Engine`.

A car **has an** engine.

Composition is often simpler and safer than inheritance.

Use inheritance when there is a genuine **is-a** relationship.

Use composition when one object contains or uses another object.

---

# 28. The `this` Pointer

Inside a non-static member function, `this` points to the current object.

```cpp
class Student {
private:
    string name;

public:
    Student(string name) {
        this->name = name;
    }
};
```

Here:

- `name` refers to the constructor parameter
- `this->name` refers to the object's data member

The `this` pointer may also be used to return the current object.

```cpp
class Counter {
private:
    int value;

public:
    Counter(int value) {
        this->value = value;
    }

    Counter& increment() {
        value++;

        return *this;
    }
};
```

```cpp
Counter counter(0);

counter.increment()
       .increment()
       .increment();
```

Returning `*this` makes method chaining possible.

---

# 29. Object Slicing

Object slicing occurs when a derived object is copied into a base object by value.

```cpp
class Animal {
public:
    string type;
};

class Dog : public Animal {
public:
    string breed;
};
```

```cpp
Dog dog;

Animal animal = dog;
```

The `breed` part is removed because `animal` is only a base-class object.

To preserve polymorphic behaviour, use references or pointers.

```cpp
Animal& animalReference = dog;

Animal* animalPointer = &dog;
```

---

# 30. Passing Objects to Functions

## Pass by Value

```cpp
void printStudent(Student student) {
}
```

This creates a copy of the object.

For large objects, copying may be expensive.

---

## Pass by Reference

```cpp
void updateStudent(Student& student) {
}
```

No copy is created.

The function may modify the original object.

---

## Pass by Const Reference

```cpp
void printStudent(const Student& student) {
}
```

No copy is created, and the function is not allowed to modify the object.

This is normally the best option for efficient read-only access.

---

# 31. Overloading versus Overriding

These concepts have similar names but are different.

## Overloading

Same function name, but different parameter lists.

Usually occurs in the same class.

```cpp
void print(int value);

void print(string value);
```

Overloading is compile-time polymorphism.

---

## Overriding

A derived class replaces a virtual function inherited from a base class.

```cpp
class Animal {
public:
    virtual void speak() {
    }
};

class Dog : public Animal {
public:
    void speak() override {
    }
};
```

Overriding is runtime polymorphism.

---

# 32. Quick Comparison Table

| Concept | Meaning |
|---|---|
| Class | Blueprint used to create objects |
| Object | A real instance of a class |
| Public | Accessible from outside the class |
| Private | Accessible only inside the class and friends |
| Protected | Accessible inside the class and derived classes |
| Encapsulation | Bundle data and functions with controlled access |
| Constructor | Initialises an object |
| Copy constructor | Creates an object from another object |
| Destructor | Cleans resources when an object is destroyed |
| Shallow copy | Copies pointer addresses |
| Deep copy | Creates independent copies of owned resources |
| Inheritance | Creates one class from another |
| Polymorphism | Same interface with different behaviour |
| Abstraction | Hides implementation details |
| Overloading | Same name with different parameters |
| Overriding | Derived class replaces base virtual behaviour |
| Virtual function | Enables runtime function selection |
| Pure virtual function | Forces derived classes to implement behaviour |
| Abstract class | Class that cannot be instantiated directly |
| Static member | Shared by the entire class |
| Friend function | Non-member function with special private access |
| Friend class | Another class with special private access |
| Composition | One object contains or uses another object |

---

# 33. Core Mental Model

Think of a class as a controlled machine.

```text
Private internal data
        ↓
Protected internal tools
        ↓
Public interface
```

Outside code should normally interact through the public interface.

```cpp
account.deposit(500);
account.withdraw(100);
```

Outside code should not directly manipulate important internal data.

```cpp
account.balance = -100000;
```

The object is responsible for keeping itself valid.

---

# 34. Final Example Using All Four OOP Pillars

```cpp
#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    // Encapsulation:
    // salary is protected from direct outside changes.
    double salary;

protected:
    // Derived classes may use the employee's name.
    string name;

public:
    Employee(
        string employeeName,
        double employeeSalary
    ) : name(employeeName),
        salary(employeeSalary) {
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double newSalary) {
        if (newSalary >= 0) {
            salary = newSalary;
        }
    }

    // Abstraction:
    // Every concrete employee must define work().
    virtual void work() const = 0;

    virtual ~Employee() {
    }
};

// Inheritance:
// Developer is an Employee.
class Developer : public Employee {
public:
    Developer(
        string name,
        double salary
    ) : Employee(name, salary) {
    }

    // Runtime polymorphism through overriding.
    void work() const override {
        cout << name
             << " writes software\n";
    }
};

// Inheritance:
// Trader is also an Employee.
class Trader : public Employee {
public:
    Trader(
        string name,
        double salary
    ) : Employee(name, salary) {
    }

    void work() const override {
        cout << name
             << " analyses markets\n";
    }
};

int main() {
    Developer developer(
        "Riya",
        50000
    );

    Trader trader(
        "Alex",
        60000
    );

    Employee* employees[2] = {
        &developer,
        &trader
    };

    // Polymorphism:
    // The same work() call behaves differently
    // depending on the real object.
    for (Employee* employee : employees) {
        employee->work();
    }

    return 0;
}
```

This example contains all four pillars.

---

## Encapsulation

```cpp
private:
    double salary;
```

The salary is protected and accessed through getters and setters.

---

## Inheritance

```cpp
class Developer : public Employee
```

`Developer` inherits from `Employee`.

---

## Polymorphism

```cpp
employee->work();
```

The same call behaves differently depending on whether the object is a `Developer` or a `Trader`.

---

## Abstraction

```cpp
virtual void work() const = 0;
```

Every concrete employee must define what working means, but the base class does not provide one universal implementation.

---

# Final Revision Points

- A class is a blueprint.
- An object is an instance of a class.
- Members of a C++ class are private by default.
- Members of a C++ struct are public by default.
- Public members form the interface used by outside code.
- Private members protect an object's internal state.
- Protected members are available to derived classes.
- Getters read private data.
- Setters safely change private data.
- Encapsulation combines data and related functions with controlled access.
- Constructors initialise objects.
- A default constructor takes no arguments.
- A parameterised constructor receives initial values.
- A copy constructor creates a new object from an existing object.
- A shallow copy copies pointer addresses.
- A deep copy creates independent owned resources.
- Classes managing dynamic memory should follow the Rule of Three or Rule of Five.
- Destructors release resources.
- A virtual destructor is important for polymorphic base classes.
- Inheritance represents an is-a relationship.
- Composition represents a has-a relationship.
- Function overloading is compile-time polymorphism.
- Operator overloading gives meaningful behaviour to operators for custom objects.
- Function overriding allows derived classes to replace base-class behaviour.
- Virtual functions enable runtime polymorphism.
- Base-class pointers and references can refer to derived objects.
- A pure virtual function is written using `= 0`.
- A class containing a pure virtual function is abstract.
- Abstract classes cannot be directly instantiated.
- Static members are shared by all objects of a class.
- Static functions do not have a `this` pointer.
- Friend functions and friend classes can access private members.
- Friendship should be used sparingly.
- Pass large read-only objects using `const` references.
- Use `override` when overriding virtual functions.
- Prefer a clear public interface rather than exposing data directly.