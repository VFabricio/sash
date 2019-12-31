#-----------------------------------------------------------------------------
#
# This source file is part of sash, the Super Awesome Shell
#
# Copyright (C) 2019 Vilson Fabricio Juliatto <vfabricio2201@gmail.com>
#
# This software is distributed under the terms of the AGPL v3.0 license.
# See the LICENSE file at the root of this project for more details.
#
#-----------------------------------------------------------------------------

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