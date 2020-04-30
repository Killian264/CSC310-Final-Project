#include <iostream>
#include <fstream>
#include "binaryFile.h"
#include <string>
#include <string.h>

using namespace std;

const std::string baseFilePath = "./Inputs/";
const std::string binaryFilePath = "./Outputs/";

void smallOutputTest(binaryFile*);
void mediumOutputTest(binaryFile*);
void largeOutputTest(binaryFile*);

int main(int argc, char* argv[]) {
	// //small output
	// binaryFile* smallBinaryFile = new binaryFile(baseFilePath, "smallOutput.txt", binaryFilePath, "smallOutput.txt");
	// smallOutputTest(smallBinaryFile);
	// delete smallBinaryFile;

	// // medium output
	// binaryFile* mediumBinaryFile = new binaryFile(baseFilePath, "mediumOutput.txt", binaryFilePath, "mediumOutput.txt");
	// mediumOutputTest(mediumBinaryFile);
	// delete mediumBinaryFile;

	// // large output
	binaryFile* largeBinaryFile = new binaryFile(baseFilePath, "largeOutput.txt", binaryFilePath, "largeOutput.txt");
	largeOutputTest(largeBinaryFile);
	delete largeBinaryFile;
	return 0;
}


void smallOutputTest(binaryFile* binaryFile){
	if(binaryFile->findEmployee(0,45731)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(0,45731) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(1,37503)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(1,37503) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(2,58509)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(2,58509) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(3,58510)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(3,58510) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(4,44258)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(4,44258) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}


	// These should not be found inside the binaryFile


	if(binaryFile->findEmployee(0,18738)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(0,18738) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(1,63006)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(1,63006) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(2,757)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(2,757) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(3,68263)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(3,68263) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(4,65898)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(4,65898) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
}

void mediumOutputTest(binaryFile* binaryFile){
	if(binaryFile->findEmployee(0,243013)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(0,243013) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(1,135016)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(1,135016) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(2,15013)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(2,15013) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(3,105013)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(3,105013) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(4,297008)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(4,297008) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}


	// These should not be found inside the binaryFile


	if(binaryFile->findEmployee(0,139708)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(0,139708) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(1,250506)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(1,250506) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(2,206998)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(2,206998) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(3,6011)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(3,6011) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(4,243119)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(4,243119) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
}

void largeOutputTest(binaryFile* binaryFile){
	if(binaryFile->findEmployee(0,205009)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(0,205009) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(1,25013)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(1,25013) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(2,189715)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(2,189715) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(3,155012)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(3,155012) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(4,430017)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(4,430017) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}


	// These should not be found inside the binaryFile


	if(binaryFile->findEmployee(0,205508)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(0,205508) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(1,335014)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(1,335014) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(2,430013)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(2,430013) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(3,5014)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(3,5014) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
		if(binaryFile->findEmployee(4,433415)){
		cout<<"Employee found."<<endl;
		cout << binaryFile -> retrieveEmployee(4,433415) << endl;
	} else{
		cout<<"Employee NOT found."<<endl;
	}
}
