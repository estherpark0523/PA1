#
# Makefile for CSE 30 -- PA1
# You should not need to change anything in this file except for SIZE.
#

# You may change me for debugging purposes.
SIZE = 2003

HEADERS		= pa1.h pa1Strings.h test.h
		  
SPAM_FILTER_C_SRCS	= populateTable.c llTableAddString.c\
		checkTable.c launchUserQuery.c retrieveLinkedList.c\
		hash.c prependNode.c util.c spamFilter.c

SPAM_FILTER_EC_SRCS	= populateTable.c llTableAddString.c checkTable.c\
		launchUserQueryEC.c retrieveLinkedList.c hash.c prependNode.c\
		util.c spamFilter.c

SPAM_FILTER_EC2_SRCS = populateTable.c llTableAddString.c\
		checkTable.c launchUserQuery.c retrieveLinkedList.c\
		hash.c prependNode.c util.c spamFilterEC2.c
SPAM_FILTER_OBJS = $(SPAM_FILTER_C_SRCS:.c=.o)
SPAM_FILTER_EC_OBJS	= $(SPAM_FILTER_EC_SRCS:.c=.o)
SPAM_FILTER_EC2_OBJS = $(SPAM_FILTER_EC2_SRCS:.c=.o)
SPAM_FILTER_EXE	= spamFilter
SPAM_FILTER_EC_EXE	= spamFilterEC
SPAM_FILTER_EC2_EXE	= spamFilterEC2
TEST_EXES	= testhash testprependNode testpopulateTable
GCC		= gcc
RM		= rm
GCC_FLAGS	= -c -g -std=c11 -pedantic -Wall -D__EXTENSIONS__ \
		-DDEFAULT_SIZE=$(SIZE)
LD_FLAGS	= -g -Wall
#
# Standard rules
#
.c.o:
	@echo "Compiling each C source file separately ..."
	$(GCC) $(GCC_FLAGS) $<
#
# Target to create the main program. This is the default target
# that gets run when you type 'make' with no target specified
#
$(SPAM_FILTER_EXE):	$(SPAM_FILTER_OBJS)
	$(RM) -f test*.o test*.ln
	@echo "Linking all object modules ..."
	$(GCC) $(LD_FLAGS) -o $(SPAM_FILTER_EXE) $(SPAM_FILTER_OBJS)
	@echo "Compilation Successful!"
#
# Target to make the EC executable for the first extra credit.
#
$(SPAM_FILTER_EC_EXE):	$(SPAM_FILTER_EC_OBJS)
	$(RM) -f test*.o test*.ln
	@echo "Linking all object modules ..."
	$(GCC) $(LD_FLAGS) -o $(SPAM_FILTER_EC_EXE) $(SPAM_FILTER_EC_OBJS)
	@echo "Compilation Successful!"
#
# Target to make the EC exectuable for the second extra credit.
#
$(SPAM_FILTER_EC2_EXE):	$(SPAM_FILTER_EC2_OBJS)
	$(RM) -f test*.o test*.ln
	@echo "Linking all object modules ..."
	$(GCC) $(LD_FLAGS) -o $(SPAM_FILTER_EC2_EXE) $(SPAM_FILTER_EC2_OBJS)
	@echo "Compilation Successful!"
clean:
	@echo "Cleaning up project directory ..."
	$(RM) -f $(SPAM_FILTER_EXE) $(SPAM_FILTER_EC_EXE) $(SPAM_FILTER_EC2_EXE) \
		$(TEST_EXES) *.o *.ln core a.out
	@echo "Clean."
#
# Unit test targets
#
# --- Test for hash ---
testhash: $(HEADERS) hash.o testhash.o
	@echo "Compiling testhash.c"
	$(GCC) $(LD_FLAGS) -o testhash testhash.o hash.o
	@echo "Compilation Successful!"
# --- Test for prependNode ---
testprependNode: $(HEADERS) prependNode.o testprependNode.o util.o
	@echo "Compiling testprependNode.c"
	$(GCC) $(LD_FLAGS) -o testprependNode testprependNode.o prependNode.o util.o
	@echo "Compilation Successful!"
# --- Test for populateTable ---
testpopulateTable: $(HEADERS) populateTable.o testpopulateTable.o \
	checkTable.o retrieveLinkedList.o prependNode.o hash.o llTableAddString.o \
	util.o
	@echo "Compiling testpopulateTable.c"
	$(GCC) $(LD_FLAGS) -o testpopulateTable testpopulateTable.o \
	checkTable.o retrieveLinkedList.o populateTable.o prependNode.o hash.o \
	llTableAddString.o util.o
	@echo "Compilation Successful!"
