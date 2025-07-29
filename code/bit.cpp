#include "bit.h"

void UpdateBit(bool signal, bit* bit) {
  bit->signal = signal;
}

void InvertBit(bit* bit) {
  if (bit->signal == false) {
    bit->signal = true;
    return;
  }
  else {
    bit->signal = false;
    return;
  }
}
