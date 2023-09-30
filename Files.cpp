#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Zero :public exception
{
private:
	string inv_error;

public:
	Zero(string error): inv_error(error)
	{
	}

	const char* getError() { return inv_error.c_str(); }
};

int main()
{
	BOOL cFile;
	string father;
	string son;
	ifstream fin;
	int orez;

	cout << "What file would you copy?\nDirectory: " << endl;
	getline(cin, father); // C:\\Users\\1\\Desktop\\Who.txt

	cout << "Where you would copy file?\nDirectory: " << endl;
	getline(cin, son); // C:\\Users\\1\\Desktop\\I.txt

	wstring stemp1 = wstring(father.begin(), father.end());
	LPCWSTR father1 = stemp1.c_str();

	wstring stemp2 = wstring(son.begin(), son.end());
	LPCWSTR son1 = stemp2.c_str();

	try
	{
		cout << "Try to copy file..." << endl;
		cFile = CopyFile(father1, son1, TRUE);
		if (cFile == FALSE)
		{
			throw exception("~Error~");
		}
		cout << "Copy Success!" << endl;
	}
	catch (const exception & cop)
	{
		cout << cop.what() << endl;
		cout << "Code of issue: " << GetLastError() << endl;
		cout << "Log of issue: " << endl;
		cout << "0 - Other problem." << endl;
		cout << "2 - Non-existent file for copy." << endl;
		cout << "3 - Non-existent directory for copy." << endl;
		cout << "80 - Same files names." << endl;
	}

	cout << "Bonus!!!" << endl;
	cout << "Divide something by..." << endl;
	cin >> orez;

	try
	{
		if (orez == 0)
		{
			throw Zero("-Error-");
		}
		cout << "All right!" << endl;
	}
	catch (Zero & cop)
	{
		cout << "~" << cop.what() << "~" << endl;
		cout << "You divided by zero." << endl;
	}

	system("pause");
	return 0;
}