#include "CPU.hpp"
#include "ControlUnit.hpp"
#include "Memory.hpp"
#include "Alu.hpp"
#include "IR.hpp"
#include "AL.hpp"
#include "BL.hpp"
#include "Move.hpp"
#include "Store.hpp"

#include "ADD.hpp"
#include "SUB.hpp"
#include "MULT.hpp"
#include "DIV.hpp"

#include <iostream>

ControlUnit::ControlUnit()
{
	this->status = "STOPPED";
}

Instruction *ControlUnit::fetch(Program theProgram, int theAddress)
{
	this->status = "FETCHED";
	std::cout << this->status << "  theAddress:: " << theAddress << endl;

	auto *instruction = theProgram.getInstruction(theAddress);

	std::cout << this->status << " instruction:: I" << theAddress << endl;

	return instruction;
}

void ControlUnit::decode(Instruction *theInstruction, Memory *memory)
{
	Move *move;
	Store *sto;
	AL *al;
	BL *bl;

	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
	ADD *add;
	// SUB* sub;
	// MULT* mult;
	// DIV *div;
	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //


	this->status = "DECODED";

	switch (theInstruction->getCode())
	{
	case Instruction::START:
		std::cout << this->status << " Instruction:: " << theInstruction->getName() << endl;
		execute(theInstruction->getName());
		break;

	case Instruction::STOP:
		std::cout << this->status << " Instruction:: " << theInstruction->getName() << endl;
		execute(theInstruction->getName());
		break;

	case Instruction::MOV:
		move = static_cast<Move *>(theInstruction);
		std::cout << this->status << " Instruction:: " << theInstruction->getName() << " "
				  << move->getRegister()->getName() << ","
				  << move->getAddress() << endl;

		if ((move->getRegister()->getName()).compare("AL") == 0)
		{
			al = static_cast<AL *>(move->getRegister());
			al->setValue(memory->getData(move->getAddress()));
			CPU::al.setValue(al->getValue());
			execute(theInstruction->getName(), al->getValue());
		}
		else
		{
			bl = static_cast<BL *>(move->getRegister());
			bl->setValue(memory->getData(move->getAddress()));
			CPU::bl.setValue(bl->getValue());
			execute(theInstruction->getName(), bl->getValue());
		}
		break;

	case Instruction::STO:
		sto = static_cast<Store *>(theInstruction);
		std::cout << this->status << " Instruction:: " << theInstruction->getName() << "  "
				  << sto->getAddress() << endl;

		execute(sto->getAddress(), memory);
		break;

	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
	case Instruction::ADD:
		std::cout << "ADD";
		add = static_cast<ADD *>(theInstruction);
		al = static_cast<AL *>(add->getReg1());
		bl = static_cast<BL *>(add->getReg2());

		std::cout << this->status << " Instruction:: " << theInstruction->getName() << "  "
				  << al->getValue() << ", "
				  << bl->getValue()
				  << endl;

		execute(theInstruction->getName(), al->getValue(), bl->getValue());
		break;

	// case Instruction::SUB:

	// 	std::cout << "SUB";
	// 	sub = static_cast<SUB *>(theInstruction);

	// 	al = static_cast<AL *>(sub->getReg1());
	// 	bl = static_cast<BL *>(sub->getReg2());

	// 	std::cout << this->status << " Instruction:: " << theInstruction->getName() << "  "
	// 			  << al->getValue() << ", "
	// 			  << bl->getValue()
	// 			  << endl;

	// 	execute(theInstruction->getName(), al->getValue(), bl->getValue());
	// 	break;

	// case Instruction::MULT:

	// 	std::cout << "MULT";
	// 	mult = static_cast<MULT *>(theInstruction);

	// 	al = static_cast<AL *>(mult->getReg1());
	// 	bl = static_cast<BL *>(mult->getReg2());

	// 	std::cout << this->status << " Instruction:: " << theInstruction->getName() << "  "
	// 			  << al->getValue() << ", "
	// 			  << bl->getValue()
	// 			  << endl;

	// 	execute(theInstruction->getName(), al->getValue(), bl->getValue());
	// 	break;

	// case Instruction::DIV:

	// 	std::cout << "DIV";
	// 	div = static_cast<DIV *>(theInstruction);

	// 	al = static_cast<AL *>(div->getReg1());
	// 	bl = static_cast<BL *>(div->getReg2());

	// 	std::cout << this->status << " Instruction:: " << theInstruction->getName() << "  "
	// 			  << al->getValue() << ", "
	// 			  << bl->getValue()
	// 			  << endl;

	// 	execute(theInstruction->getName(), al->getValue(), bl->getValue());
	// break;

	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
	default:
		break;
	}
}

void ControlUnit::execute(std::string decodedInstruction)
{
	this->status = "Executing";
	std::cout << this->status << " Instruction:: " << decodedInstruction << endl;

	if (decodedInstruction.compare("START") == 0)
		std::cout << "Starting Program" << endl;
	else
		std::cout << "Stoppig Programa" << endl;
}

void ControlUnit::execute(int theAddress, Memory *memory)
{
	this->status = "Executing";

	memory->setData(theAddress, CPU::acc.getValue());

	std::cout << this->status << " Instruction:: "
			  << "STO..." << endl;
	std::cout << "Storing at Memory Address:: " << theAddress << " the value from the Accumulator:: "
			  << CPU::acc.getValue() << endl;
	std::cout << endl;
}

void ControlUnit::execute(std::string theRegister, int theValue)
{
	this->status = "Executing";
	std::cout << this->status << " Instruction:: "
			  << "MOV..." << endl;
	std::cout << "Moving to register:: " << theRegister << " the value::  " << theValue << endl;
	std::cout << endl;
}

void ControlUnit::execute(std::string decodedInstruction, int theOperand1, int theOperand2)
{

	Alu alu(theOperand1, theOperand2);

	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
	CPU::acc.setValue(alu.add());
	// CPU::acc.setValue(alu.substraction());
	// CPU::acc.setValue(alu.mult());
	// CPU::acc.setValue(alu.div());

	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //

	this->status = "Executing";
	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //

	if (decodedInstruction.compare("ADD") == 0)
	{
		std::cout << this->status << " Instruction:: "
				  << "ADD..." << endl;
		std::cout << "ADDING:: " << theOperand1 << " + " << theOperand2 << " = "
				  << CPU::acc.getValue() << endl;
		std::cout << endl;
	}

	// if (decodedInstruction.compare("SUB") == 0)
	// {
	// 	std::cout << this->status << " Instruction:: "
	// 			  << "SUB..." << endl;
	// 	std::cout << "SUBTRACTING:: " << theOperand1 << " - " << theOperand2 << " = "
	// 			  << CPU::acc.getValue() << endl;
	// 	std::cout << endl;
	// }
	// if (decodedInstruction.compare("MULT") == 0)
	// {
	// 	std::cout << this->status << " Instruction:: "
	// 			  << "MULT..." << endl;
	// 	std::cout << "MULTIPLAYING:: " << theOperand1 << " * " << theOperand2 << " = " << CPU::acc.getValue() << endl;
	// 	std::cout << endl;
	// }
	// if (decodedInstruction.compare("DIV") == 0)
	// {
	// 	std::cout << this->status << " Instruction:: "
	// 			  << "DIV..." << endl;
	// 	std::cout << "DIVING:: " << theOperand1 << " / " << theOperand2 << " = " << CPU::acc.getValue() << endl;
	// 	std::cout << endl;
	// }

	//----------------------------  ARITHMETIC OPERATIONS ---------------------------- //
}
