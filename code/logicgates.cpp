#include "logicgates.h"
#include <stdbool.h>

void UpdateTwoInANDgate(In2Out1* ANDgate){
  if(!ANDgate->AInput->signal) {
    UpdateBit(false, &ANDgate->result);
    return;
  }
  if(!ANDgate->BInput->signal) {
    UpdateBit(false, &ANDgate->result);
    return;
  }
  UpdateBit(true, &ANDgate->result);
  return;
}

void UpdateThreeInANDgate(In3Out1* ANDgate){
  if(!ANDgate->AInput->signal) {
    UpdateBit(false, &ANDgate->result);
    return;
  }
  if(!ANDgate->BInput->signal) {
    UpdateBit(false, &ANDgate->result);
    return;
  }
  if(!ANDgate->CInput->signal) {
    UpdateBit(false, &ANDgate->result);
    return;
  }
  UpdateBit(true, &ANDgate->result);
  return;
}

void UpdateTwoInNANDgate(In2Out1* ANDgate) {
  UpdateTwoInANDgate(ANDgate);
  InvertBit(&ANDgate->result);
}

void UpdateThreeInNANDgate(In3Out1* ANDgate) {
  UpdateThreeInANDgate(ANDgate);
  InvertBit(&ANDgate->result);
}

void UpdateTwoInORgate(In2Out1 *ORgate) {
  if(ORgate->AInput->signal) {
    UpdateBit(true, &ORgate->result); 
    return;
  }
  if(ORgate->BInput->signal) {
    UpdateBit(true, &ORgate->result); 
    return;
  }
  UpdateBit(false, &ORgate->result);
  return;
}

void UpdateThreeInORgate(In3Out1* ORgate) {
  if(ORgate->AInput->signal) {
    UpdateBit(true, &ORgate->result); 
    return;
  }
  if(ORgate->BInput->signal) {
    UpdateBit(true, &ORgate->result); 
    return;
  }
  if(ORgate->CInput->signal) {
    UpdateBit(true, &ORgate->result); 
    return;
  }
  UpdateBit(false, &ORgate->result);
  return;
}

void UpdateTwoInNORgate(In2Out1* ORgate) {
  UpdateTwoInORgate(ORgate);
  InvertBit(&ORgate->result);
}

void UpdateThreeInNORgate(In3Out1* ORgate) {
  UpdateThreeInORgate(ORgate);
  InvertBit(&ORgate->result);
}

void SetupXORgate(XORgate* XORgate) {
  XORgate->ANDgate.AInput = &XORgate->ORgate.result;
  XORgate->ANDgate.BInput = &XORgate->NANDgate.result;
}

void UpdateTwoInXORgate(XORgate* XORgate) {
  UpdateTwoInORgate(&XORgate->ORgate);
  UpdateTwoInNANDgate(&XORgate->NANDgate);
  UpdateTwoInANDgate(&XORgate->ANDgate);

  XORgate->result = XORgate->ANDgate.result;
}

