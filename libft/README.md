# Standard Library Recreation

Recreated select functions plus some custom functions to use as personal library.

## Details

### Standard library functions

These functions mimic the standard library equivelants.

- **ft_atoi**
- **ft_bzero**
- **ft_isalnum**
- **ft_isalpha**
- **ft_isascii**
- **ft_isdigit**
- **ft_isprint**
- **ft_memccpy**
- **ft_memchr**
- **ft_memcmp**
- **ft_memcpy**
- **ft_memmove**
- **ft_memset**
- **ft_pow** (for int type; use ft_dpow for double)
- **ft_putchar**
- **ft_strcat**
- **ft_strchr**
- **ft_strcmp**
- **ft_strcpy**
- **ft_strdup**
- **ft_strlcat**
- **ft_strlen**
- **ft_strncat**
- **ft_strncmp**
- **ft_strncpy**
- **ft_strnstr**
- **ft_strrchr**
- **ft_strstr**
- **ft_tolower**
- **ft_toupper**

### Custom functions

These created functionality that wasn't found in standard library.

- **ft_atoi_base**: like ft_atoi, but outputs number according to specified base
- **ft_dlen**: length of a double type number, including decimal point.
- **ft_dtoa**: converts double type to ascii string
- **ft_exit**: calls exit function.
- **ft_fndfile**: returns the file or directory name without the file path.
- **ft_fndpath**: returns the file path without the file name.
- **ft_itoa**: converts int type to ascii string.
- **ft_ldlen**: length of a long double type number, including decimal point.
- **ft_ldtoa**: converts long double type to ascii string
- **ft_memalloc**: allocates memory and ensures its contents are unset.
- **ft_memdel**: frees memory of parameter and points it to NULL.
- **ft_nlen**: length of an int type number, including decimal point.
- **ft_llpow**: like pow, but uses long long return type and int parameter types.
- **ft_ldpow**: like pow, but for long double (standard library 'powl' equivelant).
- **ft_puchar_fd**: putchar with being able to select file descriptor.
- **ft_putstr**: prints a string.
- **ft_putstr_fd**: prints a string to the file descriptor.
- **ft_putnbr**: converts an int type to a string then prints it.
- **ft_putnbr_fd**: converts an int type to a string then prints it to file descriptor.
- **ft_putendl**: prints a string then prints a new line.
- **ft_putendl_fd**: prints a string then prints a new line to file descriptor.
- **ft_putnbrendl**: converts an int type to a string, prints it, then prints a new line.
- **ft_putnbrendl_fd**: converts an int type to a string, prints it, then prints a new line to file descriptor.
- **ft_putnstr**: prints a number of characters up to n.
- **ft_putnstr_fd**: prints a number of characters up to n to file descriptor.
- **ft_realstrcmp**: like strcmp, except returns only either a -1, 0, or 1.
- **ft_realstrncmp**: like strncmp, except returns only either a -1, 0, or 1.
- **ft_revsort**: sorts a char type container in reverse with specified sorting algorithm.
- **ft_sort**: sorts a char type container with specified sorting algorithm.
- **ft_splitlen**: returns the length of a container (array of strings).
- **ft_strbcpy**: uses bzero, then strcpy.
- **ft_strclr**: resets a string to nil.
- **ft_strdel**: frees a string and then sets it to NULL.
- **ft_strequ**: returns a boolean if two strings have the same content.
- **ft_striter**: uses the specified function with a string param for the string
- **ft_striteri**: uses the specified function with int type and string params for the string.
- **ft_strjoin**: like strcat, excepts creates a new string instead or returning first one.
- **ft_strlen_diff**: difference in length between two strings.
- **ft_strmap**: uses the specified function for each character with a string param to create a new string.
- **ft_strmapi**: uses the specified function for each character with int type and string params to create a new string.
- **ft_strnequ**: returns a boolean if two strings have the same content up to n.
- **ft_strnew**: allocates memory to a string.
- **ft_strrev**: reverses a string and returns it.
- **ft_strsplit**: splits a string at every instance of a specified character.
- **ft_strsub**: copies a string starting from first int type with a specified length.
- **ft_strswch**: switches the addresses between the specified char types.
- **ft_strtrim**: returns a new string eliminating empty white space in the beginning and end of the specified string.
- **ft_word_count**: counts how many 'words' there are in a string.
- **ft_word_cpy**: similar to strncpy but no return, and n is the character to stop at.
- **ft_word_len**: returns the length of a string up to the specified character.
- **get_next_line**: retrieves a string from an open file up to new line.

### Linked-List

These functions manipulate a linked-list with the specified struct:

```C
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
```

- **ft_lstnew**: creates a new node.
- **ft_lstadd**: add a node to the end of the list.
- **ft_lstdelone**: deletes specified node
- **ft_lstdel**: deletes list.
- **ft_lstiter**: uses the specified function for each node of the linked-list.
- **ft_lstmap**: uses the specified function for each node of the linked-list to create a new list.

### Ft_printf

#### For ft_printf functionality, see [README](https://github.com/EarthBoundMic/42_projects/blob/master/ft_printf/README.md).

## About

This project aims to demonstrate C knowledge by remaking standard library functions.  Not all functions will be inserted.

This project was originally created by 42 Silicon Valley.
