CC = gcc
CFLAGS = -std=c17 -Wall -O2 -march=native
#CFLAGS = -Wall -std=c17 -fsanitize=address -static-libasan -g3 -march=native
SRC = ../src
BUILD = ../build
OBJS = $(BUILD)/WY_Logger.o $(BUILD)/WY_File_IO.o
API_HEADERS = $(SRC)/WY_Logger.h  
HEADERS = $(SRC)/WY_Logger.h $(SRC)/WY_File_IO.h
TARGETLIB = $(BUILD)/lib_WY_Logger.a
DEMO = $(BUILD)/demo


.PHONY: clean distclean object_msg

all: $(TARGETLIB) $(DEMO)

$(DEMO): $(SRC)/demo.c $(API_HEADERS) $(TARGETLIB)
	@echo Building demo...
	$(CC) $(CFLAGS) $(SRC)/demo.c $(TARGETLIB) -o $(DEMO)

$(TARGETLIB): object_msg $(OBJS)
	@echo Building library...
	ar rcs $(TARGETLIB) $(OBJS)

$(BUILD)/WY_Logger.o: $(HEADERS) $(SRC)/WY_Logger.c
	$(CC) $(CFLAGS) -c $(SRC)/WY_Logger.c -o $(BUILD)/WY_Logger.o

$(BUILD)/WY_File_IO.o: $(HEADERS) $(SRC)/WY_File_IO.c
	$(CC) $(CFLAGS) -c $(SRC)/WY_File_IO.c -o $(BUILD)/WY_File_IO.o

object_msg:
	@echo Building objects...

clean:
	@echo Deleting objects...
	rm -f $(BUILD)/*.o

distclean: clean
	@echo Deleting demo and library....
	rm -f $(BUILD)/demo
	rm -f $(TARGETLIB)
