# FT_PRINTF

A recreation of the function printf in the standard C library.

## Details

Currently replicates standard printf.  Future plans will include sprintf and dprintf.

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

**Modifier** | *d, i* | *o, u, x, X* | *c* | *s* | *f*
------------ | ------ | ------------ | --- | --- | ---
**hh** | *char* | *unsigned char* | *none* | *none* | *none*
**h** | *short* | *unsigned short* | *none* | *none* | *none*
**ll** | *long long* | *unsigned long long* | *none* | *none* | *none*
**l** | *long* | *unsigned long* | *wint_t* | *wchar_t* | *double*
**j** | *intmax_t* | *uintmax_t* | *none* | *none* | *none*
**z** | *ssize_t* | *size_t* | *none* | *none* | *none*
**L** | *none* | *none* | *none* | *none* | *long double*

### Conversions supported

- **diouxX**: **d** and **i** are signed ints, **o**, **u**, **x**, and **X** are unsigned ints.  **o** converts decimal to octal, **x** and **X** converts to hexadecimal.  **x** uses lowercase letters and **X** uses uppercase.
- **DOU**: Changes conversion to long int, the same as **ld**, **lo**, and **lu**.
- **fF**: float handling with doubles.  Prints trailing zeroes depending on precision. **f** prints *inf* and *nan*, and **F** *INF* and *NAN* when appropriate.
- **cs**: **c** changes int argument to unsigned char and prints approprioate character.  **s** points to a character string argument and prints it.
- **CS**: Same as **lc** and **ls**.
- **p**: Void* argument prints as hexadecimal.
- **%**: Prints a '**%**'.

### Extras

These are extra conversions I implemented for more flexibility.

- **b**: Converts digit to binary.  Same flag support as **o** and **x**.
- **k**: Adds the current system time.  Doesn't use an argument.
- **{}**: Depending on keywords, can manipulate how the text looks, otherwise prints normal.  See Escape sequence support below for details.

## Examples

```C
ft_printf("Hello, World!"); // prints 'Hello, World!'

ft_printf("%d times fast.", 3); // prints '3 times fast.'

ft_printf("Down by the %s side", "beach"); // 'Down by the beach side'

ft_printf("Today is %k"); // 'Today is Mon Oct 15 15:18:00 2018'

ft_printf("%#5o", 23); // '  027'

ft_printf("%#b", 184); // '0b10111000'

ft_printf("%.3f", 123.4567); // '123.457'
```

## Escape sequence support

### Added text manipulation support

When inserting specific keywords within curly brackets '**{}**', can change how text looks.
Can insert one keyword per curly brackets, or multiple with seperating each keyword with a semicolon '**;**'.

```C
ft_printf("{BLUF}{BOLD;UNDR}");
```

If just one keyword is invalid within a curly bracket pair, will print it all as standard text.

For convenience, all keywords are four letters long.

#### Resetting escape sequences

Resetting is as easy as setting the manipulations in the first place.  The following are the keywords to reset certain escape sequence parameters:

- **NBOF**: 'no bold or feint'; disables bold/feint font
- **NITL**: 'no italic'; disables italic font
- **NUND**: 'no underline'; disables underline font
- **NBLK**: 'no blink'; disables fast/slow blink
- **NCRS**: 'no cross-out'; disable cross-out font
- **DEFF**: 'default foreground'; resets text color to default
- **DEFB**: 'default background'; resets background text color to default
- **RSTA**: 'reset all'; turns off all escape sequences

#### Setting escape sequences

Not all settings are univerally supported.  Check your operating system to see which sequences can be used.

- **BOLD**: bold font
- **FENT**: feint font
- **ITLC**: italic font
- **UNDR**: underline font
- **SBLK**: slow blink
- **FBLK**: fast blink
- **CSWP**: color swap; switches foreground and background colors with each other
- **CRSO**: cross-out
- **BLKF**: black foreground
- **BLKB**: black background
- **REDF**: red foreground
- **REDB**: red background
- **GRNF**: green foreground
- **GRNB**: green background
- **YLWF**: yellow foreground
- **YLWB**: yellow background
- **BLUF**: blue foreground
- **BLUB**: blue background
- **MGNF**: magneta foreground
- **MGNB**: magneta background
- **CYNF**: cyan foreground
- **CYNB**: cyan background
- **WHTF**: white foreground
- **WHTB**: white background

## About

This project aims to demonstrate C knowledge by remaking printf.  Not all functionality will be inserted.

This project was originally created by 42 Silicon Valley.
