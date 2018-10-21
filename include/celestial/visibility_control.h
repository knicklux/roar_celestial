#ifndef CELESTIAL__VISIBILITY_CONTROL_H_
#define CELESTIAL__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CELESTIAL_EXPORT __attribute__ ((dllexport))
    #define CELESTIAL_IMPORT __attribute__ ((dllimport))
  #else
    #define CELESTIAL_EXPORT __declspec(dllexport)
    #define CELESTIAL_IMPORT __declspec(dllimport)
  #endif
  #ifdef CELESTIAL_BUILDING_LIBRARY
    #define CELESTIAL_PUBLIC CELESTIAL_EXPORT
  #else
    #define CELESTIAL_PUBLIC CELESTIAL_IMPORT
  #endif
  #define CELESTIAL_PUBLIC_TYPE CELESTIAL_PUBLIC
  #define CELESTIAL_LOCAL
#else
  #define CELESTIAL_EXPORT __attribute__ ((visibility("default")))
  #define CELESTIAL_IMPORT
  #if __GNUC__ >= 4
    #define CELESTIAL_PUBLIC __attribute__ ((visibility("default")))
    #define CELESTIAL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CELESTIAL_PUBLIC
    #define CELESTIAL_LOCAL
  #endif
  #define CELESTIAL_PUBLIC_TYPE
#endif

#endif  // CELESTIAL__VISIBILITY_CONTROL_H_
