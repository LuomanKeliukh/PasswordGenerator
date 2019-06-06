#include "Header.h"

Password::Password()
{
	this->length = 12;
}

Password::~Password()
{
}

string Password::Generator()
{	
	srand(time(NULL));
	char symbol;
	for (int i = 0; i <= length + rand() % 5; i++) {
		symbol = rand() % 74 + 48;
			genPass += symbol;
	}
	return genPass;
}

string Password::SetLogin()
{
	string login;
	cout << "Enter your login or site" << endl;
	cin >> login;
	return login;
}

void Password::GetPass()
{	
	ofstream ofs;
	ofs.open("Passwords.txt", ofstream::out | ofstream::app);
	ofs << endl << SetLogin() << " " << Generator();
	ofs.close();
	//cout << genPass;
	OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg = GlobalAlloc(GMEM_MOVEABLE, genPass.size());
	if (!hg) {
		CloseClipboard();
		return;
	}
	memcpy(GlobalLock(hg), genPass.c_str(), genPass.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT, hg);
	CloseClipboard();
	GlobalFree(hg);
}
