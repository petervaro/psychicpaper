/* INFO **
** INFO */

#include <stdio.h>
/*  const : stdout
    func  : putchar */
#include <stdlib.h>
/*  const : EXIT_SUCCESS */
#include <stdbool.h>
/*  type  : bool
    const : true
            false */
#include <limits.h>

#include "psychicpaper/stdtypes.h"
/*  func  : std_bool_put
            std_char_put
            std_int_put */

int
main(void)
{
    bool        t  = true,
                f  = false;
    int         i1 = 12345,
                i2 = -9876;
    const char *s  = "hello";

    std_bool_put((const void *)&t, NULL, stdout); putchar('\n');
    std_bool_put((const void *)&f, NULL, stdout); putchar('\n');

    std_char_put((const void *)(s + 0), NULL, stdout); putchar('\n');
    std_char_put((const void *)(s + 1), NULL, stdout); putchar('\n');
    std_char_put((const void *)(s + 2), NULL, stdout); putchar('\n');
    std_char_put((const void *)(s + 3), NULL, stdout); putchar('\n');
    std_char_put((const void *)(s + 4), NULL, stdout); putchar('\n');
    std_char_put((const void *)(s + 5), NULL, stdout); putchar('\n');

    std_int_put((const void *)&i1, NULL, stdout); putchar('\n');
    std_int_put((const void *)&i2, NULL, stdout); putchar('\n');

    std_string_put((const void *)"Hello, World!", NULL, stdout); putchar('\n');

    /* Limits */
    std_int_put((const void *)(int[]){INT_MIN + 1}, NULL, stdout); putchar('\n');


    // !!!!! <<<<< THIS IS WHERE I LEFT => printing INT_MIN out <<<<< !!!!!


    std_int_put((const void *)(int[]){INT_MAX}, NULL, stdout); putchar('\n');

    // pp_printf("{}, {}, {}, {}\n", std_int_put, (int[]){1},
    //                               std_int_put, (int[]){2},
    //                               std_int_put, (int[]){3},
    //                               std_int_put, (int[]){4});

    return EXIT_SUCCESS;
}


// hx_String_str(s1, stdout);
// fputs(" => ", stdout);
// hx_String_str(s2, stdout);

// #define HX_STRING_STR(P) hx_String_str, (void *)P
// pp_fput(stdout, "{} => {}", HX_STRING_STR(s1), HX_STRING_STR(s2));
