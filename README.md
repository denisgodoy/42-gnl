![Unix](https://img.shields.io/badge/Unix-306998) ![Rigor](https://img.shields.io/badge/Rigor-306998) ![Algorithms&AI](https://img.shields.io/badge/Algorithms&AI-306998)

# get_next_line 💻
May it be a file, stdin or a network connection, get_next_line function will read content line by line.

- [Evaluation](https://github.com/denisgodoy/42-gnl#evaluation)
- [Mandatory part](https://github.com/denisgodoy/42-gnl#mandatory-part)
- [Bonus part](https://github.com/denisgodoy/42-gnl#bonus-part)

## Evaluation
![evaluation](https://user-images.githubusercontent.com/56933400/131925748-9e4015a1-05bb-4b58-864c-08deec8d560e.png)
![badge](https://game.42sp.org.br/static/assets/achievements/get_next_linem.png)

## Mandatory part
Calling get_next_line in a loop will allow you to read the text available on the file descriptor one line at a time.

| Function 	|  Description  |    External functions   	|
|:--------:	|:------------:	|:------------:	|
|  get_next_line  	|Returns a line read from a file descriptor.|   read, malloc, free   	|

To compile the program, modify the BUFFER_SIZE value `xx`.
```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c
```

## Bonus part
Use only one static variable and handle multiple file descriptors without losing the reading thread.
