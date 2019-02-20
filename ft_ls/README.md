# FT_LS

A recreation of the system command ls using C.

## Details

Able to use the flags **A**, **a**, **c**, **F**, **f**, **G**, **l**, **R**, **r**, **t**, **u**.

Without flags, ft_ls prints as if the '1' flag is used, which lists items vertically.

### 'l' Flag

Replicates the l flag of the original very well.  Shows all attributes accordingly.

```
-rw-r--r--  1 user  group   2122 Feb 19 19:52 Makefile
-rw-r--r--  1 user  group    268 Feb 19 21:00 README.md
-rwxr-xr-x  1 user  group  52012 Feb 19 21:09 ft_ls
drwxr-xr-x  2 user  group   4096 Feb 19 19:21 include
drwxr-xr-x  3 user  group   4096 Feb 19 21:07 libft
drwxr-xr-x  2 user  group   4096 Feb 19 19:21 src
```

Width is adjusted the same way as ls, where it checks the length of eery category and makes the same space for them all to organize in a readable manner.

For permissions, it is able to recognise extended attributes, ID settings of user and group, and sticky bit. It is able to see if a file is a block, character, symbolic link, socket link, and fifo files as well as regular files and directories.

### Other Flags

* **a**: lists all hidden items as well as regular items
* **A**: works like **a** but discludes '.' and '..' items
* **c**: sorts based on when file status was last changed when used with 't'; shows the appropriate time when using 'l' flag
* **F**: inserts a character at the end of the name to indicate type of item; '/' for directory, '\*' for executables, '@' for symbolic links, '=' for sockets, '%' for whiteouts, and '|' for fifo
* **f**: Doesn't sort before printing
* **G**: Inserts colors for item names
* **R**: Recursively displays all items in all directories beginning with starting directory
* **r**: Reverses sorting order
* **t**: Sorts by time modified.
* **u**: Sorts based on time of item creation when used with 't'; shows the appropriate time when using 'l' flag

## About

This project aims to demonstrate C knowledge by remaking ls.

This project was originally created by 42 Silicon Valley.
