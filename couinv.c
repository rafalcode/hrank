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

// Complete the countInversions function below.
long countInversions(int arrsz, int* arr)
{
    int tmp;
    int i, j=0;
    int coumis=0; // count missplacings.

    for(i=1;i<arrsz;++i) 
        if(arr[j]>arr[i]) { 
            coumis++;
            tmp=arr[j]; arr[j]=arr[i], arr[i]=tmp; //swap!
            j++;
        }

    return coumis;
}

int main()
{
    char *retenv=getenv("OUTPUT_PATH");
    if(!retenv) {
        retenv="./hr_output_file.txt";
        printf("Environment variable $OUTPUT_PATH not defined. Default will be %s.\n", retenv);
    }
    FILE* fptr = fopen(retenv, "w");
    int i;

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }
    free(t_str);

    int subprobnum=0;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);
        // printf("%i\n", n); 

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
        free(n_str);

        char *gs=readline();
        // printf("%s\n", gs);
        char** arr_temp = split_string(gs);

        int* arr = malloc(n * sizeof(int));

        for (i = 0; i < n; i++) {
            char* arr_item_endptr;
            char* arr_item_str = *(arr_temp + i);
            int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);
            printf("%i\n", arr_item); 

            if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(arr + i) = arr_item;
        }

        long result = countInversions(n,  arr);

        fprintf(fptr, "%ld\n", result);
        fprintf(fptr, "Array: ");
        for(i=0;i<n;++i) 
            fprintf(fptr, "%i ", arr[i]);
        printf("Subproblem %i sent to output at %s.\n", 1+subprobnum, retenv);
        free(arr);
        free(arr_temp);
        free(gs);
        subprobnum++;
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
