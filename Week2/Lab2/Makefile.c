#Name : Conner Jordan
#Date : 7 - 4 - 2023
#Title : Lab2 - Makefile
#Description : compiles the 2 versions of the c programs and also includes a clean utility

all : Lab2 Lab2A

          Lab2 : Lab2.c
                 @echo "Compiling code from step 1..."
                 @gcc Lab2.c -
    o Lab2

        Lab2A : Lab2A.c
                @echo "Compiling code from step 5..."
                @gcc Lab2A.c -
    o Lab2A

        clean : @rm -
                f Lab2 Lab2A