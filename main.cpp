#include <iostream>
#include <fstream>
#include "binaryFile.h"
#include <string>
#include <string.h>

using namespace std;

const std::string baseFilePath = "./Inputs/";
const std::string binaryFilePath = "./Outputs/";


int main(int argc, char* argv[]) {
	binaryFile* smallBinaryFile = new binaryFile(baseFilePath, "smallOutput.txt", binaryFilePath, "smallOutput.txt");

	if(smallBinaryFile->findEmployee(0,44258)){
		cout<<"Employee found."<<endl;
	}


	// binaryFile* largeBinaryFile = new binaryFile(baseFilePath, "largeOutput.txt", binaryFilePath, "largeOutput.txt");
	// if(largeBinaryFile->findEmployee(0,480154)){
	// 	cout<<"Employee found."<<endl;
	// }
	return 0;
}
