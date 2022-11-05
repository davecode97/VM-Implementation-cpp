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
#include <stdio.h>


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
	res = operand1 + operand2;

    return res;
}


int Alu::substraction()
{
	int res;
    res = operand1 - operand2;

    return res;
}

int Alu::mult()
{
    int res;
    res = operand1 * operand2;

    return res;
}


double Alu::div()
{
    double res = 0;
    res = operand1 / operand2;
    
    return res;
}