#include "binaryFile.h"
#include "customErrorClass.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

/****************************** PUBLIC: constructor ******************************/
binaryFile::binaryFile(string baseFilePath, string baseFileName, string binaryFilePath, string binaryFileName){
    // set stuff
    this->baseFilePath = baseFilePath+baseFileName;

    this->binaryFilePath = binaryFilePath+binaryFileName;

    // fill binary file based on information given

	// read in employees
    vector<employee> employees = this->p_loadEmployees();
	// sort them
	employees = this->p_sortEmployees(employees);
	// write them to binary file
	this->p_writeEmployees(employees);
	
}

binaryFile::~binaryFile(){
    
}

// params: int departmentNumber, int employeeNumber
// return: found
/****************************** PUBLIC: findEmployee ******************************/
bool binaryFile::findEmployee(int departmentNumber, int employeeNumber){
    int searchResult = this->p_findEmployee(departmentNumber,employeeNumber);
	return searchResult > 0 ? true : false;
	// if( searchResult > 0 ){
	// 	//cout<<"offset: "<<searchResult<<endl;
	// 	return true;
	// } 
	return false;
}

// params: int departmentNumber, int employeeNumber
// return: updated
/****************************** PUBLIC: updateEmployeeName ******************************/
bool binaryFile::updateEmployeeName(int departmentNumber, int employeeNumber, string newName){
	if(newName.length() > sizeof(employee::name)){
		// do error stuff
	}
    return this->p_updateEmployeeName(departmentNumber,employeeNumber, newName);
}

/****************************** PUBLIC: retrieveEmployee ******************************/
string binaryFile::retrieveEmployee(int departmentNumber, int employeeNumber)
{
    string employeeInfo = this -> p_retrieveEmployee(departmentNumber, employeeNumber);

    if(employeeInfo == "-1")
    {
        // Will add in error handling; this is a placeholder probably
        return "-1";
    }
    else
    {
        return employeeInfo;
    }
}

/****************************** PRIVATE: fillBinaryFile ******************************/
vector<employee> binaryFile::p_loadEmployees() {
	char seperator = ',';

	vector<employee> employees;
    // this is not complete 

	// open input file
	ifstream inputFile;
	string inputString;
	employee currentEmployee;
	inputFile.open(this->baseFilePath, ios::in);

	// read first line
	inputFile >> inputString;


	while (!inputFile.eof()) {
		// vars
		int departmentNumber;
		int employeeNumber;
		string name;

		// read in data as int
		std::istringstream(inputString.substr(0, inputString.find(seperator))) >> departmentNumber;
		inputString = inputString.substr(inputString.find(seperator) + 1, inputString.length());

		std::istringstream(inputString.substr(0, inputString.find(seperator))) >> employeeNumber;
		inputString = inputString.substr(inputString.find(seperator) + 1, inputString.length());

		// rest of the string
		name = inputString;

		// string length check on name should be done here


		// clear current employee name char[30]
		memset(currentEmployee.name, 0, sizeof(currentEmployee.name));
		// copy over data to currentEmployee
		currentEmployee.departmentNumber = departmentNumber;
		currentEmployee.employeeNumber = employeeNumber;

		// should be replaced with strcpy_s <- I believe strcpy is unsafe
		strcpy(currentEmployee.name, name.c_str());

		// push to employees
		employees.push_back(currentEmployee);

		inputFile >> inputString;
	}

	inputFile.close();

	return employees;
}

/****************************** PRIVATE: p_sortEmployees ******************************/
vector<employee> binaryFile::p_sortEmployees(vector<employee> employees){
	std::sort( employees.begin(), employees.end(), p_sortHelper);
	
	return employees;
}

/****************************** PRIVATE: p_sortHelper ******************************/
//sortHelper allows us to sort by 2 fields (ie Department and then Employee Number)
//params: employee e1, employee e2
//return: e1 > e2 ? true : false
bool binaryFile::p_sortHelper(const employee &e1, const employee &e2){
	return 	e1.departmentNumber < e2.departmentNumber || 
			e1.departmentNumber == e2.departmentNumber && e1.employeeNumber < e2.employeeNumber;
}

/****************************** PRIVATE: p_writeEmployees ******************************/
vector<employee> binaryFile::p_writeEmployees(vector<employee> employees){
	// open output file
	fstream outputFile;
	// trunc kills the file before write
	outputFile.open(this->binaryFilePath, ios::binary | ios::out | ios::in | ios::trunc);
	int indexLocation = 0, checkSize = 0;

	for(employee iterEmployee : employees){
		//generate the binary index based upon department
		if( checkSize <= iterEmployee.departmentNumber ){
			departmentLoc[indexLocation] = outputFile.tellp();
			indexLocation++;
			checkSize++;			
		}
		// outputFile.write((char*)&iterEmployee.departmentNumber, sizeof(int));
		// outputFile.write((char*)&iterEmployee.employeeNumber, sizeof(int));
		// outputFile.write(iterEmployee.name, sizeof(char)*30);

		outputFile.write((char*)&iterEmployee, sizeof(employee));
		
	}
	outputFile.close();
}


// params: int departmentNumber, int employeeNumber
// return: found
/****************************** PRIVATE: findEmployee ******************************/
int binaryFile::p_findEmployee(int departmentNumber, int employeeNumber){
	fstream searchFile;
	searchFile.open(this->binaryFilePath, ios::in | ios::binary);
	int temp;
	//start at location of specified department in file and end before start of next dept. 
	int startLoc = departmentLoc[departmentNumber];
	int endLoc;
	searchFile.seekg(0, ios::end);
	int length = searchFile.tellg();

	// this should be replaced with a departmentNumber < this.numberOfDepartments or something like that
	departmentNumber < 4 ? endLoc = departmentLoc[departmentNumber + 1] : endLoc = length;
	
	//determine size of segment to search
	int searchSegmentSize = endLoc - startLoc;
	//set stream position back to beginning of inputted department data
	searchFile.seekg(startLoc, ios::beg);

	while(searchSegmentSize > 0){
		searchFile.seekg(sizeof(int), ios::cur);
		searchFile.read((char*)&temp, sizeof(int));
		if(temp == employeeNumber){
			searchFile.seekg(-(sizeof(int) * 2), ios::cur);
			return searchFile.tellg();
		}
		searchFile.seekg(sizeof(employee) - sizeof(int) * 2, ios::cur);
		searchSegmentSize -= sizeof(employee);
	}

    return -1;
}

// params: int departmentNumber, int employeeNumber
// return: updated
/****************************** PRIVATE: updateEmployeeName ******************************/
bool binaryFile::p_updateEmployeeName(int departmentNumber, int employeeNumber, string newName){
    fstream file;
	employee currentEmployee;

	int offset = this -> p_findEmployee(departmentNumber, employeeNumber);

    // Employee doesn't exist
    if(offset == -1)
    {
        return false;
    }
    // Employee exists
    else
    {
        file.open(this -> binaryFilePath, ios::out | ios::binary);   // Open file
        file.seekg(offset);                // Move to beginning of entry

		memset(currentEmployee.name, 0, sizeof(currentEmployee.name));
		// In this instace changing to strcpy_s is probably unnecessary but should be done anyways
		strcpy(currentEmployee.name, newName.c_str());
		currentEmployee.departmentNumber = departmentNumber;
		currentEmployee.employeeNumber = employeeNumber;

		file.write((char*)&currentEmployee, sizeof(employee));
    }

	file.close();  

	return true;
}

// params: int departmentNumber, int employeeNumber
// return: employee information
/****************************** PRIVATE: p_retrieveEmployee ******************************/
string binaryFile::p_retrieveEmployee(int departmentNumber, int employeeNumber)
{
    fstream file;
    string employeeInfoStr = "";
    string employeeNameStr = "";
    int size = 30;
    char * employeeNameArr = new char[size];
    employee currentEmployee;

    int offset = this -> p_findEmployee(departmentNumber, employeeNumber);

    // Employee doesn't exist
    if(offset == -1)
    {
        return "-1";
    }
    // Employee exists
    else
    {
        file.open(this -> binaryFilePath, ios::in | ios::binary);   // Open file

        // file.seekg(0, ios::beg);                     // Start at beginning of file
        // file.seekg(offset, ios::beg);                // Move to beginning of entry
		file.seekg(offset);

        file.read((char*)&currentEmployee, sizeof(employee));   // Read employee into currentEmployee
        file.close();                                           // Close file
    }

    employeeNameStr = currentEmployee.name;           // Assign currentEmployee's name to employeeNameStr

    employeeInfoStr += to_string(departmentNumber);   // Append departmentNumber to employeeInfoStr
    employeeInfoStr += ", ";
    employeeInfoStr += to_string(employeeNumber);     // Append employeeNumber to employeeInfoStr
    employeeInfoStr += ", ";

    employeeInfoStr += employeeNameStr;   // Append employeeNameStr to employeeInfoStr - along with null byte

    // Return employeeInfoStr
    return employeeInfoStr;
}