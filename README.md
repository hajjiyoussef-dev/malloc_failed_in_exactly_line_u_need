# Custom Malloc Failure Wrapper

## Overview
This project provides a simple way to **simulate a `malloc` failure** in C.  
It replaces all calls to `malloc` with a custom wrapper that can deliberately fail under certain conditions (based on the source file and line number).

This technique is useful for testing how your program handles memory allocation errors, without needing to wait for a real `malloc` failure (which is rare on modern systems).

---

## How It Works
The code defines a function `p()` and a macro that replaces `malloc`:

```c
#include <string.h>
#include <stdlib.h>

static inline void *p(size_t size, char *file, int line)
{
    if (strstr(file, "main.c") && line == 22)
        return (NULL); // Force malloc to fail at main.c:22
    return (malloc(size));
}

#define malloc(x) p((x), __FILE__, __LINE__)

