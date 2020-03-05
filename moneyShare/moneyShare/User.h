#pragma once
#include <string>
#include <time.h>
#include "iostream"
using namespace std;

class user {
	protected:
		int id;
		string name;
		double totalOwed;
		double totalDebt;
		double net;
	public:
		user(int pid, string pname) {
			id = pid;
			name = pname;
		};

		~user() {};

		int get_id()
		{
			return id;
		};
		double get_totalOwed() {
			return totalOwed;
		};

		void set_totalOwed(double amount)
		{
			totalOwed = amount;
		};

		double get_totalDebt()
		{
			return totalDebt;
		};

		void set_totalDebt(double amount)
		{
			totalDebt = amount;
		};

		double get_net()
		{
			return net;
		}

		void set_net(double amount)
		{
			net = amount;
		};
};