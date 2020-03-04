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

		int getLender()
		{
			return lender;
		}

		int getReciever()
		{
			return reciever;
		}

		double getAmount()
		{
			return amount;
		}
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

		void calculateNetOfUser(user* objUser){
			int id = objUser->get_id();

			double debt = 0;
			double owed = 0;
			double net = 0;
			//Calculate net debt
			
			for (int i = 0; i < vecDebts->size(); i++)
			{
				if (vecDebts->at(i)->getReciever() == id)
				{
					debt = debt + vecDebts->at(i)->getAmount();
				}
			}

			//Calculate net owed

			for (int i = 0; i < vecDebts->size(); i++)
			{
				if (vecDebts->at(i)->getLender() == id)
				{
					debt = debt + vecDebts->at(i)->getAmount();
				}
			}

			net = owed - debt;
		};
};