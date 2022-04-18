src = $(wildcard src/libgeometry/*.cpp src/geometry/*.cpp)
obj = $(src:.cpp = obj/geometry/.o)
bin = bin/
CC = g++
srcdir = src/libgeometry

CFLAGS = -Wall -Wextra -Werror 
CPPFLAGS = -I$(srcdir)

main: $(obj)
	$(CC) $(CPPFLAGS) $^ -o $(bin)$@

.PHONY: clean
clean:
	rm -f obj/src/*/*.o
