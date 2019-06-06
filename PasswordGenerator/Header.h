#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <Windows.h>

using namespace std;

class Password
{
private:
	int length;
	string genPass;
public:
	Password();
	~Password();
	string Generator();
	string SetLogin();
	void GetPass();
};