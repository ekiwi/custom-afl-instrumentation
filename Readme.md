# Custom AFL Instrumentation Example

This repository contains a library (`afl.c`, `afl.h`)
based on the llvm runtime from [AFL](http://lcamtuf.coredump.cx/afl/).
This library makes it easy to provide custom coverage
feedback to AFL, replacing AFLs custom instrumentation which
uses branch coverage as its main metric.


## Example Program

A very simple example (provided in `main.c`) looks like this:

~~~{.c}

int main() {
	afl_init();

	switch(getc(stdin)) {
		case 'a':
			afl_set('a', 1);
		case 'b':
			afl_set('b', 1);
		case 'c':
			afl_set('c', 1);
		default:
			afl_set(0, 1);
	}
}

~~~

Here `afl_init` initialized the shared memory region and
the pipes that are used to communicate with AFL.
It also starts the
[fork server](http://lcamtuf.blogspot.com/2014/10/fuzzing-binaries-without-execve.html)
which will allow AFL to execute your code after the call to `afl_init`
over and over again without reloading your binary.

The provided example program now reads one byte from `stdin` and gives different
feedback depending on its content.
Thus we expect AFL to come up with 4 different inputs which correspond to
4 different paths. One should correspond to `a`, one to `b`, one to `c` and
the other to something other than `a`, `b` or `c`.

## Running the Example

To run the example, you can use the included `Makefile`.
You will probably need to adjust `AFL_DIR` to point
to your local checkout of AFL.

Then just type: `> make run`

This starts AFL which will begin fuzzing your binary.
Pretty quickly the number of `paths` should go up to `4` after which you can
stop AFL (`Ctrl + c`).

Now you can have a look at `out/queue` to inspect the inputs that AFL produced.

That's it. Happy Fuzzing!
