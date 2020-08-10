CXX     ?= g++
CFLAGS  ?= -std=c++14 -Wall -Wextra
LDFLAGS ?= 
TARGET  = control-id_jsonp
SOURCES = control-id_jsonp.cpp
OBJECTS = $(SOURCES:.c=.o)

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -lcurl -o $@

clean:
	rm -f *.o
	rm -f control-id_jsonp

