CC = gcc

#INC =  -I./include/
#LIBVAR = -lpthread
#LIBPATH = -L./lib
#CFLAGS ?= -O2 -g 

OBJS := main.o
OBJS += add.o
OBJS += sub.o

SRCS := main.c
SRCS += add.c
SRCS += sub.c

TARGET = test

$(TARGET):$(OBJS)
	$(CC) $(INC) $(CFLAG) -o $@ $^ $(LIBVAR) $(LIBPATH) 
	@echo "build success"

$(OBJS):$(SRCS)
	$(CC) $(INC) $(CFLAG) -c $^ $(LIBVAR) $(LIBPATH) 

clean:
	rm -rf $(OBJS) $(TARGET) 

install:
	@echo "do nothing"
