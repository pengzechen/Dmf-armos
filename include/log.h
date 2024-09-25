
#ifndef __LOG_H__
#define __LOG_H__

#include "io.h"

// 日志级别宏定义
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_WARN  2
#define LOG_LEVEL_ERROR 3

// 根据编译时定义选择日志级别
#ifndef LOG_LEVEL
#define LOG_LEVEL 1
#endif

// 颜色定义
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_GREEN  "\033[0;32m"
#define COLOR_RED    "\033[0;31m"
#define COLOR_RESET  "\033[0m"

// 日志输出宏
#if LOG_LEVEL <= LOG_LEVEL_INFO
#define INFO(fmt, ...) printf(COLOR_GREEN "[INFO] " fmt COLOR_RESET "\n", ##__VA_ARGS__)
#else
#define INFO(fmt, ...)
#endif

#if LOG_LEVEL <= LOG_LEVEL_WARN
#define WARN(fmt, ...) printf(COLOR_YELLOW "[WARN] " fmt COLOR_RESET "\n", ##__VA_ARGS__)
#else
#define WARN(fmt, ...)
#endif

#if LOG_LEVEL <= LOG_LEVEL_ERROR
#define ERROR(fmt, ...) printf(COLOR_RED "[ERROR] " fmt COLOR_RESET "\n", ##__VA_ARGS__)
#else
#define ERROR(fmt, ...)
#endif

#endif