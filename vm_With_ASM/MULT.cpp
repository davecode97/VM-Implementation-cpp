#include "MULT.hpp"
#include <iostream>

MULT::MULT(){}

MULT::MULT(Register* theReg1, Register* theReg2): Instruction("MULT", 56, 3)
{
	reg1 = theReg1;
	reg2 = theReg2;
}

int MULT::getOperand1()
{
	return operand1;
}

int MULT::getOperand2()
{
	return operand2;
}

Register* MULT::getReg1()
{
	return reg1;
}

Register* MULT::getReg2()
{
	return reg2;
}


