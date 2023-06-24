CC = g++
CFLAGS = -std=c++17 -Wall -O2
SRCDIR = src
INCDIR = include

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,%.o,$(SOURCES))
EXECUTABLE = index

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -I$(INCDIR) -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
