/*
 * =====================================================================================
 *
 *       Filename:  Alu.cpp
 *
 *    Description: Implementation 
 *
 *        Version:  1.0
 *        Created:  05/25/2020 00:01:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "Alu.hpp"

Alu::Alu() {}

Alu::Alu(int theOperand1, int theOperand2)
{
	operand1 = theOperand1;
	operand2 = theOperand2;
}

void Alu::setOperand1(int theOperand)
{
	operand1 = theOperand;
}

void Alu::setOperand2(int theOperand)
{
	operand2 = theOperand;
}

int Alu::getOperand1()
{
	return operand1;

}

int Alu::getOperand2()
{
	return operand2;
}

int Alu::add()
{

 int res;
	__asm("addl %%ebx, %%eax;"
	: "=a" (res)
	: "a" (operand1), "b"(operand2));

    return res;
}


int Alu::substraction()
{
	 int res;

    __asm("subl %%ebx, %%eax;"
          : "=a"(res)
          : "a"(operand1), "b"(operand2));

    return res;
}

int Alu::mult()
{
    int res;

    __asm("imull %%ebx, %%eax;"
          : "=a"(res)
          : "a"(operand1), "b"(operand2));

    return res;
}


int Alu::div()
{
    int res = 0;
    int rem = 0;

    __asm("movl $0x0, %%edx;"
          "movl %2, %%eax;"
          "movl %3, %%ebx;"
          "idivl %%ebx;"
          : "=a"(res), "=d"(rem)
          : "g"(operand1), "g"(operand2));
    
    return res;

}