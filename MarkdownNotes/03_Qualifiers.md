# C++ Qualifiers

_**Before we start**_

As you read through this article, you’ll come across some code snippets containing elements that we will cover in more detail later in the course. Don't worry if some of these concepts seem unfamiliar right now. Take a deep breath and relax. We'll explore each of these topics as we progress. Trust and enjoy the learning process!

## What are Qualifiers?

In C++, qualifiers are keywords that specify additional properties or constraints on variables, functions, and data types. Qualifiers enable you to control various aspects of how your data and functions behave. In this article, we will explore the most commonly used qualifiers in C++: const, volatile, mutable, inline, and constexpr.

## The `const` Qualifier

The `const` qualifier is used to declare variables that cannot be modified after their initial assignment. This is useful for defining constant values and ensuring that certain data remains unchanged throughout your program.

### Using `const` with variables

When you declare a variable with `const`, you must initialize it at the time of declaration:

~~~cpp
const int maxHealth = 100;
~~~

Here, `maxHealth` is a constant integer that cannot be changed. Attempting to modify it will result in a compiler error:

~~~cpp
maxHealth = 200; // Error: assignment of read-only variable 'maxHealth'
~~~

### `const` with function parameters

Using `const` with function parameters helps ensure that the arguments passed to the function are not modified within the function body:

~~~cpp
#include <iostream>
#include <string>
void displayScore(const std::string& playerName){
    std::cout << "Player: " << playerName << std::endl;
}

int main(){
    std::string name = "Hero";
    displayScore(name);
    return 0;
}
~~~

In this example, `playerName` is a constant reference to a `std::string`, ensuring that the function cannot modify the original string.

## The `volatile` Qualifier

The `volatile` qualifier tells the compiler that a variable's value may change at any time, without any action being taken by the code the compiler finds nearby. This is often used in embedded systems and multithreaded programs.

### Using `volatile` with variables

A typical use case for `volatile` is when working with hardware registers or memory-mapped I/O:

~~~cpp
volatile int enemyStatus;
~~~

The compiler will not optimize accesses to `enemyStatus`, ensuring that each read and write operation actually happens, which is necessary for correct operation in such environments.

## The `mutable` Qualifier

The `mutable` qualifier allows a member of an object to be modified even if the object is declared as `const`. This can be useful in certain scenarios where you need to maintain some internal state that doesn't affect the object's externally visible state.

### Using `mutable` in a class

Although we haven't covered classes yet, here's a simple illustration. Try to pay attention to the structure of a class definition, which we will cover in detail later in the course.

~~~cpp
class Player{
    public:
        void updateScore() const{
            ++score;
        }
            
    private:
        mutable int score = 0;
};
~~~

In this example, `score` is a `mutable` member of the `Player` class, allowing it to be modified even within a `const` member function. We'll delve deeper into classes and member functions later in the course.

## The `inline` Qualifier

The `inline` qualifier is a hint to the compiler to generate a copy of the function's code at each point where the function is called, rather than generating a normal function call. This can improve performance by eliminating the overhead of function calls, especially for small functions.

### Using `inline` with functions

Here's an example using `inline`:

~~~cpp
inline int calculateDamage(int baseDamage, int modifier){
    return baseDamage + modifier;
}
    
int main(){
    int totalDamage = calculateDamage(50, 10);
    std::cout << "Total Damage: " << totalDamage << std::endl;
    return 0;
}
~~~

In this example, the `calculateDamage` function is declared as `inline`. The compiler may choose to insert the function's code directly into the calling code, reducing the overhead of a function call.

## The `constexpr` Qualifier

The `constexpr` qualifier is used to indicate that the value of a variable or the result of a function can be evaluated at compile time. This enables the compiler to perform optimizations and ensures that certain expressions are constant.

### Using `constexpr` with variables

When you declare a variable with `constexpr`, it must be initialized with a constant expression:

~~~cpp
        constexpr int maxLevel = 99;
~~~

### `constexpr` with functions

Functions can also be declared as `constexpr`:

~~~cpp
constexpr int calculateExperience(int level){
    return level * level * 100;
}
        
int main(){
    constexpr int experience = calculateExperience(5);
    std::cout << "Experience for level 5: " << experience << std::endl;
    return 0;
}
~~~

In this example, the `calculateExperience` function is a `constexpr` function, meaning it can be evaluated at compile time if given constant arguments.

## Combining Qualifiers

Qualifiers can often be combined to create more specific constraints. For example, you can combine `const` and `constexpr`:

~~~cpp
constexpr int calculateMaxSpeed(int baseSpeed, int boost){
    return baseSpeed + boost * 5;
}
        
constexpr const int maxSpeed = calculateMaxSpeed(60, 8);
 ~~~

Here, `maxSpeed` is both a constant expression and a constant variable, calculated using the `calculateMaxSpeed` function.

## Honorable Mention: The `static` Specifier

Although not a qualifier, the `static` specifier in C++ has several important uses, depending on its context. It can be applied to variables, functions, and class members, and it plays a significant role in managing the scope and lifetime of variables.

### Using `static` with Local Variables

When applied to local variables within a function, `static` extends their lifetime to the entire duration of the program, rather than just the function's execution. This allows the variable to retain its value between function calls.

~~~cpp
#include <iostream>
void generateUniqueID(){
    static int id = 0; // Static local variable
    ++id;
    std::cout << "Generated ID: " << id << std::endl;
}
        
int main(){
    generateUniqueID(); // Output: Generated ID: 1
    generateUniqueID(); // Output: Generated ID: 2
    generateUniqueID(); // Output: Generated ID: 3
    return 0;
}
~~~

In this example, the `static` variable `id` retains its value between calls to `generateUniqueID`, allowing it to produce unique IDs sequentially.

### Using `static` with Class Members

When applied to a class member, `static` makes the member shared across all instances of the class, rather than being unique to each instance. This is particularly useful for keeping track of data or state that is common to all instances of a class.

Here we have another example of a class definition with a `static` data member and a `static` member function.
Once again, try to get familiar with the structure of the class, and rest assured that we will cover all of this in detail later.

~~~cpp
#include <iostream>
class Enemy{
    public:
        static int enemyCount; // Static class member
            // This is the constructor, called every time a new Enemy object is instantiated.
        Enemy(){
            ++enemyCount; // Increase enemy count
        }
            static void showEnemyCount() {
            std::cout << "Total Enemies: " << enemyCount << std::endl;
        }
};

// Initialize static member even when no instances exist yet
int Enemy::enemyCount = 0;

int main(){
    Enemy goblin;
    Enemy orc;
    Enemy troll;
    Enemy::showEnemyCount(); // Output: Total Enemies: 3

    return 0;
}
~~~

In this example, the `static` member `enemyCount` is shared across all `Enemy` instances, keeping track of the total number of `Enemy` objects created. The class constructor (identified in the code) increases this count every time a new enemy is created.
The `showEnemyCount` function demonstrates how to access the `static` member. Notice that `static` member functions are accessed as members of the class, not of objects. That’s why we use the _scope resolution operator_ (double colon) in `Enemy::showEnemyCount()`.

Also notice that `static` members are available to our code even when no objects of the class have been defined. That’s why we need to use the class name and the scope resolution operator.

### Using `static` with Functions

When applied to functions, `static` changes their linkage. A `static` function in a source file has internal linkage, meaning it can only be accessed within that file. This can help encapsulate helper functions that shouldn't be exposed outside of a specific file or module. In pretty much any real-life C++ project, you’ll work with several source files, so sometimes you don’t want to make functions in a file available to the rest of the codebase.

## Summary

In this article, we've explored some of the most important qualifiers in C++: `const`, `volatile`, `mutable`, `inline`, and `constexpr`. Understanding these qualifiers will help you write better code by providing additional constraints and guarantees on your variables and functions. As you continue with this course, you'll see these qualifiers in action and learn how to use them effectively in your own programs.

For further reading, you can visit [cppreference.com](https://en.cppreference.com/w/cpp/language/declarations).
