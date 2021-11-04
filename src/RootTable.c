
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "myLinkedList.h"

/*
Function Title: main
Summary: Read in and sort ints from a file specified from the command line
    by storing them in a dynamically allocated linked list and write out the
    sorted ints and the 2, 3, and 4 roots without duplicates to another file
    specified from the command line
Inputs: String: name of input file, String: name out output file
Outputs: none
Psuedocode:
Begin:
    initialize variables
    check for null file pointers
        exit
    read in first value from file to linked list
    while not at end of file
        read in int
        push int to linked list
    while not at end of list
       get next value from list
       write value to file with 2, 3, 4 roots
    close file pointers
End
*/
int main(int argc, char **argv) {  // Begin:
    // initialize variables
    char *filein = argv[1], *fileout = argv[2];
    FILE *data_in = fopen(filein, "r"), *data_out = fopen(fileout, "w");
    int tempint;
    List list;
    (void)argc;

    // Check for null file pointers
    if (data_in == NULL) {
        printf("Could not open %s\n", filein);
        exit(EXIT_FAILURE);  // exit
    }
    if (data_out == NULL) {
        printf("Could not open %s\n", fileout);
        exit(EXIT_FAILURE);  // exit
    }

    // read in first value from file to linked list
    fscanf(data_in, "%d", &tempint);
    if (tempint == 0) {
        printf("Data input file must have at least 1 value\n");
        exit(EXIT_FAILURE);
    }
    list.head = malloc(sizeof(Node));
    list.head->val = tempint;

    // while not at end of file
    while (!feof(data_in)) {
        fscanf(data_in, "%d", &tempint);  // read in int
        push(&list, tempint);             // push int to linked list
    }

    list.prev = malloc(sizeof(Node));
    // while not at end of list
    while (list.head != NULL) {
        tempint = pop(&list);  // get next value from list

        // write value to file with 2, 3, 4 roots
        fprintf(data_out, "%-5d\t%-5.3f\t\t%-5.3f\t\t%-5.3f\n", tempint,
                pow(tempint, 1.0 / 2.0), pow(tempint, 1.0 / 3.0),
                pow(tempint, 1.0 / 4.0));
    }

    // close file pointers
    fclose(data_out);
    fclose(data_in);

    return 0;
}  // End