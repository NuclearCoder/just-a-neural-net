# -- dirs, files -- #

SRCDIR := sources
HDRDIR := headers
OBJDIR := obj

SRCFILES := $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJFILES := $(patsubst %.cpp,%.o,$(SRCFILES))

# -- compiler -- #

WARNINGS := -Wall -Wextra -Werror
CFLAGS := -g -std=c++11 $(WARNINGS) -I$(HDRDIR)

# -- targets -- #

all: neural-net

neural-net: restore_bfiles $(OBJFILES)
	-@$(CXX) $(CFLAGS) $(OBJFILES) -o neural-net
	-@$(MAKE) hide_bfiles

%.o: %.cpp Makefile
	-@$(CXX) $(CFLAGS) -c $< -o $@

clean:
	-@$(RM) $(OBJDIR)/*

re: clean all


.PHONY: all clean re

restore_bfiles:
	-@mv obj/* sources/

hide_bfiles:
	-@mv sources/*.o obj/
	-@mv sources/*.d obj/
