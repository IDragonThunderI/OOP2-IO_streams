#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void fileCopy(ifstream& input, const string& outname)
{
	ofstream output;
	output.open(outname);

	if (!output.is_open())
	{
		cout << "Error: Ошибка при создании или открытии output файла!" << endl;
		exit(3);
	}
	
	string str;
	while (getline(input, str))
	{
		for (size_t i = 0; i < str.length(); i++)
			if (str.at(i) == ',') str.replace(i, 1, "");

		output << str << endl;
	}

	output.close();
}

int main(int argc, char* argv[])
{
	system("chcp 1251 > nul");

	string filename;

	if (argc > 1) filename = argv[1];
	else
	{
		cout << "Укажите файл для копирования: ";
		getline(cin, filename);
	}

	ifstream input;
	input.open(filename);

	if (!input.is_open())
	{
		cout << "Error: Ошибка при открытии input файла!" << endl;
		exit(2);
	}

	filename.erase(0, filename.find_last_of("/\\") + 1);
	string outname;
	if (argc > 2)
	{
		outname = argv[2];
		if (outname.size() - 1 == outname.find_last_of("/\\"))
			outname += "copy - " + filename;
	}
	else outname = "copy - " + filename;

	fileCopy(input, outname);

	input.close();
	cout << "Файл успешно скопирован!\n";

	return 0;
}