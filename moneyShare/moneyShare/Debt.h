#pragma once
#include "Group.h"

class debt {
	private:
		int lender;
		int reciever;
		double amount;
	public:
		debt(int plender, int preciever, double pamount) {
			lender = plender;
			reciever = preciever;
			amount = pamount;
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
			srand((unsigned)time(NULL));
			objgroup = pobjgroup;
			vecDebts = new vector<debt*>;
		};

		~debts() {

		};

		void lend(int lender, int reciever, double amount)
		{
			debt* tempDebt = new debt(lender, reciever, amount);
			vecDebts->push_back(tempDebt);
			//delete tempDebt;
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
			cout << net << endl;
		};

		void settleDebts()
		{
			showDebts();

			if (vecDebts->size() > 0)
			{
				vector<user*>* debters = new vector<user*>;
				vector<user*>* owed = new vector<user*>;

				for (int i = 0; i < objgroup->get_sizeOfGroup(); i++)
				{
						calculateNetOfUser(objgroup->get_users()->at(i));
				}
			

				//Make FIFO list of debters and order it

				for (int i = 0; i < objgroup->get_sizeOfGroup(); i++)
				{
					if (objgroup->get_users()->at(i)->get_net() < 0)
					{
						debters->push_back(objgroup->get_users()->at(i));
					}
				}

				debters = bubbleSortMin(debters);

				//Make FIFO list of people owed

				for (int i = 0; i < objgroup->get_sizeOfGroup(); i++)
				{
					if (objgroup->get_users()->at(i)->get_net() > 0)
					{
						owed->push_back(objgroup->get_users()->at(i));
					}
				}

				owed = bubbleSortMax(owed);

			};
		};

		vector<user*>* bubbleSortMax(vector<user*>* users)
		{
			bool swapped = true;

			while (swapped == true)
			{
				swapped = false;
				for (int i = 0; i < users->size() - 1; i++)
				{
					if (users->at(i + 1)->get_net() > users->at(i)->get_net())
					{
						user* aux = users->at(i + 1);
						users->at(i + 1) = users->at(i);
						users->at(i) = aux;
						swapped = true;
					}
				}
			}

			for (int i = 0; i < users->size(); i++)
			{
				cout << "id: " << users->at(i)->get_id() << " net: " << users->at(i)->get_net() <<endl;
			}
			return users;
		};


		vector<user*>* bubbleSortMin(vector<user*>* users)
		{
			bool swapped = false;

			while (swapped == true)
			{
				swapped = false;
				for (int i = 0; i < users->size() - 1; i++)
				{
					if (users->at(i + 1)->get_net() < users->at(i)->get_net())
					{
						user* aux = users->at(i + 1);
						users->at(i + 1) = users->at(i);
						users->at(i) = aux;
						swapped = true;
					}
				}
			}

			for (int i = 0; i < users->size(); i++)
			{
				cout << "id: " << users->at(i)->get_id() << " net: " << users->at(i)->get_net() << endl;
			}
			return users;
		};

		void showDebts()
		{
			for (int i = 0; i < vecDebts->size(); i++)
			{
				cout << vecDebts->at(i)->getLender() << " " << vecDebts->at(i)->getReciever() << " " << vecDebts->at(i)->getAmount() <<endl;
			}
		}
};