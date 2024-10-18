
# CST 334 - Operating Systems Course Summary 
## General Overview
This repository contains lab assignments focusing on key operating systems concepts, including process management, inter-process communication, memory management, and thread synchronization.

### Week 4

-   **Lab4.c & fifo.c**:  
    Implements the FIFO (First-In-First-Out) page replacement algorithm, managing page requests in memory. Tracks total requests, faults, hit/miss rates, and exports results to a CSV file.
    
-   **Makefile.mak**:  
    Automates compilation of lab programs. Builds programs related to thread synchronization.
    
-   **Lab4 copy.c**:  
    A backup or alternative version of the Lab4 FIFO algorithm.
    
-   **Write Up.docx**:  
    Report summarizing Lab 4, explaining the FIFO page replacement implementation and results.
    

### Week 6

-   **threadSync.c & Lab6.c**:  
    Implements thread synchronization, exploring concepts like mutexes, semaphores, and handling concurrency.
    
-   **Makefile.mak**:  
    Compiles the thread synchronization programs for Lab 6.
    
-   **Lab assignment 6.docx & Week 6.docx**:  
    Documentation for Lab 6, detailing thread synchronization implementation and test results.
    
-   **Step1.png, Step2.png**:  
    Visual aids likely showing thread interactions or program outputs.
    

### Week 1-3

-   **Lab 2 - Parent and Child Processes**:  
    Creates a child process from the parent, and both processes iterate 100 times. This lab demonstrates basic process creation using `fork()`, with both parent and child processes executing concurrently and delayed by `usleep()`.
    
-   **Lab 2A - exec() and wait()**:  
    A child process is created with `fork()` and runs the `ls` command using `execlp()`. The parent process waits for the child to complete using `wait()`.
    
-   **Lab 3 (Part 1) - IPC with Pipes (ls -> more)**:  
    Demonstrates inter-process communication (IPC) using pipes. The output of the `ls` command is passed to the `more` command through a pipe, with child processes duplicating the pipe file descriptors.
    
-   **Lab 3 (Part 2) - Argument Passing via Pipes**:  
    A program that passes command-line arguments through a pipe. The writer process sends arguments to the upstream end, and the reader process reads from the downstream end.
