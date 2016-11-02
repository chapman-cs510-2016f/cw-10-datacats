#include <stdio.h>
#include <stdlib.h>
#include "typeio.h"

int main(int argc, char **argv) {
    
    // Permit easy command-line access
    unsigned int C = 65;
    if (argc == 2) {
        C = atoi(argv[1]);
        printf("Using unsigned integer: %u\n\n", C);
    }
    else {
        printf("Usage: %s uint\n where uint is an unsigned integer\n\n", 
          argv[0]);
        printf("Using default unsigned integer: %u\n\n", C);
    }

    /* Define a variety of types all initialized
     * to the same value C defined at the top
     *
     * This code investigates how each numeric type
     * is physically stored as bits in the hardware
     *
     * Importantly the same "value" has very different
     * representations, depending on which type it is
     * 
     * This code exploits the fact that the compiler will
     * auto-coerce the type of C into the declared type
     */
    // Here an explicit type cast is used to type (char)
    char c = (char) C;
    // Here the cast is left implicitly done by the compiler
    unsigned char uc = C;
    short int si = C;
    int i = C;
    long int li = C;
    unsigned int ui = C;
    unsigned long int uli = C;
    unsigned long long int ulli = C;
    float f = C;
    double d = C;
    long double ld = C;
    
    /* Output actual bit strings to screen
     * Why is it hard to write a function to execute the
     * following three lines for each type?
     * 
     * Syntax note:
     *    &var : returns memory address (pointer) containing value of var
     *    *add : returns value at the memory address add (dereferences pointer)
     */ 
    print_type("Character", sizeof(c));
    printf("%c : ",c);
    print_bits(sizeof(c), &c);
    
    print_type("Unsigned character", sizeof(uc));
    printf("%u : ",uc);
    print_bits(sizeof(uc), &uc);
    
    print_type("Short Integer", sizeof(si));
    printf("%d : ",si);
    print_bits(sizeof(si), &si);
    
    print_type("Integer", sizeof(i));
    printf("%d : ",i);
    print_bits(sizeof(i), &i);
    
    print_type("Long Integer", sizeof(li));
    printf("%ld : ",li);
    print_bits(sizeof(li), &li);
    
    print_type("Unsigned Integer", sizeof(ui));
    printf("%u : ",ui);
    print_bits(sizeof(ui), &ui);
    
    print_type("Unsigned Long Integer", sizeof(uli));
    printf("%lu : ",uli);
    print_bits(sizeof(uli), &uli);
    
    print_type("Unsigned Long Long Integer", sizeof(ulli));
    printf("%llu : ",ulli);
    print_bits(sizeof(ulli), &ulli);
    
    print_type("Float", sizeof(f));
    printf("%f : ",f);
    print_bits(sizeof(f), &f);
    
    print_type("Double", sizeof(d));
    printf("%f : ",d);
    print_bits(sizeof(d), &d);
    
    print_type("Long Double", sizeof(ld));
    printf("%Lf : ",ld);
    print_bits(sizeof(ld), &ld);
    
    return 0;
}

