#include "logicgates.h"
#include <stdbool.h>

void UpdateTwoInANDgate(TwoInANDgate *ANDgate){
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

void UpdateThreeInANDgate(ThreeInANDgate *ANDgate){
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

void UpdateTwoInORgate(TwoInORgate *ORgate) {
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

void UpdateThreeInORgate(ThreeInORgate *ORgate) {
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
