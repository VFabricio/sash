BINDIR = bin
SRCDIR = src
OBJDIR = obj
BIN = sash
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

CC = gcc
CFLAGS = -Wall -pedantic

.PHONY: all clean
all: $(OBJS)
	@echo "Compiling '$(BIN)' binary'."
	@$(CC) -o $(BINDIR)/$(BIN) $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Creating object file $@."
	@$(CC) -c $^ -o $@ $(CFLAGS)
	
clean:
	@echo "Removing build files."
	@-rm -f $(BINDIR)/* $(OBJDIR)/*