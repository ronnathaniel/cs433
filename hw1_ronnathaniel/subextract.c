
# include <stdio.h>

/*
Author: Ron Nathaniel
Course: CS 433 "Linux Kernel Programming"
Due:    Jan 27 2022
*/


static inline char * sub_str(
    char * dest,
    char * src,
    int s_idx,
    int e_idx
) {
    int s_pass;
    for (s_pass = 0; s_pass + s_idx <= e_idx; s_pass++) {
        *(dest + s_pass) = *(src + s_pass + s_idx);
    }

    printf("%s\n", dest);
    return dest;
}

static inline char * asm_sub_str(
    char * dest,
    char * src,
    int s_idx,
    int e_idx
) {

    __asm__ volatile (
    	"movl $0, %%ecx		\n\t"
		"movq 0(%%rsp), %%rdi\n\t"
    	"add %3, %%ecx		\n\t"
    	"and %%ecx, %%ecx	\n\t"
		"test %%edx, %%ecx 	\n\t"
		"je done			\n\t"
        "loop:				\n\t"
        "add $1, %%ecx		\n\t"
        "and %%ecx, %%ecx	\n\t"
        "test %%ecx, %%edx	\n\t"
        "jg loop			\n\t"
        "done:				\n\t"
        :   "=a" (dest)
        :	"a" (dest),
        	"b" (src),
        	"c" (s_idx),
        	"d" (e_idx)
    	);

    printf("%s\n", dest);
    return dest;
}

int main() {
    char * src = "HelloWorld.";

    int start = 3, stop = 8;

    char dest[stop - start];

   	(sub_str(dest, src, start, stop) == asm_sub_str(dest, src, start, stop))
   	?
   		printf("Strings Are Equal.\n")
   	:
   		printf("Strings Are NOT Equal.\n");
}
