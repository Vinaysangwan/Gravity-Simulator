#pragma once

typedef char bool;
#define TRUE 1
#define FALSE 0

#define PRINTLN(...)            \
{                               \
  printf(__VA_ARGS__);          \
  printf("\n");                 \
}
