/* 
* Allison Macdonald
* amm0086
* project2
*
* File help - http://www.cplusplus.com/doc/tutorial/files/ 
* Debugging help - stackoverflow.com
*/

#include<iostream>
#include "tool.h"
using namespace std;
using namespace myTool;

/*
 * Main will run auDiskTool. This tool will
 * scan disk data and send records to a report.
 * Configuration may be manipulated.
 */
int main()
{
	Tool auDiskTool;
	
	auDiskTool.init();
	auDiskTool.menu();
	auDiskTool.exit();
	return 0;
}
