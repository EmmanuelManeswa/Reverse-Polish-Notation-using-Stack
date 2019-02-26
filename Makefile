all:
	gcc main.c -o executable -g -Wall -Werror -std=c11
clean:
	rm -f executable
	