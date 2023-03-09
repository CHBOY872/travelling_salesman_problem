CC=gcc
CXX=g++

DEFINES=""

# CFLAGS=-ansi -pedantic -g -Wall
# CXXFLAGS=-ansi -pedantic -g -Wall

CFLAGS=-ansi -pedantic-errors -Wall -Wextra -Werror -O0 -g -fno-exceptions \
-fno-rtti -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable \
-Wno-sign-compare -Wno-missing-field-initializers -Wno-unused-function -Wno-unused-label \
-Wno-unused-value -Wno-unused-result -Wno-strict-aliasing -Wno-format-security -Wno-format-overflow \
-Wno-format-truncation -Wno-stringop-overflow -Wno-array-bounds -Wno-misleading-indentation \
-Wno-implicit-fallthrough -Wno-undef -Wno-logical-op -Wno-maybe-uninitialized -Wno-unused-local-typedefs \
-Wno-unused-private-field -Wno-unused-parameter -Wno-unused-const-variable -Wno-unused-but-set-parameter \
-Wno-unused-variable -Wno-unused-lambda-capture
CXXFLAGS=$(CFLAGS)

SRCMODULES=$(shell find . -name "*.cpp" | grep -v main.cpp)
OBJMODULES=$(SRCMODULES:.cpp=.o)
HEDMODULES=$(SRCMODULES:.hpp=.o)

%.o: %.cpp %.hpp
	$(CXX) $(DEFINES) $(CXXFLAGS) $< -c -o $@

main: main.cpp $(OBJMODULES)
	$(CXX) $(DEFINES) $(CXXFLAGS) $^ -o $@

ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

clean:
	find . -name '*.o' -delete

install:
	make main
	make clean