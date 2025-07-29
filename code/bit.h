#include <stdbool.h>



typedef struct bit {
  bool signal;
} bit;

void UpdateBit(bool signal, bit* bit);

void InvertBit(bit* bit);
