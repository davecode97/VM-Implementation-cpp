#ifndef MULT_HPP
#define MULT_HPP

#include "Instruction.hpp"
#include "AL.hpp"
#include "BL.hpp"

class MULT: public Instruction 
{
	private:
		int operand1;
		int operand2;
		Register* reg1;
		Register* reg2;

	public:
		MULT();
		MULT(Register* theReg1, Register* theReg2);
	       	int getOperand1();
	       	int getOperand2();
	       	Register* getReg1();
	       	Register* getReg2();
};
#endif