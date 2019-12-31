# Sash

## Introduction

Sash (the *Super Awesome SHell*) is a tiny POSIX shell. It has been written and tested on Linux but it should work on any UNIX-like system. It has been inspired by Stephen Brennan's [LSH](/uri "https://brennan.io/2015/01/16/write-a-shell-in-c/"), but doesn't use any code from it.

I am developing it mostly as a learning project. Completeness is not a major goal, although I intend to slowly add extra features. Full POSIX compliance may never be reached, but I would like to get to a shell that is complete enough for daily use.

## Features

For now, sash is *extremely* bare bones. The only builtin command so far is 'exit', which terminates the shell with status code 0. It can also launch programs, but that's it. So, a partial list of things that are *not* supported yet is:

- Piping
- Redirection
- Quotting
- Globbing
- Variables
- Any sort of scripting functionality
- Other useful builtins, including even cd
- Customizing the prompt

Some of these may be added in the future.
