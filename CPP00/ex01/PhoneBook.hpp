#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();

		void	addContact(void);

	private:
		Contact contacts[8];
		int		index;
};

#endif