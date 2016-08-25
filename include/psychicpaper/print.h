/* INFO **
** INFO */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stdio.h>
/*  type  : FILE */


/*----------------------------------------------------------------------------*/
typedef void (*pp_FormatFunc)(const void *restrict,
                              const char *restrict,
                              FILE       *restrict);
