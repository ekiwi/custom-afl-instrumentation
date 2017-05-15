// Copyright 2017, Kevin Laeufer <ekiwi@berkeley.edu>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at:
// http://www.apache.org/licenses/LICENSE-2.0

#include "afl.h"
#include <stdio.h>

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
