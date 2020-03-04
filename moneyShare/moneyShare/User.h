#pragma once
#include "iostream"
using namespace std;
class user {
	protected:
		int id;
		string name;
		double totalDebt;
	public:
		user(int pid, string pname, double ptotalDebt) {
			id = pid;
			name = pname;
			totalDebt = ptotalDebt;
		};

		~user() {};

};