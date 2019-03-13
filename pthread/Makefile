CC = gcc
CPP = g++
AR = ar rc

#INC =  -I./include/
INC =
LIBVAR = -lpthread
#LIBPATH = -L./lib
LIBPATH =


OBJS =

SRCS = main.c
TARGET = test 


$(TARGET):$(SRCS)
	$(CC) $(INC) -g -o $@ $^ $(LIBVAR) $(LIBPATH) 
	@echo "build success"

clean:
	rm -rf $(OBJS) $(TARGET) 

install:
	@echo "rtmp do nothing"
