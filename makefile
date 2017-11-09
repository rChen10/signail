all: signal
	gcc signal.c -o signal

run: all
	./signal
