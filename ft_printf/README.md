# FT_PRINTF

A recreation of the function printf in the standard C library.

## Details

Currently replicates standard printf.  Future plans will include sprintf and dprintf, wildcard width/precision support, colors, and adding the double converter 'f'.

### Flags supported

- '**#**', which inserts a prefix to binary, octal, and hexadecimal conversions.
- '**0**', which replaces left-padding spaces with zeroes. Ignored if precision is used with non-double number conversions.
- '**-**', which changes padding to be on the right side of the conversion. Overrides '**0**' flag.
- ' ', which adds a space to the left of signed conversions, currently only 'd' and 'i'.
- '**+**', which adds a '+' to the left side of signed conversions. Overrides ' ' flag.
- **minimum field width**, which keeps a specific string length when printing the conversion, although if it's smaller than the conversion, the length of the conversion is used instead.
- **precision**, marked by a '**.**', to add zeroes to non-double digit conversions, or restrict the number of characters for an 's' conversion to be printed.

### Length Modifiers supported

Specifies size for what is being converted.

**Modifier** | *d, i* | *o, u, x, X* | *c* | *s*
------------ | ------ | ------------ | --- | ---
**hh** | *char* | *unsigned char* | *none* | *none*
**h** | *short* | *unsigned short* | *none* | *none*
**ll** | *long long* | *unsigned long long* | *none* | *none*
**l** | *long* | *unsigned long* | *wint_t* | *wchar_t*
**j** | *intmax_t* | *uintmax_t* | *none* | *none*
**z** | *ssize_t* | *size_t* | *none* | *none*

### Conversions supported

- **diouxX**: **d** and **i** are signed ints, **o**, **u**, **x**, and **X** are unsigned ints.  **o** converts decimal to octal, **x** and **X** converts to hexadecimal.  **x** uses lowercase letters and **X** uses uppercase.
- **DOU**: Changes conversion to long int, the same as **ld**, **lo**, and **lu**.
- **cs**: **c** changes int argument to unsigned char and prints approprioate character.  **s** points to a character string argument and prints it.
- **CS**: Same as **lc** and **ls**.
- **p**: Void* argument prints as hexadecimal.
- **%**: Prints a '**%**'.

### Extras

These are extra conversions I implemented for more flexibility.

- **b**: Converts digit to binary.  Same flag support as **o** and **x**.
- **k**: Adds the current system time.  Doesn't use an argument.

## Examples

```
ft_printf("Hello, World!"); // prints 'Hello, World!'

ft_printf("%d times fast.", 3); // prints '3 times fast.'

ft_printf("Down by the %s side", "beach"); // 'Down by the beach side'

ft_printf("Today is %k"); // 'Today is Mon Oct 15 15:18:00 2018'

ft_printf("%#5o", 23); // '  027'

ft_printf("%#b", 184); // '0b10111000'
```

## About

This project aims to demonstrate C knowledge by remaking printf.  Not all functionality will be inserted.

This project was originally created by 42 Silicon Valley.
