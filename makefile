CC = gcc
CFLAGS = $(CF) -g -Wall -Werror -Wpedantic \
	 -Wwrite-strings \
	 -Wstack-usage=1024 \
	 -Wfloat-equal \
	 -Waggregate-return \
	 -Winline

timestable: timestable.c
