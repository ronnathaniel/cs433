
/*
Author: Ron Nathaniel
Course: CS 433 "Linux Kernel Programming"
Due:    Jan 27 2022
*/

# include <stdio.h>

static inline char * sub_str(
    char * dest,
    char * src,
    int s_idx,
    int e_dix
) {
    /*
    */
    int s_pass;
    for (s_pass = 0; s_pass + s_idx <= e_dix; s_pass++) {
        *(dest + s_pass) = *(src + s_pass + s_idx);
    }

    printf("%s\n", dest);

    return dest;

}

static inline char * asm_sub_str(
    char * dest,
    char * src,
    int s_idx,
    int e_dix
) {

    __asm__(
        ""
        :   /* output */
        : "r"
    );
    /*
    */
    return dest;
}

int main() {
    char * src = "MyNameIs.";

    int start = 2, stop = 6;

    char dest[stop - start];

    sub_str(dest, src, start, stop);
}