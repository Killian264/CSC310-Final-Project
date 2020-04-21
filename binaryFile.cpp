#include "binaryFile.h"
#include "customErrorClass.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <string.h>

/****************************** PUBLIC: constructor ******************************/
binaryFile::binaryFile(string baseFilePath, string baseFileName, string binaryFilePath, string binaryFileName){
    // set stuff
    this->baseFilePath = baseFilePath;
    this->baseFileName = baseFileName;

    this->binaryFilePath = binaryFilePath;
    this->binaryFileName = binaryFileName;

    // fill binary file based on information given
    p_fillBinaryFile();
}

binaryFile::~binaryFile(string baseFilePath, string baseFileName, string binaryFilePath, string binaryFileName){
    
}

// params: int departmentNumber, int employeeNumber
// return: found
/****************************** PUBLIC: findEmployee ******************************/
bool binaryFile::findEmployee(int, int){
    return true;
}

// params: int departmentNumber, int employeeNumber
// return: updated
/****************************** PUBLIC: updateEmployeeName ******************************/
bool binaryFile::updateEmployeeName(int, int, string){
    return true;
}

/****************************** PRIVATE: fillBinaryFile ******************************/
void binaryFile::p_fillBinaryFile() {
    // this is not complete 
	ifstream inputFile;
	string inputString;
	inputFile.open(this->baseFilePath + this->baseFileName, ios::in);


	fstream outputFile;
	employee* currentEmployee = new employee;
	outputFile.open(this->binaryFilePath + this->binaryFileName, ios::binary | ios::out | ios::in);

	inputFile >> inputString;

	while (inputString != "") {
		currentEmployee->departmentNumber = (int)inputString[0];
		currentEmployee->employeeNumber= (int)inputString[2];

		string strName = inputString.substr(4);
		// do str length check or something here


		strcpy(currentEmployee->name, strName.c_str());
		// char* & is some kind of hidden magic probably
		outputFile.write((char*)&currentEmployee, sizeof(employee));

		inputFile >> inputString;
	}

	inputFile.close();

	// free allocated data
	delete(currentEmployee);
}


/****************************** PRIVATE: sortBinaryFilee ******************************/
void binaryFile::p_sortBinaryFile(){
    return;
}

// params: int departmentNumber, int employeeNumber
// return: found
/****************************** PRIVATE: findEmployee ******************************/
bool binaryFile::p_findEmployee(int, int){
    return true;
}

// params: int departmentNumber, int employeeNumber
// return: updated
/****************************** PRIVATE: updateEmployeeName ******************************/
bool binaryFile::p_updateEmployeeName(int, int, string){
    return true;
}