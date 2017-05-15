AFL_DIR:=~/d/afl-vanilla/


test: afl.c afl.h main.c
	gcc -O3 -g main.c afl.c -o test
run: test
	rm -rf out
	mkdir out
	AFL_SKIP_CPUFREQ=1 $(AFL_DIR)afl-fuzz -i in -o out ./test
