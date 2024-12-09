# **What is `read` in C?**  

In C, `read` is a system call that allows you to read data from a file, device, or input stream into memory.

## **How Does It Work?**  
The `read` function reads data from a file descriptor into a buffer (an array in memory).

### **Syntax:**  
```c
ssize_t read(int fd, void *buf, size_t count);
```

- **`fd`**: File descriptor (an integer representing the file or input source).  
- **`buf`**: Pointer to a memory location where the read data will be stored.  
- **`count`**: Maximum number of bytes to read.

### **Returns:**  
- Number of bytes successfully read.  
- `0` if the end of the file is reached.  
- `-1` if there’s an error.


## **Key Points to Remember:**  
- `read` works with file descriptors (like `0` for standard input, `1` for standard output, or `2` for standard error).  
- It doesn’t add a null character (`'\0'`), so you need to do that manually for strings.  
- You must include `<unistd.h>` to use `read`.  

---

## **Simple Example: Reading from Standard Input (`stdin`)**
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    char buffer[100]; // Buffer to store the data
    int bytesRead;

    // Reading input from the user
    bytesRead = read(0, buffer, sizeof(buffer) - 1); // 0 means stdin
    
    if (bytesRead == -1) {
        perror("Error reading input");
        return 1;
    }

    // Adding a null terminator to the string
    buffer[bytesRead] = '\0';

    // Printing what was read
    printf("You entered: %s\n", buffer);

    return 0;
}
```
