# Specifiy the target
all: prompt

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
prompt: BST.o test.o
	g++ BST.o test.o -o testCP3

# Specify how the object files should be created from source files

BST.o: BST.cpp
	g++ -c BST.cpp

test.o: test.cpp
	g++ -c test.cpp	

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o
	rm testCP3
	
