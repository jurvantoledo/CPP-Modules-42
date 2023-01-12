#ifndef CONTACT_H

#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
	public:
		void	setContact(void);
		void	printContact(void);
		void	displayContact(void);

	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif