#include "bit.h"

typedef struct In2Out1 {
  bit result;
  bit* AInput;
  bit* BInput;
} In2Out1;

typedef struct In3Out1 {
  bit result;
  bit* AInput;
  bit* BInput;
  bit* CInput;
} In3Out1;

typedef struct XORgate {
  bit result;
  In2Out1 ORgate;
  In2Out1 NANDgate;
  In2Out1 ANDgate;
}XORgate;

void UpdateTwoInANDgate(In2Out1* ANDgate);

void UpdateThreeInANDgate(In3Out1* ANDgate);

void UpdateTwoInNANDgate(In2Out1* ANDgate);

void UpdateThreeInNANDgate(In3Out1* ANDgate);

void UpdateTwoInORgate(In2Out1* ORgate);

void UpdateThreeInORgate(In3Out1* ORgate);

void UpdateTwoInNORgate(In2Out1* ORgate);

void UpdateThreeInNORgate(In3Out1* ORgate);

void SetupXORgate(XORgate* XORgate);

void UpdateTwoInXORgate(XORgate* XORgate);
