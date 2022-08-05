all: 
	gcc *.c -o prog -g -Wall
run:
	./prog
zip:
	zip trab.zip *c *h Makefile