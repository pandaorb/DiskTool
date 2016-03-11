#include<iostream>
#include<fstream>
#include<string>
#include <unistd.h>
#include<cstdlib>
#include "tool.h"
using namespace std;

namespace myTool
{
	/* Default constructor for Tool */
	Tool::Tool()
	{
	}

	/* Constructor for Tool */
	Tool::Tool(CommandLine newCommand, DiskStat newStatus, ConfigInfo newConfig):commandLine(newCommand), status(newStatus), configuration(newConfig)
	{
	}

	/* Initializes each member of Tool */
	void Tool::init()
	{
		status.getDiskInfo();
		configuration.readConfigFile();
		configuration.setChangeFlag(false);
		report.setReportName("report.adt");
	}

	/*
	 * Display a greeting from which user may control
	 * the tool. Any invalid input will display help and 
	 * allow user to try again.
 	 * Parameter: none
	 * Return: none
 	 */
	void Tool::menu()
	{
		string input;
		cout << "auDiskTool, version 1.0.0. Type 'help' to find more about commands." << endl;
		getline(cin, input);
		commandLine.setCommand(Command(input));
		int typeLocation = input.find(" ");
		string type = input.substr(0,typeLocation);
		commandLine.setType(type);
		commandType action = commandLine.getType();
		switch(action)
		{
			case RUN:
				run();
				break;
			case SET:
				set();
				break;
			case PRINT:
				print();
				break;
			case SAVE:
				save();
				break;
			case EXIT:
				return;
			case HELP:
			default:
				help();
				break;
		}
		menu();
	}

	/*
	 * Allows the tool to grab the most recent data. After each
	 * data pull the tool will store the record and then
	 * wait the number of seconds specified in
	 * the config file before creating another record.
	 * Parameter: none
	 * Return: none
	 */ 
	void Tool::run()
	{
		configuration.readConfigFile();
		configuration.printFile();
		cout << "report file name = " << report.getReportName() << endl;
		cout << "Please wait...\n" << endl;
		for(int i = 0; i < configuration.getCount(); i++)
		{
			status.getDiskInfo();
			status.setKbReadS(status.getBlkRead()/(2*configuration.getInterval()));
			status.setKbWrtnS(status.getBlkWrtn()/(2*configuration.getInterval()));
			report.addRecord(status);
			sleep(configuration.getInterval());
		}
		report.storeDiskStats(configuration.getIsBlkRead(), configuration.getIsBlkReadS(), configuration.getIsBlkWrtn(), configuration.getIsBlkWrtnS(), configuration.getIsKbReadS(), configuration.getIsKbWrtnS());
		cout << "A file '" << report.getReportName() << "' is updated." << endl;
	}

	/*
	 * Allows the users to set various parameters in config file
	 * as well as file name.
	 * Parameter: none
	 * Return: none
	 */
	void Tool::set()
	{
		string setCmd = commandLine.getCommand().getInput();
		unsigned int startPosition = setCmd.find(" ");
		unsigned int endPosition = setCmd.find(" ", startPosition+1);
		unsigned int length = endPosition - startPosition;
		string parameter = setCmd.substr(startPosition+1, length-1);
		startPosition = endPosition;
		endPosition = setCmd.find(" ", startPosition+1);
		string value = setCmd.substr(startPosition+1);
	
		if(parameter == "report") 
		{
			string oldName = report.getReportName();
			report.setReportName(value);
			cout << "The report file name is changed from '" << oldName << "' to '" << value << "'. \n"
			<< "You can now type 'run' to generate new records to be saved in '" << value << "'. \n"
			<< "Note: '" << oldName << "' will not be deleted by audisktool." << endl;
		}
		else if(parameter == "count")
		{
			configuration.setCount(atoi(value.c_str()));
			cout << "The number of records generated in each run has been changed to " << value << endl;
		}
		else if(parameter == "interval")
		{
			configuration.setInterval(atoi(value.c_str()));
			cout << "The sampling interval has bee nchanged to " << value << " seconds."<< endl;
		}
		else if(atoi(value.c_str()) != 0 && atoi(value.c_str()) != 1)
		{
			cout << "Please enter either 0 or 1 for value. " << endl;
			return;
		}
		else if(parameter == "blk_read")
		{
			configuration.setIsBlkRead(atoi(value.c_str()));
			cout << "Print_blk_read has been changed to " << value << endl;
		}
		else if(parameter == "blk_read/s")
		{
			configuration.setIsBlkReadS(atoi(value.c_str()));
			cout << "Print_blk_read/s has been changed to " << value << endl;
		}
		else if(parameter == "kb_read/s ")
		{
			configuration.setIsKbReadS(atoi(value.c_str()));
			cout << "Print_kb_read/s has been changed to " << value << endl;
		}
		else if(parameter == "blk_write")
		{
			configuration.setIsBlkWrtn(atoi(value.c_str()));
			cout << "Print_blk_write has been changed to " << value << endl;
		}
		else if(parameter == "blk_read/s")
		{
			configuration.setIsBlkWrtnS(atoi(value.c_str()));
			cout << "Print_blk_read/s has been changed to " << value << endl;
		}
		else if(parameter == "kb_write/s")
		{
			configuration.setIsKbWrtnS(atoi(value.c_str()));
			cout << "Print_kb_write/s has been changed to " << value << endl;
		}
		else 
		{
			cout << "Please enter a valid parameter." << endl;
			return;
		}
		configuration.setChangeFlag(true);
	}

	/*
	 * At user request prints either config file or current
	 * report to the screen.
	 * Parameters: none
	 * Return: none
	 */
	void Tool::print()
	{
		string printCmd = commandLine.getCommand().getInput();
		unsigned int startPosition = printCmd.find(" ");
		string requested = printCmd.substr(startPosition+1);
	
		if(requested == "conf")
		{	
			configuration.printFile();
		}
		else if(requested == "report")
		{
			report.printReport();
		}
		else
		{
			cout << "Please enter a valid parameter." << endl;
		}
	}

	/*
	 * Saves config file with changed parameters.
	 * Parameter: none
	 * Return: none
	 */
	void Tool::save()
	{
		configuration.saveConfig();
	}

	/*
	 * Prints various possible instructions so that user knows
	 * how to use the tool.
	 * Parameter: none
	 * Return: none
	 */
	void Tool::help()
	{
		cout << "\n";
		cout << "run - run the monitoring tool. " << endl;
		cout << "set interval [value] - set sampling period to [value]" << endl;
		cout << "set count [value] - set the number of records to [value]" << endl;
		cout << "set report [name] - set report file name to [name]" << endl;
		cout << "set blk_read [0|1] - set print_blk_read to 0 or 1" << endl;
		cout << "set blk_read/s [0|1] - set print_blk_read/s to 0 or 1" << endl;
		cout << "set kb_read/s [0|1] - set print_kb_read/s to 0 or 1" << endl;
		cout << "set blk_write [0|1] - set print_blk_write to 0 or 1" << endl;
		cout << "set blk_write/s [0|1] - set print_blk_write/s to 0 or 1" << endl;
		cout << "set kb_write/s [0|1] - set print_kb_write to 0 or 1" << endl;
		cout << "print conf - display all the parameters" << endl;
		cout << "print report - open and display the report file" << endl;
		cout << "save - the configuration file audisktool.conf is updated" << endl;
		cout << "exit - exit the tool\n" << endl;
	}

	/*
	 * Closes files and exits tool
	 * Parameter: none
	 * Return: none
	 */
	void Tool::exit()
	{
		//close diskStat and configFile. Oh they're already closed.
	}
}
