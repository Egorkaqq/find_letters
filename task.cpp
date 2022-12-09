#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string text = "";
	string line;

	fstream file("tets_text.txt");

	if (file.fail()) 
	{
		cerr << "ERROR FILE" << endl;
	}
	else
	{
		while (file.is_open())
		{
			while (!file.eof())
			{
				getline(file, line);
				text += line + '\n';
			}
			file.close();
		}
	}

	ofstream out("replaced_text.txt");

	if (out.fail())
	{
		cerr << "ERROR OUT" << endl;
	}
	else
	{
		for (size_t i = 0; i < text.length(); i++)
		{
			if (text[i] == 'a' && text[i + 1] == 'c')
			{		
				text[i] = 'f';
				text[i + 1] = 'a';
			}
		}
		out << text << endl;
	}

	out.close();
	return 0;
}
