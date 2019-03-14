CC = gcc

CUR = $(PWD)
LIBVAR = -lpthread
LIBPATH =
SRCS = $(CUR)/print.c


print:$(SRCS)
	$(CC) $(INC) $(CFLAG) -o $@ -c $^ $(LIBVAR) $(LIBPATH) 

