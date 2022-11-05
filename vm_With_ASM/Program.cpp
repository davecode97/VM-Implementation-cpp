/*
 * =====================================================================================
 *
 *       Filename:  Memory.cpp
 *
 *    Description: Implementation
 *
 *        Version:  1.0
 *        Created:  05/25/2020 19:01:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
#include "Program.hpp"
#include "Move.hpp"
#include "Store.hpp"
#include "AL.hpp"
#include "BL.hpp"

#include "ADD.hpp"
#include "SUB.hpp"
#include "MULT.hpp"
#include "DIV.hpp"

using namespace std;

Program::Program()
{
	instructionIndex = 0;
}

void Program::addInstruction(Instruction *theInstruction)
{
	if (instructionIndex <= 10)
	{
		instructions[instructionIndex] = theInstruction;
		instructionIndex++;
	}
}

Instruction *Program::getInstruction(int theAddress)
{
	return instructions[theAddress];
}

Instruction *Program::getInstructions()
{
	return *instructions;
}

void Program::display()
{
	Move *move;
	Store *sto;
	AL *al;
	BL *bl;

	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
	ADD* add;
	// SUB* sub;
	// MULT *mult;
	// DIV* div;
	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //

	cout << "Memory: " << endl;
	cout << endl;

	for (int address = 0; address < instructionIndex; address++)
	{

		auto *theInstruction = getInstruction(address);

		switch (theInstruction->getCode())
		{
		case Instruction::START:

			std::cout << address << ":[" << theInstruction->getName() << "]" << endl;
			break;

		case Instruction::STOP:

			std::cout << address << ":[" << theInstruction->getName() << "]" << endl;
			break;

		case Instruction::MOV:
			move = static_cast<Move *>(theInstruction);

			std::cout << address << ":[" << theInstruction->getName() << " " << move->getRegister()->getName() << "," << move->getAddress() << "]" << endl;
			break;

		case Instruction::STO:

			sto = static_cast<Store *>(theInstruction);
			std::cout << address << ":[" << theInstruction->getName() << "  "
					  << sto->getAddress() << "]" << endl;

			break;

			//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
			   case Instruction::ADD:

				add = static_cast<ADD*>(theInstruction);

			                al = static_cast<AL*>(add->getReg1());
			                bl = static_cast<BL*>(add->getReg2());

				std::cout << address << ":[" << theInstruction->getName() << "  "
				     << al->getValue() << ", "
				     << bl->getValue()
				     << "]" << endl;

				break;

			//    case Instruction::SUB:

			// 	sub = static_cast<SUB*>(theInstruction);

			//                 al = static_cast<AL*>(sub->getReg1());
			//                 bl = static_cast<BL*>(sub->getReg2());

			// 	std::cout << address << ":[" << theInstruction->getName() << "  "
			// 	     << al->getValue() << ", "
			// 	     << bl->getValue()
			// 	     << "]" << endl;

			// 	break;

		// case Instruction::MULT:

		// 	mult = static_cast<MULT *>(theInstruction);

		// 	al = static_cast<AL *>(mult->getReg1());
		// 	bl = static_cast<BL *>(mult->getReg2());

		// 	std::cout << address << ":[" << theInstruction->getName() << "  "
		// 			  << al->getValue() << ", "
		// 			  << bl->getValue()
		// 			  << "]" << endl;

		// 	break;

			// case Instruction::DIV:

			// div = static_cast<DIV*>(theInstruction);

			//             al = static_cast<AL*>(div->getReg1());
			//             bl = static_cast<BL*>(div->getReg2());

			// std::cout << address << ":[" << theInstruction->getName() << "  "
			//      << al->getValue() << ", "
			//      << bl->getValue()
			//      << "]" << endl;

			// break;
			//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //

		default:
			break;
		}
	}
}

void Program::displayInstructions()
{
	cout << "This program contains the following instructions: " << endl;
	cout << endl;

	for (int address = 0; address < instructionIndex; address++)
	{

		auto *instruction = getInstruction(address);
		Move *move;
		Store *sto;

		//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
		ADD* add;
		// SUB* sub;
		// MULT *mult;
		// DIV* div;
		//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //

		switch (instruction->getCode())
		{
		case Instruction::START:
			cout << address << ": " << instruction->getName() << endl;
			break;

		case Instruction::STOP:
			cout << address << ": " << instruction->getName() << endl;
			break;

		case Instruction::MOV:
			move = static_cast<Move *>(instruction);

			std::cout << " Instruction:: " << instruction->getName() << " "
					  << move->getRegister()->getName() << ","
					  << move->getAddress() << endl;
			break;

		case Instruction::STO:
			sto = static_cast<Store *>(instruction);
			;

			cout << address << ": "
				 << instruction->getName() << " "
				 << sto->getAddress()
				 << endl;
			break;

			// //----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
			case Instruction::ADD:
				add = static_cast<ADD*>(instruction);

				cout << address << ": "
				     << instruction->getName() << " "
			     	     << add->getOperand1() << ", "
			     	     << add->getOperand2()
			             << endl;
				break;

			// case Instruction::SUB:
			// sub = static_cast<SUB*>(instruction);

			// cout << address << ": "
			//      << instruction->getName() << " "
			//  	     << sub->getOperand1() << ", "
			//  	     << sub->getOperand2()
			//          << endl;
			// break;

		// case Instruction::MULT:
		// 	mult = static_cast<MULT *>(instruction);

		// 	cout << address << ": "
		// 		 << instruction->getName() << " "
		// 		 << mult->getOperand1() << ", "
		// 		 << mult->getOperand2()
		// 		 << endl;
		// 	break;

			// case Instruction::DIV:
			// div = static_cast<DIV*>(instruction);

			// cout << address << ": "
			//      << instruction->getName() << " "
			//  	     << div->getOperand1() << ", "
			//  	     << div->getOperand2()
			//          << endl;
			// break;

			//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //

		default:
			break;
		}
	}
}
