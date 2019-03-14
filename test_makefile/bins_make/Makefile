#CC = aarch64-oe-linux-gcc
CC = gcc
#CPP = g++
#AR = ar rc

#INC =  -I./include/
#INC ?= --sysroot=/usr/local/oecore-x86_64/sysroots/aarch64-oe-linux

LIBVAR = -lpthread
#LIBPATH = -L./lib
LIBPATH =

#CFLAGS ?= -O2 -fexpensive-optimizations -frename-registers -fomit-frame-pointer 
#CFLAGS += -Wl,-O1 -Wl,--hash-style=gnu -Wl,--as-needed

OBJS := main.o
OBJS += add.o
OBJS += sub.o

SRCS := main.c
SRCS += add.c
SRCS += sub.c
TARGET = test hello
all:$(TARGET)

test:$(OBJS)
	$(CC) $(INC) $(CFLAG) -o $@ $^ $(LIBVAR) $(LIBPATH) 
	@echo "build success"

$(OBJS):$(SRCS)
	$(CC) $(INC) $(CFLAG) -c $^ $(LIBVAR) $(LIBPATH) 

hello:hello.c	
	$(CC) $(INC) $(CFLAG) -o $@ $^ $(LIBVAR) $(LIBPATH) 

clean:
	rm -rf $(OBJS) $(TARGET) 

install:
	@echo "rtmp do nothing"
