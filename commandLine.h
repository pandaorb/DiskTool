#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include<iostream>
#include "command.h"
using namespace std;

/* Types of commands */
enum commandType {RUN, HELP, SET, PRINT, SAVE, EXIT};

/* Used by tool to handle user input */
class CommandLine
{
	Command command;
	commandType type;
	public:
	CommandLine();
	CommandLine(Command commandIn);
	Command getCommand();
	void setCommand(Command newCommand);
	commandType getType();
	void setType(string newType);
};

#endif
