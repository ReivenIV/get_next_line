# Why we use BUFFER_SIZE ?

**`BUFFER_SIZE`** is a constant that defines how many bytes the function reads from the file at one time. Think of it as the size of the "bucket" used to fetch data from the file. 

### **Why Use `BUFFER_SIZE`?**
- **Memory Efficiency**: Instead of reading the whole file at once (which might be very large), the function reads in smaller chunks.
- **Performance**: Reading in chunks balances speed and memory usage. Too small a value causes many reads (slow), and too large wastes memory.
- **Flexibility**: By changing `BUFFER_SIZE`, you can control how much data gets read at each step.

### **Example**
- If `BUFFER_SIZE` is `4`, the function reads 4 bytes at a time.
- If the file contains `"Hello, world!"`, the function might read it in chunks like:
  - `"Hell"`
  - `"o, w"`
  - `"orld"`
  - `"!"`

This makes the reading process manageable and prevents memory overload. 

