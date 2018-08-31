#ifndef CONTACT_DETAILS_H
#define CONTACT_DETAILS_H
#include <string>

class ContactDetails{
	std::string address;
	std::string email_id;
	std::string phone_no;
	private:
	ContactDetails(std::string, std::string, std::string);
	void UpdateEmailID(const std::string email_id);
	void UpdateAddress(const std::string address);
	void UpdatePhone(const std::string phone_no);
	std::string GetEmailID() const;
	std::string GetAddress() const;
	std::string GetPhone() const;
};
#endif
