// log.h (Updated with LOG_W and LOG_E)

#ifndef LOG_H
#define LOG_H

#include <stdio.h> // Required for printf

// ----------------------------------------------------
// 1. Logging Level Control
// ----------------------------------------------------
// Define LOG_LEVEL_ENABLE when compiling to activate all logging.
// Example: gcc -DLOG_LEVEL_ENABLE -c main.c

#ifdef LOG_LEVEL_ENABLE

// ----------------------------------------------------
// 2. Logging Macro Definitions (Enabled)
// ----------------------------------------------------

// Helper macro to format the output with context
#define LOG_FORMAT(level, fmt, ...)                                            \
  printf("[%s] %s:%d - " fmt, level, __FILE__, __LINE__, ##__VA_ARGS__)

// ➡️ LOG_E (Error)
#define LOG_E(fmt, ...) LOG_FORMAT("ERROR", fmt, ##__VA_ARGS__)

// ➡️ LOG_W (Warning)
#define LOG_W(fmt, ...) LOG_FORMAT("WARN", fmt, ##__VA_ARGS__)

// LOG_I (Info)
#define LOG_I(fmt, ...) LOG_FORMAT("INFO", fmt, ##__VA_ARGS__)

// LOG_D (Debug)
#define LOG_D(fmt, ...) LOG_FORMAT("DEBUG", fmt, ##__VA_ARGS__)

#else

// ----------------------------------------------------
// 3. Logging Macro Definitions (Disabled/NOP)
// ----------------------------------------------------
// All macros expand to a NOP for zero overhead.
#define LOG_E(fmt, ...)                                                        \
  do {                                                                         \
  } while (0)
#define LOG_W(fmt, ...)                                                        \
  do {                                                                         \
  } while (0)
#define LOG_I(fmt, ...)                                                        \
  do {                                                                         \
  } while (0)
#define LOG_D(fmt, ...)                                                        \
  do {                                                                         \
  } while (0)

#endif // LOG_LEVEL_ENABLE

#endif // LOG_H
