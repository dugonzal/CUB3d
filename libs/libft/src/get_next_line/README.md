<h1 align= center> GET NEXT LINE </h1>

<h2 align= center> 42 Project </h2>

## DESCRIPTION
This project is about making a function that returns a line ending with a newline, read from a file descriptor.

## PROTOTYPE
```c
int get_next_line(int fd);
```
- fd: file descriptor for reading
- line: The value of what has been read

## RETURN VALUES
- 1 : A line has been read
- 0 : EOF has been reached
- -1 : An error happened

## HOW TO USE
```bash
git clone git@github.com:dugonzal/get_next_line.git
cd get_next_line
bash script/make.sh
```

## HOW TO TEST
```bash
bash script/test.sh
```

## AUTHOR
- **Duvan Gonzalez** - [ dugonzal ]
