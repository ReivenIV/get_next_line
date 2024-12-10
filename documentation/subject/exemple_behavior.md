# How the program should work ? 

in some FD file you have some data (imagine its important data): 
```
These \nchicken r\nun fast\0
```

char *get_next_line(int fd); (program runned with buffer 5)

becase the buffer is 5 read will read by 5 bits. 
will work in these way: 
```
These \nchicken run super\n fast\0
123451 234512345123451234 512345 1
```

1. call to function 
static reminder = 0
raw_line = "These \nchi"
output = "These \n"

2. call to function 
static reminder = "chi"
raw_line = "cken run super\n"
output = chicken run super\n

3. call to function 
static reminder = 0
raw_line = " fast\0"
output = " fast\0"

4. call to function 
static reminder = 0
output =  NULL (the way to say is the end of the file.)