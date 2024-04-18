# Get Next Line (GNL) - Bonus

## Overview
The Get Next Line (GNL) project is a C programming challenge that involves writing a function that reads a line ending with a newline character (`'\n'`) from a file descriptor. The bonus part of the project extends the functionality to handle multiple file descriptors simultaneously, allowing the user to read from different file descriptors in an interleaved manner without losing the reading thread of each one.

## Features
- Reads lines ending with a newline character.
- Supports multiple file descriptors.
- Maintains the reading state of each file descriptor independently.
- Utilizes a single static variable for state management.

## Usage
Include `get_next_line_bonus.h` in your project and compile with `get_next_line_bonus.c` and `get_next_line_utils_bonus.c`.

```c
#include "get_next_line_bonus.h"
int main() {
int fd = open("example.txt", O_RDONLY);
char line;
while ((line = get_next_line(fd)) != NULL) {
printf("%s", line);
free(line);
}
close(fd);
return 0;
}
```

## Compilation
Compile with the following command, adjusting `BUFFER_SIZE` as needed:
```bash
gcc -D BUFFER_SIZE=32 -o gnl_bonus get_next_line_bonus.c get_next_line_utils_bonus.c main.c
```


## Contributing
Feel free to fork, make improvements, and submit pull requests.
