/**
	Gaurav Parida
	Cloud Assignment 1
	Binary Translation of 32bit asm code to 64-bit asm code
**/
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	cout<<"BEGIN"<<endl;
	cout<<"----------------------------------"<<endl;
	cout<<"The 32-bit file is : "<<argv[1]<<endl;
	cout<<"The 64-bit file after translation is : "<<argv[2]<<endl;
  ifstream file(argv[1]);
	ofstream file2;
	file2.open(argv[2]);
	size_t found;
	string str;
	while (getline(file, str)) //read file line by line
	{
		found=str.find("eax, 4");
		if(found!=string::npos)
			str.replace(found,6,"rax, 1");

		found=str.find("eax, 1");
		if(found!=string::npos)
			str.replace(found,6,"rax, 60");

		found=str.find("eax");
		if(found!=string::npos)
			str.replace(found,3,"rax");

		found=str.find("ebx");
		if(found!=string::npos)
			str.replace(found,3,"rdi");

		found=str.find("ecx");
		if(found!=string::npos)
			str.replace(found,3,"rsi");

		found=str.find("edx");
		if(found!=string::npos)
			str.replace(found,3,"rdx");

		found=str.find("int 80h");
		if(found!=string::npos)
			str.replace(found,7,"syscall");

		file2<<str<<endl;
	}
	file2.close();
	cout<<"----------------------------------"<<endl;
	cout<<"DONE"<<endl;
	return 0;
}
