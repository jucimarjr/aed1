/*
    Nome:   Jucimar Maia da Silva Jr
    Mat:    7389217389123
    
    ESTOU NA STACK!!

*/

#include <stdio.h>

void fazer_recursao() {
    char buffer[1024];

    printf("To understand recursion, you must first understand recursion!\n");
    fazer_recursao();
}

int main(int argc, char** argv)
{
	printf("Stack overflow!!!!\n");
    fazer_recursao();

	return 0;
}