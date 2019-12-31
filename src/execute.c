//-----------------------------------------------------------------------------
//
// This source file is part of sash, the Super Awesome Shell
//
// Copyright (C) 2019 Vilson Fabricio Juliatto <vfabricio2201@gmail.com>
//
// This software is distributed under the terms of the AGPL v3.0 license.
// See the LICENSE file at the root of this project for more details.
//
//-----------------------------------------------------------------------------

#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "error.h"
#include "execute.h"
#include "lexer.h"
#include "wrappers.h"

void execute(tokens t) {
    pid_t pid = fork();
    if (pid < 0) {
        if (errno == EAGAIN) {
            error_quit(MAX_THREADS_EXECUTE,
                "FATAL ERROR: cannot execute command because the maximum number of threads has been reached or forking is not allowed by the scheduling policy!");
        }
        if (errno == ENOMEM) {
            error_quit(OOM_EXECUTE,
                "FATAL ERROR: cannot execute command because the system is out of memory!");
        }
        if (errno == ENOSYS) {
            error_quit(NO_FORK_EXECUTE,
                "FATAL ERROR: the fork() system call is not avaiable on this platform!");
        }
        error_quit(UNKNOWN_ERROR, "FATAL ERROR: an unknown error ocurred while trying to run a command!");
    }

    if (pid == 0) // we're on the child
    {
        execvp(t.tokens_list[0], t.tokens_list);
        print("An error has ocurred. Could not launch command ");
        print(t.tokens_list[0]);
        print(".\n");
        exit(EXIT_FAILURE);
    }

    // TODO: add more detail here
    if (pid > 0) // we're on the parent
    {
        int status;
        waitpid(pid, &status, 0);
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}