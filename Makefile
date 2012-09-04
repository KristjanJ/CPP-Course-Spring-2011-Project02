# To compile, run 'make' in the same directory as this file

############################
# Settings for the library #
############################

# Needed at least for math.ut.ee server
CXX = g++

# Compiler flags (-Wall shows all warnings when compiling, always use this!)
# -Idir specifies, that there are includes in the 'dir' directory
LIB_CPPFLAGS = -Wall -Iinclude

# List of objects for the library
LIBOBJS = obj/vector2.o obj/vector3.o obj/line2.o obj/line3.o obj/circle2.o obj/sphere3.o

# Name of the library
LIBRARY = lib/libgeometry.a

################################
# Settings for the testing app #
################################

# Compiler flags for the pp
APP_CPPFLAGS = -Wall -Iinclude

# Linker flags (order the compiler to link with our library)
LFLAGS = -Llib -lgeometry

# The object for the testing app
TESTOBJS = obj/geometrytest.o

# The name of the testing app
TESTAPP = bin/geometrytest

# This is the first target. It will be built when you run 'make' or 'make all'
all: $(LIBRARY)

# Create the library by using 'ar'
$(LIBRARY) : $(LIBOBJS)
	ar cr $(LIBRARY) $(LIBOBJS)

# Compile each source file of the librar
obj/vector2.o: src/vector2.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/vector2.cpp -o obj/vector2.o
obj/vector3.o: src/vector3.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/vector3.cpp -o obj/vector3.o
obj/line2.o: src/line2.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/line2.cpp -o obj/line2.o
obj/line3.o: src/line3.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/line3.cpp -o obj/line3.o
obj/circle2.o: src/circle2.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/circle2.cpp -o obj/circle2.o
obj/sphere3.o: src/sphere3.cpp
	$(CXX) $(LIB_CPPFLAGS) -c src/sphere3.cpp -o obj/sphere3.o

# Rule for linking the test app with our library
$(TESTAPP): $(TESTOBJS)
	$(CXX) $(TESTOBJS) -o $(TESTAPP) $(LFLAGS) 

# Compile each source file of the library
obj/geometrytest.o: tests/geometrytest.cpp
	$(CXX) $(APP_CPPFLAGS) -c tests/geometrytest.cpp -o obj/geometrytest.o 

test: all $(TESTAPP)

doc:
	doxygen

clean:
	rm -f $(LIBOBJS)
	rm -f $(TESTOBJS)
	rm -f $(LIBRARY)
	rm -f $(TESTAPP)
	rm -rf docs/html
