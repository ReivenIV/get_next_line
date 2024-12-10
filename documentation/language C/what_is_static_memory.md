/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rita <rita@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:57:01 by rita              #+#    #+#             */
/*   Updated: 2024/12/10 14:12:38 by rita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# **Static Memory in C**  

### **What is static memory?**  
- **Static Memory** is a region in a program where memory is allocated **before the program runs** and stays the same **during the entire execution** of the program.  
- It is fixed and cannot grow or shrink while the program runs.  

### **How it works:**  
- **Global Variables** and **Static Variables** in C are stored in static memory.  
- This memory is automatically initialized to **zero** if you don’t set a value.  

---
### **Simple Example:**  

```c
#include <stdio.h>

// Global variable (stored in static memory)
int counter = 0;

void increaseCounter() {
    // Static variable (stored in static memory)
    static int calls = 0;
    calls++;
    printf("Function called %d times\n", calls);
}

int main() {
    increaseCounter();  // Output: Function called 1 times
    increaseCounter();  // Output: Function called 2 times
    increaseCounter();  // Output: Function called 3 times
    return 0;
}
```

#### **Why is this static memory?**  
- `calls` is a **static variable**: It keeps its value even **after the function ends**.  
- When `increaseCounter()` runs again, `calls` **remembers** its last value.

---

### **Why is it important to know about "static Memory"?**  

1. **Persistence of Data:**  
   - Static variables retain their values between function calls.  

2. **Memory Management:**  
   - You don’t have to allocate or free memory manually.

3. **Performance:**  
   - Reduces **memory allocation overhead**, making programs more efficient.

4. **Scope Control:**  
   - Static variables are only visible **within the file or function** where they are defined, which enhances **data security**.

## **Why Use the `static` Keyword?**
- **Control Scope:** Using `static` limits the visibility of variables or functions to the file or function where they are declared, preventing unintended access or modifications from other parts of the program.
- **Avoid Naming Conflicts:** In large projects, multiple files might have variables or functions with the same name. Declaring them as `static` ensures they don't interfere with each other.

In summary, while both global and static variables reside in static memory, the `static` keyword in C is used to **restrict the scope** of variables or functions, enhancing encapsulation and reducing potential errors due to unintended interactions. 

---
---

# Difference between "Global variables" and "Static variables"

Let's bring some light about the distinction between **Global variables** and **Static variables** in C, focusing on their scope and linkage.

## **Global Variables:**
- **Definition:** Variables declared **outside** of any function.
- **Scope:** Accessible by any function within the same file or even other files (if properly declared).
- **Linkage:** By default, they have **external linkage**, meaning they can be accessed across multiple files.

**Example:**
```c
#include <stdio.h>

int globalVar = 10; // Global variable

void function1() {
    printf("function1: globalVar = %d\n", globalVar);
}

void function2() {
    globalVar = 20; // Modify global variable
    printf("function2: globalVar = %d\n", globalVar);
}

int main() {
    function1(); // Outputs: function1: globalVar = 10
    function2(); // Outputs: function2: globalVar = 20
    function1(); // Outputs: function1: globalVar = 20 (crazy)
    return 0;
}
```

## **Static Variables:**
- **Definition:** Variables declared with the `static` keyword.
- **Scope:** Depends on where they are declared:
  - **Inside a function:** Accessible only within that function.
  - **Outside all functions (file scope):** Accessible only within that file.
- **Linkage:** When declared at file scope with `static`, they have **internal linkage**, meaning they are not accessible from other files.

**Example 1: Static Variable Inside a Function**
```c
#include <stdio.h>

void counter() {
    static int count = 0; // Static local variable
    count++;
    printf("count = %d\n", count);
}

int main() {
    counter(); // Outputs: count = 1
    counter(); // Outputs: count = 2
    counter(); // Outputs: count = 3
    return 0;
}
```
Here, `count` retains its value between calls to `counter()` but is not accessible outside this function.

**Example 2: Static Global Variable**
```c
#include <stdio.h>

static int staticVar = 100; // Static global variable

void function1() {
    printf("function1: staticVar = %d\n", staticVar);
}

void function2() {
    staticVar = 200; // Modify static global variable
    printf("function2: staticVar = %d\n", staticVar);
}

int main() {
    function1(); // Outputs: function1: staticVar = 100
    function2(); // Outputs: function2: staticVar = 200
    function1(); // Outputs: function1: staticVar = 200
    return 0;
}
```
In this case, `staticVar` is accessible by all functions within the same file but cannot be accessed from other files.

