# sorun
A project for learning how to use dynamic libraries on UNIX systems. It is used to run special dynamic libraries (.so files).
There are no real use cases for this program and it was created for learning purposes only.

## Compiling
The launcher, sorun.c, is compiled into a normal executable:
```
clang sorun.c -o sorun
```
The core, cmd.c, includes the commands that are used in the user interface. The core is loaded dynamically by the launcher and is compiled into a shared object:
```
clang -shared -undefined dynamic_lookup -o core/cmd.so core/cmd.c
```

Other programs, or dynamic libraries, are launched with run command defined in the core. An example program, attach/run.c, is provided and it, as well as other programs, should be compiled like the core:
```
clang -shared -undefined dynamic_lookup -o run.so attach/run.c
```

## Usage
The program is launched using ```./sorun```

All functional commands are defined in the core.
Currently working commands are: help, info, run, quit

The example program can be launch with
```
run path/to/run.so
```
in the sorun user interface.

## Programs
The run command opens the program given as an argument and looks for a function named start. If start function is found, the program is run.
Similar to the main function in C the start function returns integer and has two arguments (although arguments cannot be used in the current version):
```
int start(int argc, char *argv)
```

### Example program - run.so
The example program runs inside to sorun environment with the following output:
```
[sorun]
> run run.so
[executing]

Hello world!
test function

[finished]
> quit
[closing]
```
