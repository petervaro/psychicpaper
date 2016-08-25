/* INFO **
** INFO */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include standard headers */
#include <stdio.h>
/*  type  : FILE
    func  : fputc
            fputs */
#include <stddef.h>
/*  type  : size_t
            ptrdiff_t */
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
            UINTMAX_MAX
    type  : int8_t
            int16_t
            int32_t
            int64_t
            int_fast8_t
            int_fast16_t
            int_fast32_t
            int_fast64_t
            int_least8_t
            int_least16_t
            int_least32_t
            int_least64_t
            intmax_t
            intptr_t
            uint8_t
            uint16_t
            uint32_t
            uint64_t
            uint_fast8_t
            uint_fast16_t
            uint_fast32_t
            uint_fast64_t
            uint_least8_t
            uint_least16_t
            uint_least32_t
            uint_least64_t
            uintmax_t
            uintptr_t */
#include <stdbool.h>
/*  type  : bool */

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Include psychicpaper headers */
#include "psychicpaper/stdtypes.h"

#define REPR_START(T)     "<" #T " "
#define REPR_STOP_C()     '>'
#define REPR_STOP_S()     ">"
#define REPR_CONST(T, V)  REPR_START(T) #V REPR_STOP_S()
#define REPR_CHAR_START() REPR_START(char) "'"
#define REPR_CHAR_STOP()  "'" REPR_STOP_S()
#define REPR_STR_START()  REPR_START(char*) "\""
#define REPR_STR_STOP()   "\"" REPR_STOP_S()
#define REPR_BOOL(V)      REPR_START(bool) #V REPR_STOP_S()
#define REPR_NULL(T)      REPR_CONST(T, (NULL))

/*----------------------------------------------------------------------------*/
void
std_bool_put(const void *restrict self,
             const char *restrict format,
             FILE       *restrict stream)
{
    (void)format;
    if (!self)
        /* TODO: This expands to "<_Bool (NULL)>" instead of "<bool (NULL)>",
                 because of the macro-evaluation order. */
        fputs(REPR_NULL(bool), stream);
    else if (*(const bool *)self)
        fputs(REPR_BOOL(true), stream);
    else
        fputs(REPR_BOOL(false), stream);
}

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* TODO: **standalone non-pointer print methods**
         Consider defining non-pointer methods. Pro: printing instances of types
         which are mostly used as not pointers can be a pain, therefore defining
         methods which can handle these can be a good idea. Con: most of the
         custom types by the user will be better to use as pointers */
// void
// std_bool_print(const bool           self,
//                FILE       *restrict stream)
// {
//     std_bool_put((const void *)&self, NULL, stream);
// }

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
std_bool_str(const void *restrict self,
             const char *restrict format,
             FILE       *restrict stream)
{
    (void)format;
    if (self)
        fputs(*(const bool *)self ? "true" : "false", stream);
}


/*----------------------------------------------------------------------------*/
void
std_char_put(const void *restrict self,
             const char *restrict format,
             FILE       *restrict stream)
{
    (void)format;
    if (!self)
        fputs(REPR_NULL(char), stream);
    else
    {
        if (*(const char *)self)
        {
            fputs(REPR_CHAR_START(), stream);
            fputc(*(const char *)self, stream);
            fputs(REPR_CHAR_STOP(), stream);
        }
        else
            fputs(REPR_CONST(char, '\0'), stream);
    }
}


/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
std_char_str(const void *restrict self,
             const char *restrict format,
             FILE       *restrict stream)
{
    (void)format;
    if (self)
        fputc(*(const char *)self, stream);
}



/*----------------------------------------------------------------------------*/
void
std_string_put(const void *restrict self,
               const char *restrict format,
               FILE       *restrict stream)
{
    (void)format;
    if (!self)
        fputs(REPR_NULL(char*), stream);
    else
    {
        fputs(REPR_STR_START(), stream);
        fputs((const char *)self, stream);
        fputs(REPR_STR_STOP(), stream);
    }
}

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void
std_string_str(const void *restrict self,
               const char *restrict format,
               FILE       *restrict stream)
{
    (void)format;
    if (self)
        fputs((const char *)self, stream);
}



/*----------------------------------------------------------------------------*/
/* TODO: **MSVC pragma operator**
         if the same thing is happening on windows (MSVC), then the conditional
         has to be exptended with the following:
         #elif defined(_MSVC_VER)
             #define PRAGMA(expr) __pragma(#expr) */

/* Unfortunately GCC cannot look ahead, and cannot detect that `INTEGER_PUT`
   will only be called on signed integers, which are already detected to be
   lesser than 0, and then converted to their *-1 value, which means, this
   convertion is safe, and the value of the integer won't change */
#ifndef __clang__
    #define PRAGMA(expr) _Pragma(#expr)
#else
    #define PRAGMA(_)
#endif
/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
#define INTEGER_PUT(TYPE, NAME)                                                \
    static inline void                                                         \
    NAME##_put(TYPE  number,                                                   \
               FILE *stream)                                                   \
    {                                                                          \
        if (number > (TYPE)9)                                                  \
        {                                                                      \
            PRAGMA(GCC diagnostic push)                                        \
            PRAGMA(GCC diagnostic ignored "-Wconversion")                      \
            NAME##_put(number/(TYPE)10, stream);                               \
            PRAGMA(GCC diagnostic pop)                                         \
        }                                                                      \
        fputc('0' + (char)(number%(TYPE)10), stream);                          \
    }

/*----------------------------------------------------------------------------*/
#define U_INTEGER_PUT(TYPE, NAME)                                              \
    INTEGER_PUT(TYPE, NAME)                                                    \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    std_##NAME##_put(const void *restrict self,                                \
                     const char *restrict format,                              \
                     FILE       *restrict stream)                              \
    {                                                                          \
        (void)format;                                                          \
        if (!self)                                                             \
            fputs(REPR_NULL(TYPE), stream);                                    \
        else                                                                   \
        {                                                                      \
            fputs(REPR_START(TYPE), stream);                                   \
            NAME##_put(*(const TYPE *)self, stream);                           \
            fputc(REPR_STOP_C(), stream);                                      \
        }                                                                      \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    std_##NAME##_str(const void *restrict self,                                \
                     const char *restrict format,                              \
                     FILE       *restrict stream)                              \
    {                                                                          \
        (void)format;                                                          \
        if (self)                                                              \
            NAME##_put(*(const TYPE *)self, stream);                           \
    }

/*----------------------------------------------------------------------------*/
#define S_INTEGER_PUT(TYPE, NAME)                                              \
    INTEGER_PUT(TYPE, NAME)                                                    \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    std_##NAME##_put(const void *restrict self,                                \
                     const char *restrict format,                              \
                     FILE       *restrict stream)                              \
    {                                                                          \
        (void)format;                                                          \
        TYPE number;                                                           \
        if (!self)                                                             \
            fputs(REPR_NULL(TYPE), stream);                                    \
        else                                                                   \
        {                                                                      \
            fputs(REPR_START(TYPE), stream);                                   \
            number = *(const TYPE *)self;                                      \
            if (number < 0)                                                    \
            {                                                                  \
                fputc('-', stream);                                            \
                number = (TYPE)-number;                                        \
            }                                                                  \
            NAME##_put(number, stream);                                        \
            fputc(REPR_STOP_C(), stream);                                      \
        }                                                                      \
    }                                                                          \
    /*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/\
    void                                                                       \
    std_##NAME##_str(const void *restrict self,                                \
                     const char *restrict format,                              \
                     FILE       *restrict stream)                              \
    {                                                                          \
        (void)format;                                                          \
        TYPE number;                                                           \
        if (self)                                                              \
        {                                                                      \
            number = *(const TYPE *)self;                                      \
            if (number < 0)                                                    \
            {                                                                  \
                fputc('-', stream);                                            \
                number = (TYPE)-number;                                        \
            }                                                                  \
            NAME##_put(number, stream);                                        \
        }                                                                      \
    }

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Unigned integer types */
U_INTEGER_PUT(unsigned char, uchar)
U_INTEGER_PUT(unsigned short, ushort)
U_INTEGER_PUT(unsigned int, uint)
U_INTEGER_PUT(unsigned long int, ulint)
U_INTEGER_PUT(unsigned long long int, ullint)
U_INTEGER_PUT(size_t, size)
#ifdef UINT8_MAX
    U_INTEGER_PUT(uint8_t, uint8)
#endif
#ifdef UINT16_MAX
    U_INTEGER_PUT(uint16_t, uint16)
#endif
#ifdef UINT32_MAX
    U_INTEGER_PUT(uint32_t, uint32)
#endif
#ifdef UINT64_MAX
    U_INTEGER_PUT(uint64_t, uint64)
#endif
#ifdef UINT_FAST8_MAX
    U_INTEGER_PUT(uint_fast8_t, uintf8)
#endif
#ifdef UINT_FAST16_MAX
    U_INTEGER_PUT(uint_fast16_t, uintf16)
#endif
#ifdef UINT_FAST32_MAX
    U_INTEGER_PUT(uint_fast32_t, uintf32)
#endif
#ifdef UINT_FAST64_MAX
    U_INTEGER_PUT(uint_fast64_t, uintf64)
#endif
#ifdef UINT_LEAST8_MAX
    U_INTEGER_PUT(uint_least8_t, uintl8)
#endif
#ifdef UINT_LEAST16_MAX
    U_INTEGER_PUT(uint_least16_t, uintl16)
#endif
#ifdef UINT_LEAST32_MAX
    U_INTEGER_PUT(uint_least32_t, uintl32)
#endif
#ifdef UINT_LEAST64_MAX
    U_INTEGER_PUT(uint_least64_t, uintl64)
#endif
#ifdef UINTMAX_MAX
    U_INTEGER_PUT(uintmax_t, uintmax)
#endif
#ifdef UINTPTR_MAX
    U_INTEGER_PUT(uintptr_t, uintptr)
#endif
#undef U_INTEGER_PUT

/*- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/* Signed integer types */
S_INTEGER_PUT(signed char, schar)
S_INTEGER_PUT(signed short, short)
S_INTEGER_PUT(int, int)
S_INTEGER_PUT(signed int, sint)
S_INTEGER_PUT(signed long int, lint)
S_INTEGER_PUT(signed long long int, llint)
S_INTEGER_PUT(ptrdiff_t, ptrdiff)
#ifdef INT8_MAX
    S_INTEGER_PUT(int8_t, int8)
#endif
#ifdef INT16_MAX
    S_INTEGER_PUT(int16_t, int16)
#endif
#ifdef INT32_MAX
    S_INTEGER_PUT(int32_t, int32)
#endif
#ifdef INT64_MAX
    S_INTEGER_PUT(int64_t, int64)
#endif
#ifdef INT_FAST8_MAX
    S_INTEGER_PUT(int_fast8_t, intf8)
#endif
#ifdef INT_FAST16_MAX
    S_INTEGER_PUT(int_fast16_t, intf16)
#endif
#ifdef INT_FAST32_MAX
    S_INTEGER_PUT(int_fast32_t, intf32)
#endif
#ifdef INT_FAST64_MAX
    S_INTEGER_PUT(int_fast64_t, intf64)
#endif
#ifdef INT_LEAST8_MAX
    S_INTEGER_PUT(int_least8_t, intl8)
#endif
#ifdef INT_LEAST16_MAX
    S_INTEGER_PUT(int_least16_t, intl16)
#endif
#ifdef INT_LEAST32_MAX
    S_INTEGER_PUT(int_least32_t, intl32)
#endif
#ifdef INT_LEAST64_MAX
    S_INTEGER_PUT(int_least64_t, intl64)
#endif
#ifdef INTMAX_MAX
    S_INTEGER_PUT(intmax_t, intmax)
#endif
#ifdef INTPTR_MAX
    S_INTEGER_PUT(intptr_t, intptr)
#endif
#undef S_INTEGER_PUT
#undef INTEGER_PUT
#undef PRAGMA
