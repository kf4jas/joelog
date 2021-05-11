build: clean
	gcc -o joelog src/main.c
clean:
	rm -f joelog

buildtests:
	gcc -o argtest src/argtest.c
