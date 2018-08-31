#ifndef ATM_DETAILS_H
#define ATM_DETAILS_H

typedef enum
{
	VISA,
	MASTER,
	MAESTRO
}CARD_TYPE_T;
class ATMDetails{
	double card_number;
	CARD_TYPE_T card_type;
	int pin;
	int cvv;

};
#endif
