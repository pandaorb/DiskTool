#ifndef COMMAND_H
#define COMMAND_H

#include<iostream>
using namespace std;

/* Holds entire user command. 
 * Used to build command line.
 */
class Command
{
	string input;
	public:	
	Command();
	Command(string userInput);
	string getInput();
	void setInput(string newCommand);
};

#endif
