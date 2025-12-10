# Solitude

> A written guide on how to become a better system-level debugger, through a series of practical exercises.

### How to use this guide

Each exercise/example is numbered and totally self-sufficient. They work in isolation and have no dependencies on any other exercises.

The following tools are needed to run the examples:

- Clang or GCC (defaults to Clang)
- GNU Make
- GNU GDB

### `01-segfault`

This is a classic example of a trivial segmentation fault.

The `segfault-release` binary simply exits with a SIGSEGV (exit code 139, signal 11).

The `segfault-debug` binary, while we could use the compiler's address sanitiser, does not do this.

Instead, we build it without ASan, and a `capture.sh` detects if the process dies due to a segmentation fault, runs GDB on it, and captures a full backtrace.

### `02-use-after-free`

For this example, we allocate 4 contiguous integers, set their individual values to [1, 2, 3, 4], and try to sum them, which should produce 10.

However, before summing the integers, we free the memory where they had been allocated.

Thus, the sum produced is seemingly random, as the pointer still holds its original value, whereby reading from it, after it's been freed, is undefined behaviour.

The `release` build displays this undefined behaviour, and the `debug` build uses ASan, which immediately reveals the issue.

### `03-double-free`

We allocate an integer, then attempt to free it twice.

While ASan would reveal the issue, it doesn't help us track it down too well.

So here, for the `debug` build, ASan is turned off, and a `capture.sh` script (another GDB wrapper) helps us track down where the issue happens.

But the debug flags themselves are good enough, too.

The `release` build simply displays the issue, and has no debug information whatsoever.

### `04-stack-buffer-overflow`

In this example, we deliberately write more data into a fixed-size stack buffer than it can hold, overflowing into adjacent memory.

This is a common pattern in real programs that use unsafe string or memory functions without checking lengths first.

Depending on the build and platform, the program may abort immediately with a stack smashing warning, or appear to run and only fail later in a less obvious way.

The goal here is to practice locating the overflowing write and relating the crash (or strange behaviour) back to the small local buffer that caused it.

For the `debug` build, ASan is enabled, which displays the issue more clearly.

For the `release` build, the results are not deterministic. The program may work fine if the input provided is short enough, or it may die with a segmentation fault if the process tries to access an invalid memory address. We can also change the boolean value of the `authenticated` variable.
