#pragma once
#include "Group.h"
class debt {
	private:
		int lender;
		int reciever;
		double amount;
	public:
		debt(int plender, int preciever, double pamount) {
		};
		
		~debt() {

		};
};

class debts {
	private:
		vector<debt*>* vecDebts;
		group * objgroup;
	public:
		debts(group* pobjgroup) {
			objgroup = pobjgroup;
			vecDebts = new vector<debt*>;
		};

		~debts() {

		};

		void lend(int lender, int reciever, double amount)
		{
			debt* tempDebt = new debt(lender, reciever, amount);
			vecDebts->push_back(tempDebt);
			delete tempDebt;
		}


};