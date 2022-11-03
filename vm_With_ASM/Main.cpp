/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description: Main  
 *
 *        Version:  1.0
 *        Created:  05/19/2020 23:32:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "CPU.hpp"
#include "ControlUnit.hpp"
#include "Program.hpp"

#include "Move.hpp"
#include "Store.hpp"

#include "AL.hpp"
#include "BL.hpp"

#include "ADD.hpp"
#include "SUB.hpp"
#include "MULT.hpp"
#include "DIV.hpp"

#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main(int argc, char* argv[])
{
	// Creating Memory
	Memory memory;
	// Storing values, to add, in Memory  
        memory.setData(6, 2);
        memory.setData(7, 1);

	// Creating and initializing START instruction 
	Instruction start("START", 50, 1);
	// Creating a Register/AL object
	AL al("AL");
	// Creating a Register/BL object
	BL bl("BL");
	// Creating and initializing move instructions 
	Move move1(&al,6);
	Move move2(&bl,7);
	// Creating and initializing and ADD instruction
	ADD add(&al, &bl);
	SUB sub(&al, &bl);
	MULT mult(&al, &bl);
	DIV div(&al, &bl);

	// Creating and initializing STORE(STO) instruction 
	Store store(8);
	// Creating and initializing STOP instruction 
	Instruction stop("STOP", 51, 1);
	
	// Creating a Program object
	Program program;
	ControlUnit cu;

	int option;	
	cout<< "Choise one option: " << endl;
	cout<<"1. ADD\n";
	cout<<"2. SUB\n";
	cout<<"3. MULT\n";
	cout<<"4. DIV\n";
	
	cin>>option;
	
		if (option == 1)
		{
	
		// Add
			ControlUnit(option);
			program.addInstruction(&start);
			program.addInstruction(&move1);
			program.addInstruction(&move2);
			program.addInstruction(&add);
			program.addInstruction(&store);
			program.addInstruction(&stop);
		}
		if (option == 2) {
		// SUB
			ControlUnit(option);
			program.addInstruction(&start);
			program.addInstruction(&move1);
			program.addInstruction(&move2);
			program.addInstruction(&sub);
			program.addInstruction(&store);
			program.addInstruction(&stop);
		}
		if (option == 3) 
		{
		 // MULT
		 	ControlUnit(option);
			program.addInstruction(&start);
			program.addInstruction(&move1);
			program.addInstruction(&move2);
			program.addInstruction(&mult);
			program.addInstruction(&store);
			program.addInstruction(&stop);
		}
		if (option == 4) 
		{
			// DIV
			ControlUnit(option);
			program.addInstruction(&start);
			program.addInstruction(&move1);
			program.addInstruction(&move2);
			program.addInstruction(&div);
			program.addInstruction(&store);
			program.addInstruction(&stop);
		}


	// Displaying program instructions
	program.display();
	std::cout  << 6 << ":["  << memory.getData(6) << "]"<< std::endl;	
	std::cout  << 7 << ":["  << memory.getData(7) << "]"<< std::endl;	
	
	// Loading program to memory
	memory.setProgram(program);
       
        // Creating a CPU
	CPU cpu;
	cpu.doMachineCycle(&memory);

	std::cout <<endl <<  store.getAddress() << ":["  << memory.getData(store.getAddress()) << "]"<< std::endl;	

	return EXIT_SUCCESS;
}

