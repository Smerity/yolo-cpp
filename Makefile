#
# 'make'        build executable file
# 'make clean'  removes all .o and executable files
#

# Executables to build
EXEC += 01_hello
EXEC += 02_hailstone
EXEC += 03_fibonacci
EXEC += 04_templates
EXEC += 05_letters
EXEC += 06_references

# Define the C++ compiler to use
CXX := $(shell which g++) -std=gnu++0x

# Define CXX compile flags
CXXFLAGS  = -fopenmp -funroll-loops -O3 -W -Wall -Wextra #-Wfatal-errors

# Define any directories containing libraries
#   To include directories use -Lpath/to/files
LDFLAGS +=

##################
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
##################

# 'make' - default rule
all: $(EXEC)

# Default rule for creating an exec of $(EXEC) from a .o file
$(EXEC): % : %.o $(SDLOBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Default rule for creating a .o file from a .cpp file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(DEPSFLAGS) -c -o $@ $<

# Extra dependencies for executables
#   Nothing here

# 'make clean' - deletes all .o files, exec, and dependency files
clean:
	-$(RM) *.o $(EXEC)
	$(RM) -r $(DEPSDIR)

# Define rules that do not actually generate the corresponding file
.PHONY: clean all
