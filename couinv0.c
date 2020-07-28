/* hackerrank input is awkward, it by default wants inerteactive input by the user, though the idea is the user should be able to copy paste input too or direct input too */
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* fn prototypes */
char* readline();
char** split_string(char*);

int main()
{
    char *retenv=getenv("HR_OUTPUT_PATH");
    if(!retenv) {
        printf("Environment variable $HR_OUTPUT_PATH not defined.");
        retenv="./hr_output_file.txt";
    }
    printf("Output will be sent to = %s\n", retenv); 
    FILE* fptr = fopen(retenv, "w");

    /* the very first readline() takes place before the main loop (subsequently, it gets called during each loop iteration
     * because this sole number will tell us how many subproblems there are. The subproblems will be held inside the loop */
    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10); // convert to long int. I usually use atoi(), but strtol() is more general .. can capture substrings, and use base 16 for hex: here base is 10.
    printf("First input stirng element defines %i subproblems.\n", t); 

    if(t_endptr == t_str || *t_endptr != '\0') {
        printf("Error. First strtol() call was ineffective.\n"); 
        exit(EXIT_FAILURE);
    }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        /* inside the loop, we expect to read the size of each subproblem, followed by the array input for each subproblem */
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);
        // printf("%i\n", n); 

        if (n_endptr == n_str || *n_endptr != '\0') {
            printf("Error. subproblem size strtol() call was ineffective.\n"); 
            exit(EXIT_FAILURE);
        }

        // the next line will be an array and there is an inner loop for that.
        char *gs=readline();
        // printf("%s\n", gs);
        char** arr_temp = split_string(gs);
        int* arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            char* arr_item_endptr;
            char* arr_item_str = *(arr_temp + i);
            int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);
            printf("%i\n", arr_item); 

            if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') {
                printf("Error. arr_item strtol() call was ineffective.\n"); 
                exit(EXIT_FAILURE);
            }
            *(arr + i) = arr_item;
        }
    }

    fclose(fptr);
    return 0;
}

char* readline()
{
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str)
{
    char** collsubs = NULL; // collect the substrings. Container of str ptrs, pointing to the substrings in between the tokens.
    char* retok = strtok(str, " "); // "REturn from strTOK: sets space to be the character to split on, in subsequent calls to strtok() as long as NULL is the first arg.

    int spaces = 0; // prob. a count var.

    while(retok) {
        collsubs = realloc(collsubs, sizeof(char*) * ++spaces); // single increment memory expansions

        if (!collsubs)
            return collsubs; // presumably return NULL would work here as well, and it would be clearer.

        collsubs[spaces - 1] = retok;
        retok = strtok(NULL, " ");
    }
    return collsubs;
}
