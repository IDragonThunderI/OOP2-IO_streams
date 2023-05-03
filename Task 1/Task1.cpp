#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

string toBinary(int value)
{
	string bin;
	do {
		bin += char('0' + value % 2);
	} while (value >>= 1);
	return string(bin.crbegin(), bin.crend());
}

int main()
{
	system("chcp 1251 > nul");
	cout << "/* ЗАДАЧА №1 */\n\n";

	int x;
	vector<int> fibonacci(2, 1);
	bool correctInput = false;
	cout << "Введите количество элементов ряда Фибоначчи: ";

	while (!correctInput)
	{
		try
		{
			if (!(cin >> x))
				throw invalid_argument("Недопустимое значение параметра. Ожидалось значение типа unsigned int!");

			if (x < 3)
				throw invalid_argument("Количество элементов должно быть больше двух!");

			correctInput = true;
		}
		catch (const invalid_argument& error)
		{
			cerr << "Error: " << error.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	for (size_t i = 2; i < x; i++)
		fibonacci.push_back(fibonacci.at(i - 1) + fibonacci.at(i - 2));

	for (size_t i = 0; i < fibonacci.size(); i++)
	{
		cout << setw(2) << left << i + 1 << " - dec: " << setw(5) << fibonacci.at(i);
		cout << hex << "   |   hex: " << setw(5) << left << fibonacci.at(i); 
		cout << oct << "   |   oct: " << setw(5) << left << fibonacci.at(i);
		cout <<	"   |   bin: " << setw(5) << left << toBinary(fibonacci.at(i)) << endl;
	}

	return 0;
}