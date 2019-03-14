CC = gcc

#INC =  -I./include/
#LIBVAR = -lpthread
#LIBPATH = -L./lib
#CFLAGS ?= -O2 -g 

OBJS := test.o
OBJS += hello.o

SRCS := test.c
SRCS += hello.c

TARGET = test hello

all:$(TARGET)
	@echo "build success"
test:test.c
	$(CC) $(INC) $(CFLAG) -o $@ $^ $(LIBVAR) $(LIBPATH) 

hello:hello.c	
	$(CC) $(INC) $(CFLAG) -o $@ $^ $(LIBVAR) $(LIBPATH) 

clean:
	rm -rf $(OBJS) $(TARGET) 

install:
	@echo "do nothing"
