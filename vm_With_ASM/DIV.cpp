#include "DIV.hpp"
#include <iostream>

DIV::DIV(){}

DIV::DIV(Register* theReg1, Register* theReg2): Instruction("DIV", 57, 3)
{
	reg1 = theReg1;
	reg2 = theReg2;
}

int DIV::getOperand1()
{
	return operand1;
}

int DIV::getOperand2()
{
	return operand2;
}

Register* DIV::getReg1()
{
	return reg1;
}

Register* DIV::getReg2()
{
	return reg2;
}


