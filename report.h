#ifndef REPORT_H
#define REPORT_H

#include<iostream>
#include<vector>
#include "diskStat.h"
using namespace std;

/*
 * Report class will access information being held
 * in DiskStat and store it for output to either 
 * the screen or a file.
 */
class Report
{
	string reportName;
	vector<DiskStat> recordSet;
	int numRecords;
	public:
	Report();
	Report(vector<DiskStat> newRecordSet);
	void storeDiskStats(bool, bool, bool, bool, bool, bool);
	void printReport();
	vector<DiskStat> getAllRecords();
	void addRecord(DiskStat newRecord);
	string getReportName();
	void setReportName(string newRptName);
	
};

#endif
