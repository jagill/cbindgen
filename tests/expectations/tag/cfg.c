#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#if (defined(PLATFORM_WIN) || defined(M_32))
enum BarType {
  A,
  B,
  C,
};
typedef uint32_t BarType;
#endif

#if (defined(PLATFORM_UNIX) && defined(X11))
enum FooType {
  A,
  B,
  C,
};
typedef uint32_t FooType;
#endif

#if (defined(PLATFORM_UNIX) && defined(X11))
struct FooHandle {
  FooType ty;
  int32_t x;
  float y;
};
#endif

enum C_Tag {
  C1,
  C2,
#if defined(PLATFORM_WIN)
  C3,
#endif
#if defined(PLATFORM_UNIX)
  C5,
#endif
};
typedef uint8_t C_Tag;

#if defined(PLATFORM_UNIX)
struct C5_Body {
  C_Tag tag;
  int32_t int_;
};
#endif

union C {
  C_Tag tag;
#if defined(PLATFORM_UNIX)
  struct C5_Body c5;
#endif
};

#if (defined(PLATFORM_WIN) || defined(M_32))
struct BarHandle {
  BarType ty;
  int32_t x;
  float y;
};
#endif

#if (defined(PLATFORM_UNIX) && defined(X11))
void root(struct FooHandle a, union C c);
#endif

#if (defined(PLATFORM_WIN) || defined(M_32))
void root(struct BarHandle a, union C c);
#endif
