<h1 align="center"> ft_printf ✏️ </h1>

<p align="center"> ft_printf is a 42 project that aims to recode the printf function. </p>

<p align="center"> <img src="https://img.shields.io/badge/Grade-100%2F125-brightgreen"> <img src="https://img.shields.io/badge/Language-C-blue"> <img src="https://img.shields.io/badge/Status-Completed-brightgreen"> </p>

## 📖 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Authors](#authors)

## 🧐 About <a name = "about"></a>

ft_printf is a 42 project that aims to recode the printf function. The function must be able to manage the following conversions: cspdiuxX% and manage any combination of the following flags: ’-0.*’ and minimum field width with all conversions.

## 🏁 Getting Started <a name = "getting_started"></a>

### Prerequisites

- gcc compiler (gcc 9.3.0) or higher version (https://gcc.gnu.org/)
- make (https://www.gnu.org/software/make/) (optional)

### Installing

- Clone the repository

```bash
git clone git@github.com:dugonzal/ft_printf.git

cd ft_printf
```

- Compile the library

```bash
make
```
###    header
```c
#include "ft_printf.h"
```

## 🎈 Usage <a name="usage"></a>

- Compile your program with the library

```bash
include "ft_printf.h" in your header file and compile with the library

gcc -Wall -Wextra -Werror -I. -L. -libft_printf.a your_program.c

```

- Include the library in your program
## example

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello World!");
	return (0);
}
```

## ✍️ Authors <a name = "authors"></a>

- [@dugonzal]

