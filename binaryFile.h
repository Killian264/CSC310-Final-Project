#ifndef __BINARYFILE__H__
#define __BINARYFILE__H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;


typedef struct EMPLOYEE {
	int departmentNumber;
	int employeeNumber;
	char name[30];
}__attribute__((packed))employee;


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

	// params: int departmentNumber, int employeeNumber
    // return: employee information
    string retrieveEmployee(int, int);

private:
	// This can be change later but in the current setup the paths of the files will be stored here
	// When a function is called that needs to access the binary file the function will open the file and do stuff then close it
	string baseFilePath;
	string binaryFilePath;
	//binary index to search only department specified in search
	// int departmentLoc[5];
	vector<int> departmentLocations;

	// this will load in employees to a vector
	vector<employee> p_loadEmployees();

	//this will help sort employees by more than one field
	static bool p_sortHelper(const employee&, const employee&);

	// this will sort the vector of employees given to it
	vector<employee> p_sortEmployees(vector<employee>);

	// this will write to the binary file at binaryFilePath + binaryFileName
	vector<employee> p_writeEmployees(vector<employee>);

	// params: int departmentNumber, int employeeNumber
	// return: found
	int p_findEmployee(int, int);

	// params: int departmentNumber, int employeeNumber
	// return: updated
	bool p_updateEmployeeName(int, int, string);

    // params: int departmentNumber, int employeeNumber
    // return: employee information
    string p_retrieveEmployee(int, int);

};

#endif