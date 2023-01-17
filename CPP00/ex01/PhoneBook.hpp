#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();

		void	addContact(void);
		void	searchContact(void);

	private:
		void	showPhoneBook(void);
		void	removeContact(void);
		Contact _contacts[8];
		int		_index;
};

#endif