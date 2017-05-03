CXX := g++-mp-6
CC := gcc-mp-6
CCFLAGS := -Wall -Wextra -std=c11
CXXFLAGS := -Wall -Wextra -std=c++14
LDFLAGS := -O2
EXEC := main

HEADERS := $(wildcard *.h)
OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))
OBJECTS += $(patsubst %.cpp,%.o,$(wildcard *.cpp))
OBJECTS := $(strip $(OBJECTS))

$(EXEC): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(EXEC) $^

%.o: %.c $(HEADERS)
	$(CC) -c $(CCFLAGS) -o $@ $<

%.o: %.cpp $(HEADERS)
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -rf main main.dSYM $(OBJECTS)
	clang-format-mp-3.9 -i -style="Google" *.cpp
