#This script will build stack ADT
CC=gcc
CFLAGS=-Wall -g -c
SRC=stack_ops.c main.c
OBJS=stack_ops.o
HDRS=stack.h
AR=ar
LIB_NAME=libstack.a
ARKEYS=r
RUN=run
TAG=ctags

all:$(OBJS) main.o
	$(CC) $(OBJS) main.o -o $(RUN)
stack_ops.o:stack.h stack_ops.c
main.o:main.c stack.h

bundle:
	$(AR) $(ARKEYS) $(LIB_NAME) $(OBJS)

.PHONY:clean tags
clean:
	rm -rf $(OBJS) main.o $(RUN)
tags:
	$(TAG) -R $(SRC) $(HDRS)
