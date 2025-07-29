#include "logicgates.h"
#include "iostream"
#include "iomanip"

 typedef struct logicTest {
  struct bit inputBits[3];
  struct In2Out1 testANDgate;
  struct In2Out1 testORgate;
  struct In3Out1 test3ANDgate;
  struct In3Out1 test3ORgate;
} logicTest;

logicTest logic;

int main(int argc, char* argv[]) {
  int key;

  logic.testANDgate.AInput = logic.testORgate.AInput = logic.test3ANDgate.AInput = logic.test3ORgate.AInput = &logic.inputBits[0];
  logic.testANDgate.BInput = logic.testORgate.BInput = logic.test3ANDgate.BInput = logic.test3ORgate.BInput = &logic.inputBits[1];
  logic.test3ANDgate.CInput = logic.test3ORgate.CInput = &logic.inputBits[2];

  UpdateBit(true, logic.testANDgate.AInput);
  UpdateBit(true, logic.testANDgate.BInput);
  UpdateTwoInANDgate(&logic.testANDgate);

  std::cout << "Test for double true ANDgate: "<< logic.testANDgate.result.signal << std::endl;

  UpdateTwoInORgate(&logic.testORgate);

  std::cout << "Test for double true ORgate: "<< logic.testORgate.result.signal << std::endl;

  UpdateBit(false, logic.testORgate.AInput);
  UpdateTwoInORgate(&logic.testORgate);

  std::cout << "Test for singal true ORgate: "<< logic.testORgate.result.signal << std::endl;

  UpdateBit(true, logic.test3ANDgate.CInput);
  UpdateThreeInANDgate(&logic.test3ANDgate);

  std::cout << "Test for 2 true 1 false 3ANDgate: "<< logic.test3ANDgate.result.signal << std::endl;

  XORgate testXORgate;
  In2Out1 XORinputs[3];
  bit XORbits[6]; //Only needs 4 Inputs because the Or and Nand share same inputs

  for(int i = 0, j = 0 ; i < 3; i++, j += 2) {
    XORinputs[i].AInput = &XORbits[j];
    XORinputs[i].BInput = &XORbits[j+1];
  }

  testXORgate.ORgate = XORinputs[0];
  testXORgate.NANDgate = XORinputs[1];
  testXORgate.ANDgate = XORinputs[2];

  for(int i = 0; i < 3; i++) {
    XORinputs[i].AInput->signal = false;
    XORinputs[i].BInput->signal = false;
  }

  SetupXORgate(&testXORgate);
  UpdateTwoInXORgate(&testXORgate);
  
  std::cout << testXORgate.result.signal << std::endl;

  XORinputs[0].AInput->signal = true;
  XORinputs[1].AInput->signal = true;

  UpdateTwoInXORgate(&testXORgate);

  std::cout << testXORgate.result.signal << std::endl;

  std::cin >> key;
}

