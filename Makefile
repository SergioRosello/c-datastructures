main: clear
	gcc -o main linkedList.c main.c -Wall -Werror

all: linkedList main

linkedList:
	gcc -o linkedList linkedList.c -Wall -Werror

clear:
	rm -rf main

run: main
	./main
