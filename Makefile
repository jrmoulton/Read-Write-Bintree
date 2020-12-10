# https://stackoverflow.com/questions/30573481/path-include-and-src-directory-makefile/30602701
#
# Compiler flags
#
CC = gcc
CFLAGS = -Wall -Werror -Wextra

#
# Project files
#
SRCDIR = src
SRCS = $(wildcard $(SRCDIR)/*.c)
EXE  = RootTable

#
# Debug build settings
#
DBGDIR = target/debug
DBGEXE = $(DBGDIR)/$(EXE)
DBGOBJS = $(patsubst $(SRCDIR)/%.c, $(DBGDIR)/%.o, $(SRCS))
DBGCFLAGS = -g -O0 -DDEBUG

#
# Release build settings
#
RELDIR = target/release
RELEXE = $(EXE)
RELOBJS = $(patsubst $(SRCDIR)/%.c, $(RELDIR)/%.o, $(SRCS))
RELCFLAGS = -O3 -DNDEBUG

.PHONY: all clean debug release remake

#
# Default build
#
all: release

#
# Debug rules
#
debug: $(DBGEXE)

$(DBGEXE): $(DBGOBJS) | $(DBGDIR)
	$(CC) $(CFLAGS) $(DBGCFLAGS) $^ -o $@

$(DBGDIR)/%.o: $(SRCDIR)/%.c | $(DBGDIR)
	$(CC) $(CFLAGS) $(DBGCFLAGS) -c $< -o $@

#
# Release rules
#
release: $(RELEXE)

$(RELEXE): $(RELOBJS) | $(RELDIR)
	$(CC) $(CFLAGS) $(RELCFLAGS) $^ -o $@

$(RELDIR)/%.o: $(SRCDIR)/%.c | $(RELDIR)
	$(CC) $(CFLAGS) $(RELCFLAGS) -c $< -o $@

#
# Other rules
#
clean:
	rm -f $(RELEXE) $(RELOBJS) $(DBGEXE) $(DBGOBJS)

remake: clean all

$(RELDIR) $(DBGDIR):
	@mkdir -p $@

-include $(OBJ:.o=.d)