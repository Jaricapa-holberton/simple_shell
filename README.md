#Simple_shell

###Content

Description
This project is a simple UNIX command language interpreter that reads and
executes commands from either a file or standard input.

What is the shell? A Unix shell is a command-line interpreter or shell that
provides a command line user interface for Unix-like operating systems The
first Shell Unix sh was written by Ken Thompson working at Bell Labs and
called Thompson shell Version 1. The last version is the 6. An ultimate
variation of Shell is called Bourne Against Shell -BASH written by
Stephen Bourne at Bell Labs too. Distributed as the shell for UNIX Version
7 in 1979

[Authors]
# Authors

 👤 **Jaime Andrés Aricapa**

- Twitter: [@Jaime95_Aricapa](https://twitter.com/Jaime95_Aricapa)
- Github: [@Jaricapa-holberton](https://github.com/Jaricapa-holberton)

👤 **Frank J. Grijalba H.**

- Twitter: [@FrankGrijalba](https://twitter.com/FrankGrijalba)
- Github: [@FRANK-GRIJALBA](https://github.com/FRANK-GRIJALBA)

Invocation
Usage: sHell [filename]

To invoke sHell, compile all .c files in the repository with the
flag -o sHell and run the executable:

gcc -Wall -Werror -Wextra -pedantic gcc -Wall - *.c -o sHell
./sHell
sHell can be invoked both interactively and non-interactively.

Interactive mode: sHell is connected to a terminal and displays the prompt
$ when it is ready to read a command.

Example:

$./sHell
$
Non interactive mode If sHell is invoked with standard input not connected
to a terminal, it reads and executes received commands in order.

Example:

$ echo "echo 'Holberton'" | ./sHell
'Holberton'
$
Cat redirection You can get the same result using the command cat.

Example:

$ cat test_cat | ./sHell
'Hello'
"World"
/home/user/simple_shell
$
Example of Use

$ ls -l

:~$ ls -l
total 48
drwxrwxr-x  7 vagrant vagrant 4096 Nov 21 01:17 0x15.c
drwxrwxr-x  5 vagrant vagrant 4096 Sep 16 15:42 Betty
drwxrwxr-x 16 vagrant vagrant 4096 Nov 13 16:38 gdb-7.11
drwxrwxr-x  7 vagrant vagrant 4096 Sep  9 23:10 holbertonschool-zero_day
drwxrwxr-x  7 vagrant vagrant 4096 Nov 14 00:51 preshell
drwxrwxr-x  3 vagrant vagrant 4096 Oct 28 20:17 printf
drwxrwxr-x  4 vagrant vagrant 4096 Oct 27 23:42 printf_
drwxrwxr-x  3 vagrant vagrant 4096 Sep 21 14:56 Prueba
drwxrwxr-x  3 vagrant vagrant 4096 Nov 26 02:13 simple_shell
drwxrwxr-x  7 vagrant vagrant 4096 Nov 24 03:33 temptest

Authors
XXX <nick>
XXX <nick>
