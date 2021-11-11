# Testr

Testr is a seemingly-modern-yet-very-small testing framework (read macro collection). It defines only 3 
variables, one temporary variable, and *0 functions!* Testing is really easy:

```c
#include <stdio.h>
#include "testr.h"

int main() {
	TEST(1==1);
	return 0;
}
```

This will provide beautiful colorized output. But what if you want the number of tests, how many worked 
and how many failed? What if you just want it to look more like an  *actual*, *good* testing framework? 
Well, Testr can cater to that:

```c
#include <stdio.h>
#include "testr.h"

int tests() {
	TESTR_BEGIN;
	TEST(1 == 1);
	TEST(1 == 0);
	TESTR_END;
}

int main() {
	return tests();
}
```

(Note that `TESTR_END` actually returns the value, meaning you can't return another value after that. 
This will probably be fixed in the future). This gives you much fancier output, with banners and 
overall test information. See `testr_example.c` for a more detailed example.

However, when you're compiling, wouldn't this add unnecessary bloat to your code? **WRONG!!!** Since
all of the functions are actually macros, this means that all code would be inlined. And since only 4
bytes *max* are used, this doesn't add much of a memory bloat. You can even disable tests by setting
the global variable `on` to 0, disabling all printing of test results.

Testr is an elegant way to unit test, but if you want to put your testing in the hands of a 5 line
testing framework ... be my guest! I'm not going to stop you!

## Documentation

### P

Internal alias for `printf` which only prints when `on` is true. Can be used for logging, if you're
so inclined.

### TESTR\_BEGIN

Prints out a banner and initializes variables to their proper variables. Can (and should) be used
before any test cases.

### TEST

Actual testing function. Can be used independantly of the other two functions, but not recommended.
Prints out a success message in green if the value passed to it is true, otherwise it prints out
a failure message in red including the line number, file, and the test number.

### TESTR\_END

Prints out a banner and displays the data compiled up to the point where it was called, namely the
number of successes and the number of failures.

### Variables

#### on

An integer (char actually, but who cares) which specifies whether to print tests or not. If 0, tests
are effectively disabled.

#### s

Internal variable. Used to keep track of the number of successes.

#### f

Internal variable. Used to keep track of the number of failures.
