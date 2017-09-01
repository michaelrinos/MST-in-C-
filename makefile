#
# Created by gmakemake (Ubuntu Jul 25 2014) on Mon Jun 19 17:49:53 2017
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Default flags (redefine these with a header.mak file if desired)
CXXFLAGS =  -std=c++14 -Wall -Wextra -Wpedantic -ggdb
CFLAGS =	-ggdb
CLIBFLAGS =	-lm
CCLIBFLAGS =	
########## End of default flags


CPP_FILES =	Edge.cpp Maze.cpp Node.cpp
C_FILES =	
PS_FILES =	
S_FILES =	
H_FILES =	Edge.h Node.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	Node.o Edge.o

#
# Main targets
#

all:	test_edge test_node

MST:	Minimum_Spanning_Tree.o ${OBJFILES}
	$(CXX) $(CXXFLAGS) -o MST Minimum_Spanning_Tree.o $(OBJFILES) $(CCLIBFLAGS)

test_edge:	test_edge.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o test_edge test_edge.o $(OBJFILES) $(CCLIBFLAHS)

test_node:	test_node.o $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o test_node test_node.o $(OBJFILES) $(CCLIBFLAHS)

#
# Dependencies
#

Node.o:		Node.h
Edge.o:		Edge.h

test_edge.o:	Edge.h
test_node.o:	Node.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm -f $(OBJFILES) tester.o core

realclean:        clean
	-/bin/rm -f tester 
