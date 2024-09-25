#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector <string> SplitString(string S1, string Delim)
{
	vector <string> vString;

	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length()); // erase() until position and move to next word

	}

	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of string.
	}

	return vString;

}


sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string>vClientData;

	vClientData = SplitString(Line, Seperator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); //cast string to double

	return Client;

}

void PrintClientRecord(sClient Client)
{

	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccount Number  : " << Client.AccountNumber;
	cout << "\nPin Code        : " << Client.PinCode;
	cout << "\nName            : " << Client.Name;
	cout << "\nPhone           : " << Client.Phone;
	cout << "\nAccount Balance : " << Client.AccountBalance;

}

int main()
{
	string stLine = "A150#//#1234#//#Omar Al-Hmaidi#//#0799989#//#5270.000000";

	cout << "Line Record is: \n";
	cout << stLine << endl;

	sClient Client = ConvertLineToRecord(stLine);

	PrintClientRecord(Client);


	system("pause>0");
}
