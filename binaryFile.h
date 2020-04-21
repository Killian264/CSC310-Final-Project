#ifndef __BINARYFILE__H__
#define __BINARYFILE__H__

#include <iostream>
#include <string>

using namespace std;


typedef struct EMPLOYEE {
	char name[30];
	int departmentNumber;
	int employeeNumber;
}employee;


class binaryFile {
public:
	// constructor
	binaryFile(string baseFilePath, string baseFileName, string binaryFilePath, string binaryFileName);
	// destructor
	~binaryFile();

	// params: int departmentNumber, int employeeNumber
	// return: found
	bool findEmployee(int, int);

	// params: int departmentNumber, int employeeNumber
	// return: updated
	bool updateEmployeeName(int, int, string);
    

private:
	// This can be change later but in the current setup the paths of the files will be stored here
	// When a function is called that needs to access the binary file the function will open the file and do stuff then close it
	string baseFilePath;
	string baseFileName;
	string binaryFilePath;
	string binaryFileName;

	// this will fill the binary file at binaryFilePath + binaryFileName
	void p_fillBinaryFile();

	// this will sort the binary file at binaryFilePath + binaryFileName
	void p_sortBinaryFile();

	// params: int departmentNumber, int employeeNumber
	// return: found
	bool p_findEmployee(int, int);

	// params: int departmentNumber, int employeeNumber
	// return: updated
	bool p_updateEmployeeName(int, int, string);

};

#endif