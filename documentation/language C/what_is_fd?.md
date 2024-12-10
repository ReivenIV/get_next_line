```txt
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
```

# **What is "fd" (File Descriptor) in C?**

In C programming, **"fd"** stands for **File Descriptor**. It is a small integer that represents an open file or a resource like a socket. The operating system uses file descriptors to track open files in a program.

### **Why Use File Descriptors?**
When you open a file, the operating system assigns a number to it. You use this number to read, write, or close the file.

### **Key Takeaways:**
- **File Descriptor (fd)** is a number used by the OS to manage files or resources.
- You use this number with functions like `read()`, `write()`, and `close()`.
- If an operation fails, `fd` returns `-1`, meaning something went wrong.

---

## **Standard File Descriptors:**
There are three standard file descriptors in C:

| File Descriptor | Name         | Description      |
|------------------|---------------|------------------|
| `0`              | `stdin`      | Standard input   |
| `1`              | `stdout`     | Standard output  |
| `2`              | `stderr`     | Standard error   |

---


# Exemples without using open

You can use file descriptors **without** `open()` by working with standard file descriptors (`stdin`, `stdout`, and `stderr`). These are **already opened** by default when your program runs.  

---

## **Example 1: Writing to `stdout` (File Descriptor `1`)**  
You can use `write()` to send text directly to the terminal using `fd = 1` (`stdout`).  

```c
#include <unistd.h>

int main() {
    // Writing to the standard output (terminal)
    write(1, "Hello, World!\n", 14);
    return 0;
}
```

**What Happens:**  
- `write(1, "Hello, World!\n", 14);` writes the text directly to the terminal because `1` is `stdout`.  

---

## **Example 2: Writing an Error Message to `stderr` (File Descriptor `2`)**  
You can send error messages to the standard error output using `fd = 2`.  

```c
#include <unistd.h>

int main() {
    // Writing to the standard error (terminal)
    write(2, "Error: Something went wrong!\n", 30);
    return 1;  // Return an error code
}
```

**What Happens:**  
- `write(2, "Error: Something went wrong!\n", 30);` writes the message to `stderr`, usually displayed in the terminal.

---

## **Example 3: Reading from `stdin` (File Descriptor `0`)**  
You can use `read()` to get input from the user through `stdin`.  

```c
#include <unistd.h>

int main() {
    char buffer[100];  

    // Reading from standard input (keyboard)
    int bytesRead = read(0, buffer, sizeof(buffer));
    
    // Writing back to standard output
    write(1, "You entered: ", 13);
    write(1, buffer, bytesRead);

    return 0;
}
```

**What Happens:**  
- `read(0, buffer, sizeof(buffer));` reads from the terminal (keyboard).  
- `write(1, buffer, bytesRead);` prints what the user typed.  

---

### **Key Takeaways:**  
- `0` → `stdin` (read from the keyboard)  
- `1` → `stdout` (print to the screen)  
- `2` → `stderr` (print error messages)  

--- 

# Exemples using open
### **Example 1: Writing to a File**
```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_WRONLY | O_CREAT, 0644); 
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    // Write to the file using the file descriptor
    write(fd, "Hello, World!\n", 14);
    
    // Close the file
    close(fd);
    return 0;
}
```
**What Happens Here:**
- `open()` opens the file and returns a file descriptor (`fd`).
- `write()` uses `fd` to write to the file.
- `close()` closes the file.

---

### **Example 2: Redirecting Output**
```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    
    // Redirect stdout (1) to the file descriptor fd
    dup2(fd, 1);
    
    // This will go to "output.txt" instead of the terminal
    printf("This is written to the file!\n");
    
    close(fd);
    return 0;
}
```

**What Happens Here:**
- `dup2(fd, 1);` redirects `stdout` to the file descriptor `fd`.
- `printf()` writes directly to the file instead of the terminal.

---
