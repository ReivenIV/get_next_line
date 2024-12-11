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

# Understanding `open` in C

In C, **`open`** is a system call used to open a file. When you open a file, the system gives you a **file descriptor**, which is like a special number used to read from or write to the file.

By using `open`, you can manage files directly in C, making it a powerful tool for file-based applications.

## Why Use `open`?
- To **read** data from a file.
- To **write** data to a file.
- To **create** a file if it doesn’t exist.
- Reminder: _to **close** a file after reading you will need the `close(fd)` from unistd.h library._

## Important Notes:
- Always **check if `open` returns `-1`**, meaning something went wrong.
- in language C always **close the file** after using it with `close(fd);`.
- You can use **`perror()`** to see what went wrong if there’s an error.

---

## How to Use `open`

### Header File:
```c
#include <fcntl.h>   // For open()
#include <unistd.h>  // For close()
```

### Syntax:
```c
int file_descriptor = open("filename", flags, mode);
```

- **`filename`**: The name of the file (e.g., "example.txt").
- **`flags`**: How you want to open the file:
  - `O_RDONLY` - Read only.
  - `O_WRONLY` - Write only.
  - `O_RDWR`   - Read and write.
  - `O_TRUNC`  - Truncated mode. If the file exists and the access mode allows writing to it ( O_WRONLY ou O_RDWR), truncates its contents to 0 size when it is opened, with the effect of overwriting the file..
  - `O_APPEND`  - Append mode. The file offset is set to the end of the file at each write, with the effect of adding text to the end of the file instead of overwriting it.
  - `O_CREAT`  - Create the file if it doesn’t exist.

---
```c
// ex: we can open a file in read only mode this way:
open("path/to/file", O_RDONLY);

// ex: we can combine flags with  "|" (OR operator). If we want to open a file in truncated write mode, we could do:
open("path/to/file", O_WRONLY | O_TRUNC);

```
---


---

### Simple Example 1: Open a File and get "fd" (File Descriptor)
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    // Here is the way to get the fd adresse to the file. 
    int fd = open("example.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    printf("File opened successfully! File descriptor: %d\n", fd);

    close(fd);  // Close the file when done
    return 0;
}
```
---
### Simple Example 2: Create and Write to a File
```c
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT, 0644);

    if (fd == -1) {
        perror("Error creating file");
        return 1;
    }

    write(fd, "Hello, world!\n", 14);

    printf("Data written successfully!\n");

    close(fd);  // Close the file
    return 0;
}
```

### references: 
For more information (there is a lot more) check these website it will show you how to create new files + open for exemple: 
    - https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/