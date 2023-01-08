# the compiler to use
CC = clang

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
  
# the name to use for both the target source file, and the output file:
TARGET = binary_tree
BINS = a.out
  
# all: $(TARGET)
  
$(BINS): $(TARGET).c
	$(CC) $(CFLAGS) -o $(BINS) $(TARGET).c $(LFLAGS)

clean:
	$(RM) $(BINS)
