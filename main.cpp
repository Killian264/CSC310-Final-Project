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

	if(smallBinaryFile->findEmployee(0,45731)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	if(smallBinaryFile->findEmployee(1,37503)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	if(smallBinaryFile->findEmployee(2,58509)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	if(smallBinaryFile->findEmployee(3,58510)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	if(smallBinaryFile->findEmployee(4,44258)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	if(smallBinaryFile->findEmployee(0,18738)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	if(smallBinaryFile->findEmployee(1,63006)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	if(smallBinaryFile->findEmployee(2,757)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
	
	if(smallBinaryFile->findEmployee(3,68263)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	if(smallBinaryFile->findEmployee(4,65898)){
		cout<<"Employee found."<<endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}

	// binaryFile* largeBinaryFile = new binaryFile(baseFilePath, "largeOutput.txt", binaryFilePath, "largeOutput.txt");
	// if(largeBinaryFile->findEmployee(0,499995)){
	// 	cout<<"Employee found."<<endl;
	// }
	return 0;
}
