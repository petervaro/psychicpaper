/* INFO **
** INFO */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Header guard */
#ifndef PP_STDTYPES_H_2785948336644590
#define PP_STDTYPES_H_2785948336644590 1

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stdio.h>
/*  type  : FILE */
#include <stdint.h>
/*  macro : INT8_MAX
            INT16_MAX
            INT32_MAX
            INT64_MAX
            INT_FAST8_MAX
            INT_FAST16_MAX
            INT_FAST32_MAX
            INT_FAST64_MAX
            INT_LEAST8_MAX
            INT_LEAST16_MAX
            INT_LEAST32_MAX
            INT_LEAST64_MAX
            INTMAX_MAX
            INTPTR_MAX
            UINT8_MAX
            UINT16_MAX
            UINT32_MAX
            UINT64_MAX
            UINT_FAST8_MAX
            UINT_FAST16_MAX
            UINT_FAST32_MAX
            UINT_FAST64_MAX
            UINT_LEAST8_MAX
            UINT_LEAST16_MAX
            UINT_LEAST32_MAX
            UINT_LEAST64_MAX
            UINTPTR_MAX
            UINTMAX_MAX */

/*----------------------------------------------------------------------------*/
void
std_bool_put(const void *restrict self,
             const char *restrict format,
             FILE       *restrict stream);

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
std_bool_str(const void *restrict self,
             const char *restrict format,
             FILE       *restrict stream);



/*----------------------------------------------------------------------------*/
void
std_char_put(const void *restrict self,
             const char *restrict format,
             FILE       *restrict stream);

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
std_char_str(const void *restrict self,
             const char *restrict format,
             FILE       *restrict stream);



/*----------------------------------------------------------------------------*/
void
std_string_put(const void *restrict self,
               const char *restrict format,
               FILE       *restrict stream);

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
std_string_str(const void *restrict self,
               const char *restrict format,
               FILE       *restrict stream);



/*----------------------------------------------------------------------------*/
#define INTEGER_PUT(NAME)                                                      \
void                                                                           \
std_##NAME##_put(const void *restrict self,                                    \
                 const char *restrict format,                                  \
                 FILE       *restrict stream);                                 \
void                                                                           \
std_##NAME##_str(const void *restrict self,                                    \
                 const char *restrict format,                                  \
                 FILE       *restrict stream);
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
INTEGER_PUT(schar)
INTEGER_PUT(short)
INTEGER_PUT(int)
INTEGER_PUT(sint)
INTEGER_PUT(lint)
INTEGER_PUT(llint)
INTEGER_PUT(ptrdiff)
INTEGER_PUT(uchar)
INTEGER_PUT(ushort)
INTEGER_PUT(uint)
INTEGER_PUT(ulint)
INTEGER_PUT(ullint)
INTEGER_PUT(size)
#ifdef INT8_MAX
    INTEGER_PUT(int8)
#endif
#ifdef INT16_MAX
    INTEGER_PUT(int16)
#endif
#ifdef INT32_MAX
    INTEGER_PUT(int32)
#endif
#ifdef INT64_MAX
    INTEGER_PUT(int64)
#endif
#ifdef INT_FAST8_MAX
    INTEGER_PUT(intf8)
#endif
#ifdef INT_FAST16_MAX
    INTEGER_PUT(intf16)
#endif
#ifdef INT_FAST32_MAX
    INTEGER_PUT(intf32)
#endif
#ifdef INT_FAST64_MAX
    INTEGER_PUT(intf64)
#endif
#ifdef INT_LEAST8_MAX
    INTEGER_PUT(intl8)
#endif
#ifdef INT_LEAST16_MAX
    INTEGER_PUT(intl16)
#endif
#ifdef INT_LEAST32_MAX
    INTEGER_PUT(intl32)
#endif
#ifdef INT_LEAST64_MAX
    INTEGER_PUT(intl64)
#endif
#ifdef INTMAX_MAX
    INTEGER_PUT(intmax)
#endif
#ifdef INTPTR_MAX
    INTEGER_PUT(intptr)
#endif
#ifdef UINT8_MAX
    INTEGER_PUT(uint8)
#endif
#ifdef UINT16_MAX
    INTEGER_PUT(uint16)
#endif
#ifdef UINT32_MAX
    INTEGER_PUT(uint32)
#endif
#ifdef UINT64_MAX
    INTEGER_PUT(uint64)
#endif
#ifdef UINT_FAST8_MAX
    INTEGER_PUT(uintf8)
#endif
#ifdef UINT_FAST16_MAX
    INTEGER_PUT(uintf16)
#endif
#ifdef UINT_FAST32_MAX
    INTEGER_PUT(uintf32)
#endif
#ifdef UINT_FAST64_MAX
    INTEGER_PUT(uintf64)
#endif
#ifdef UINT_LEAST8_MAX
    INTEGER_PUT(uintl8)
#endif
#ifdef UINT_LEAST16_MAX
    INTEGER_PUT(uintl16)
#endif
#ifdef UINT_LEAST32_MAX
    INTEGER_PUT(uintl32)
#endif
#ifdef UINT_LEAST64_MAX
    INTEGER_PUT(uintl64)
#endif
#ifdef UINTMAX_MAX
    INTEGER_PUT(uintmax)
#endif
#ifdef UINTPTR_MAX
    INTEGER_PUT(uintptr)
#endif
#undef INTEGER_PUT

#endif /* PP_STDTYPES_H_2785948336644590 */
