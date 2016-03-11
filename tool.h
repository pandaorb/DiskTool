#ifndef TOOL_H
#define TOOL_H

#include<iostream>
#include "commandLine.h"
#include "diskStat.h"
#include "configInfo.h"
#include "report.h"
using namespace std;

namespace myTool
{
	/*
	 * Tool coordinates all other components to
	 * allow user monitoring of proc/diskstat.
	 */
	class Tool
	{
		CommandLine commandLine;
		DiskStat status;
		ConfigInfo configuration;
		Report report;
		public:
		Tool();
		Tool(CommandLine newCommand, DiskStat newStatus, ConfigInfo newConfig);
		void init();
		void menu();
		void run();
		void help();
		void set();
		void print();
		void save();
		void exit();
	};
}

#endif
