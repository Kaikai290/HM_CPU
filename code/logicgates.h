#include "bit.h"

typedef struct TwoInANDgate {
  bit result;
  bit* AInput;
  bit* BInput;
} TwoInANDgate;

typedef struct ThreeInANDgate {
  bit result;
  bit* AInput;
  bit* BInput;
  bit* CInput;
} ThreeInANDgate;

typedef struct TwoInORgate {
  bit result;
  bit* AInput;
  bit* BInput;
} TwoInORgate;

typedef struct ThreeInORgate {
  bit result;
  bit* AInput;
  bit* BInput;
  bit* CInput;
} ThreeInORgate;

void UpdateTwoInANDgate(TwoInANDgate* ANDgate);

void UpdateThreeInANDgate(ThreeInANDgate* ANDgate);

void UpdateTwoInORgate(TwoInORgate* ORgate);

void UpdateThreeInORgate(ThreeInORgate* ORgate);
