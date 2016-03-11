#include<iostream>
#include<string>
#include "commandLine.h"
using namespace std;

/* Default constructor for CommandLine */
CommandLine::CommandLine()
{
}

/* Constructor for CommandLine */
CommandLine::CommandLine(Command commandIn):command(commandIn)
{
	setType(command.getInput());
}

/* Accessor for command */
Command CommandLine::getCommand()
{
	return command;
}

/* Mutator for command */
void CommandLine::setCommand(Command newCommand)
{
	command = newCommand;
}

/* Accessor for type */
commandType CommandLine::getType()
{
	return type;
}

/* Mutator for getType */
void CommandLine::setType(string newCommand)
{
	if(newCommand == "run") type = RUN;
	else if(newCommand == "set") type =  SET;
	else if(newCommand == "print") type = PRINT;
	else if(newCommand == "save") type = SAVE;
	else if(newCommand == "exit") type = EXIT;
	else { type = HELP; }
}
