#ifndef COMMON_H
#define COMMON_H

#if defined (Debug) | defined (_DEBUG)
#define LOG(x) { std::cout << x << std::endl; }
#else
#define LOG(x)
#endif

#endif
