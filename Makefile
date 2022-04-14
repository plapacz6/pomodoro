CC=gcc
CFLAGS=-g -Wall

pomodoro_pw: pomodoro_pw.c
	$(CC) $(CFLAGS) pomodoro_pw.c -o pomodoro_pw

.PHONY: clean

clean:
	- rm *.o pomodoro_pw
