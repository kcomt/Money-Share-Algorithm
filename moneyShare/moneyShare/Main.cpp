#include "Debt.h"

int main()
{
	int x;
	user* mauri = new user(0, "mauri");
	user* kcomt = new user(1, "kcomt");
	user* dani = new user(2, "dani");

	group* objgroup = new group(0, "lima");

	objgroup->AddToGroup(mauri);
	objgroup->AddToGroup(kcomt);
	objgroup->AddToGroup(dani);

	debts* limadebts = new debts(objgroup);

	limadebts->lend(0, 1, 10);
	limadebts->lend(0, 2, 20);
	limadebts->lend(1, 0, 5);

	limadebts->settleDebts();

	cin >> x;
	return x;
};