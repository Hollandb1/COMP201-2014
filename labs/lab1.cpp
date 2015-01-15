#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	ifstream input_file;
	ofstream output_file;
	int var;
	int sum = 0;
	
	input_file.open(argv[1]);
	output_file.open("output.txt");
	
	if (input_file.fail())
	{
		cout << "input file failed to open";

		return 1;

	}
	if (output_file.fail())
	{
		cout << "output file failed to open";

		return 1;

	}

	output_file << "x \t" << "x^2 \t" << "Current sum" << endl;
	output_file << "= \t" << "=== \t" << "======= === " << endl;

	while (input_file >> var)
	{
		sum = sum + var;
		output_file << var << "\t" << var*var << "\t" << sum << endl;
	}
	input_file.close();
	output_file.close();
	
	return 0;
}