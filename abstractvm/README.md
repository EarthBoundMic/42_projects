# ABSTRACTVM

A simple virtual machine that can interpret programs written in a basic assembly language.  It is written in C++.

## Details

The program can be used either with standard input, or with a *.avm* file.  Examples of such files are inside the *testfiles* directory.

The virtual machine queues commands to be used for creating data, and stores data on a stack.  The commands revolve around number manipulation, storing them, performing basic arithmetic, and printing what has been stored.

### Commands

There are a total of 12 commands.  Two of them require additional input as they are required to either insert the data you want, or check if the front of the stack is the data you are expecting.

*comments*: Files can have comments within by using **;** to indicate start of comment.  They can have their own lines or come after a command.

#### Command Definitions

**push** *v*: Inserts data v to the stack. v must have the following form:

- **int8**(*n*) : Creates an 8-bit integer with value *n*.
- **int16**(*n*) : Creates a 16-bit integer with value *n*.
- **int32**(*n*) : Creates a 32-bit integer with value *n*.
- **float**(*z*) : Creates a float with value *z*.
- **double**(*z*) : Creates a double with value *z*.

**assert** *v*: Checks if the the top of the stack is equal to the parameter of the instruction.  Both the type and the number must be exact, or an error is thrown.

**pop**: Removes the current top of the stack.  Errors if the stack is empty.

**dump**: Prints all the values of the stack, starting with the top, each one seperated by a newline.

**print**: Prints the top value of the stack into a character.  Asserts if the value is an int8 type first.

The following are the arithmetic operations.  Each one errors if there aren't enough values to do the arithmetic with.

**add**: Performs the addition operation with the top value and the next value.

**sub**: Performs the subtraction operation with the top value and the next value.

**mul**: Performs the multiplication operation with the top value and the next value.

**div**: Performs the division operation with the top value and the next value.

**mod**: Performs the modulo operation with the top value and the next value.

For sub, div, and mod, the notation is (next op top), as in top value performs operation from next value.

For div and mod, if top is a zero, then an eror is thrown.

**exit**: Stops the execution of the commands.  Any commands inserted after exit are ignored.

**;;**: Exclusive to standard input.  Terminates program.  Must use exit command beforehand or an error is thrown.

Note 1: When performing arithmetic operations, the values used for the calculation are removed from the stack, and the new value is pushed.

Note 2: A strict check is performed to make sure a number doesn't go beyond the scope of the type of the value.  As such, make sure you aren't causing numbers to overflow or underflow.

#### Syntax

Because the virtual machine is looking for specific commands in a specific manner, much control has been inserted where any faults in the input will result in thrown exceptions.  As such, a specific syntax is required to properly execute any command.

(**#** corrsponds to end of input)

:= INSTR [SEP INSTR]* #

INSTR :=
   push VALUE
   | pop
   | dump
   | assert VALUE
   | add
   | sub
   | mul
   | div
   | mod
   | print
   | exit

VALUE :=
   int8(N)
   | int16(N)
   | int32(N)
   | float(Z)
   | double(Z)

N := [-]?[0..9]+

Z := [-]?[0..9]+.[0..9]+

SEP := '\n'+

#### Precision

The value types are handled by a precision hierarchy.  When performing arithmetic operations, if both values are different, the higher precision type takes priority when creating the new value.

The following is used to show the priority:

**int8 < int16 < int32 < float < double**

For example:

push int16(24)
push float(3.75)
add

the result would be a value of float(90)

### The Code

A big part of the project is how the code is handled.  Using a [factory pattern](./includes/Operands.hpp) is mandatory for selecting which type to be made and pushed into the stack. Each type class must in the form of the interface class [IOperand](./includes/IOperand.hpp), plus the enum used.  The use of the actual stack container was forbidden as well.

Well structured exception handling is also mandatory, with maximum grade creating custom exceptions inheriting from std::exception.

### Bonuses

Normally, upon reaching the first error, the program is supposed to stop.  A bonus is to display all errors before stopping.

Clearly defined lexer/parser couple.  Basically, clean code for creating tokens and parsing them.

## ABOUT

This project aims to demonstrate C++ knowledge by cleverly using classes to create an assembly language virtual machine.

This project was originally created by 42 Silicon Valley.
