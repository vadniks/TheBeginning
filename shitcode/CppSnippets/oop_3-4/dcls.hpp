#ifndef __dcls
#define __dcls

#define ths    (*this)
#define _r(_x) { return _x; }

///////////////////////////////

#if defined(__GNUC__)
#  if __cplusplus >= 201703L
#    define _nn [[gnu::nonnull]]
#  else
#    define _nn __attribute__((nonnull)) // <--
#  endif
#else
#  define _nn
#endif

#if defined(__clang__)
#  define _nl _Nullable
#else
#  define _nl // <--
#endif

#if __cplusplus >= 201103L
#  define _nd [[nodiscard]] // <--
#else
#  define _nd
#endif

///////////////////////////////

typedef char*       ss;
typedef const char* cs;

using namespace std;

const int bf = 64;

template<typename t>
using act = void (t::*)(ss&);

#endif
