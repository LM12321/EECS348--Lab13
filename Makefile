CC = g++
CFLAGS = -Wall -O3
SRC = lab13.cpp

# Detect OS and set executable name accordingly
ifeq ($(OS),Windows_NT)
    TARGET = lab13.exe
	CLEANCMD = del /F /Q $(TARGET) & del /F /Q *.o
else
    TARGET = lab13
	CLEANCMD = rm -f $(TARGET) *.o
endif

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

clean:
	$(CLEANCMD)