# How the program should work ? 

imagine in some FD file you have these data : 
```
These \nchicken run super\n fast\0
```

char *get_next_line(int fd); (program runned with buffer 5)

becase the buffer is 5 read will read by 5 bits. 
will work in these way: 
```
These \nchicken run super\n fast\0
123451 234512345123451234 512345 1
```

1. call to function 
static stash = '\0'
raw_line = "These \nchi"
output = "These \n"

2. call to function 
static stash = "chi"
raw_line = "cken run super\n"
output = chicken run super\n

3. call to function 
static stash = '\0'
raw_line = " fast\0"
output = " fast\0"

4. call to function 
static stash = '\0'
raw_line = '\0'
output =  NULL (the way to say is the end of the file.)

//edge case double \n\n
99. call to function 
static stash = ''
raw_line = "These \nchi\n"
output =  NULL (the way to say is the end of the file.)