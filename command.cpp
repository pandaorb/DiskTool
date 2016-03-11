#include<iostream>
#include<string>
#include "command.h"
using namespace std;

/* Default Command constructor */
Command::Command()
{
}

/* Command constructor */
Command::Command(string inputIn):input(inputIn)
{
}

/* Accessor for input */
string Command::getInput()
{
	return input;	
}

/* Mutator for input */
void Command::setInput(string newCommand)
{
	input = newCommand;
}
