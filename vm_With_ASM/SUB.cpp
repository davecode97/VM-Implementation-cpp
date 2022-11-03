#include "SUB.hpp"
#include <iostream>

SUB::SUB(){}

SUB::SUB(Register* theReg1, Register* theReg2): Instruction("SUB", 55, 3)
{
	reg1 = theReg1;
	reg2 = theReg2;
}

int SUB::getOperand1()
{
	return operand1;
}

int SUB::getOperand2()
{
	return operand2;
}

Register* SUB::getReg1()
{
	return reg1;
}

Register* SUB::getReg2()
{
	return reg2;
}