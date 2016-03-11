#include<iostream>
#include<string>
#include<fstream>
#include "report.h"
using namespace std;

/* Default constructor */
Report::Report()
{
}

/* Constructor for Report */
Report::Report(vector<DiskStat> newRecordSet)
{
	for(int i = 0; i < recordSet.size(); i++)
	{
		recordSet[i] = newRecordSet[i];
	}
}

/* 
 * Appends shown records to report file previously
 * specified by user.
 * Parameters: bool - determining which data was requested.
 * Return: none
 */
void Report::storeDiskStats(bool showBlkRead, bool showBlkReadS, bool showBlkWrite, bool showBlkWriteS, bool showKbReadS, bool showKbWriteS)
{
	ofstream outStream;
	outStream.open(reportName.c_str(), ios::app);
	
	for(int i = 0; i < recordSet.size(); i++)
	{
			outStream << "Disk Name: " << recordSet[i].getDiskName() << endl; 	
		if(showBlkRead) 
			outStream << "\tblk_read: " << recordSet[i].getBlkRead() << endl; 
		if(showBlkReadS)
			outStream << "\tblk_read/s: " << recordSet[i].getBlkReadS() << endl;
		if(showKbReadS)
			outStream << "\tkb_read/s: " << recordSet[i].getKbReadS() << endl;
		if(showBlkWrite)
			outStream << "\tblk_wrtn: " << recordSet[i].getBlkWrtn() << endl;
		if(showBlkWriteS)
			outStream << "\tblk_wrtn/s: " << recordSet[i].getBlkWrtnS() << endl;
		if(showKbWriteS)
			outStream << "\tkb_wrtn/s: " << recordSet[i].getKbWrtnS() << endl;
		outStream << endl;
	}

	outStream.close();
}

/* 
 * Prints report file to screen
 * Parameters: none
 * Return: none
 */
void Report::printReport()
{
	string data;
	ifstream instream;
	instream.open(reportName.c_str());
	if(instream.is_open())
	{
		while(getline(instream, data))
		{
			cout << data << "\n";
		}
		instream.close();
	}
	else
	{
		cout << "No record found in '" << reportName << "'." << endl;
	}
}

/* 
 * Returns a list of all records being
 * held in report.
 * Parameters: none
 * Return: vector<DiskStat> - all records
 */
vector<DiskStat> Report::getAllRecords()
{
	return recordSet;
}

/* 
 * Adds a new record to recordSet
 * Parameters: newRecord - record to add
 * Return: None
 */
void Report::addRecord(DiskStat newRecord)
{
	recordSet.push_back(newRecord);
}

/* Accessor for reportName */
string Report::getReportName()
{
	return reportName;
}

/* Mutator for reportName */
void Report::setReportName(string newReportName)
{
	reportName = newReportName;
}
