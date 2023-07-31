<h1 align="center">
	📚 libft
</h1>

<p align="center">
	<b><i>FIRST LIBRARY</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/dugonzal/libft" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/dugonzal/libft" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/dugonzal/libft">
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/dugonzal/libft?color=green" />
	<img alt="GitHub closed issues" src="https://img.shields.io/github/issues-closed/dugonzal/libft" />
	<img alt="GitHub pull requests" src="https://img.shields.io/github/issues-pr/dugonzal/libft" />
	<img alt="GitHub closed pull requests" src="https://img.shields.io/github/issues-pr-closed/dugonzal/libft" />

---
**3. Using it in your code**


You can use this library in your code by cloning this repository and compiling it with your code. You can also use the Makefile to compile the library and your code:

```C
#include "libft.h"
```

##  What is libft?

> _Libft is an individual project at [42](https://42urduliz.com/) that consists of recoding a set of the standard C library functions, as well as other utility functions that are useful for any C program._

## List of functions:


| Function | Description |
| :--- | :---- |
ft_is | Checks if the character is a digit, letter, lowercase, uppercase, or printable.
ft_lst | Functions to manipulate linked lists.
ft_mem | Functions to manipulate memory.
ft_put | Functions to print characters, strings, and integers.
ft_str | Functions to manipulate strings.
ft_tol | Functions to convert characters to integers and vice versa, converting to lowercase and uppercase.
octet  | functions for manipulating octets

### Instructions

**1. Compiling the library**

To compile the library, go to its path and run:

For all mandatory functions:

```shell
 make
```

**2. Cleaning all binary (.o) and executable files (.a)**

To clean all files generated while doing a make, go to the path and run:

```shell
 make fclean
```

<h4>examples</h4>

```c
#include "libft.h"

int main(void)
{
	ft_isalnum(0);
	ft_bzero(0, 0);
	ft_puchar_fd("hello world", 1);
	ft_split("hello world", ' ');
	ft_strchr("hello world", ' ');
	return (0);

}

```
