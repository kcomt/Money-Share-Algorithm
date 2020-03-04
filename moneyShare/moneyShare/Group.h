#pragma once
#include "User.h"
#include "vector"
class group
{
	protected:
		int id;
		string name;
		vector<user*>* users;
	public:
		group(int pid, string pname) {
			id = pid;
			name = pname;
			users = new vector<user*>;
		};

		~group() {
		
		};

		void AddToGroup(user* objuser) {
			users->push_back(objuser);
		};
};