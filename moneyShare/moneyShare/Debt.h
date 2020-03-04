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

		void calculateNetOfUser(user* objUser) {
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

			objUser->set_totalDebt(debt);

			//Calculate net owed

			for (int i = 0; i < vecDebts->size(); i++)
			{
				if (vecDebts->at(i)->getLender() == id)
				{
					owed = owed + vecDebts->at(i)->getAmount();
				}
			}

			objUser->set_totalOwed(owed);

			net = owed - debt;

			objUser->set_net(net);
		};

		void settleDebts()
		{
			if (vecDebts->size() > 0)
			{
				vector<int>* idDebters = new vector<int>;
				vector<int>* idOwed = new vector<int>;

					for (int i = 0; i < objgroup->get_sizeOfGroup(); i++)
					{
						calculateNetOfUser(objgroup->get_users()->at(i));
					}
			

				//Make FIFO list of debters

				for (int i = 0; i < objgroup->get_sizeOfGroup(); i++)
				{
					if (objgroup->get_users()->at(i)->get_net() < 0)
					{
						idDebters->push_back(objgroup->get_users()->at(i)->get_id());
					}
				}

				//Make FIFO list of people owed

			};
		};
};