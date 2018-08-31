#ifndef _DATE_H
#define _DATE_H

class SpecialDate
{
	int dd;
	int mm;
	public:
	SpecialDate(int dd, int mm);	
};
class Date
{
	int dd, mm, yy;
	public:
	Date();
	// if explicit not specified then constructor performs implicit conversion from primitive type to class type. e.g Date dt(10); dt = 20; Such constructor is known as conversion constructor. To make sure that constructor should be invoked explicitly only on object creation programmer must specify explciti keyword at constructor declaration.
	Date(int dd);
	Date(int dd, int mm, int yy);
	void SetDD(const int dd);
	void SetMM(const int mm);
	void SetYY(const int yy);
	int GetDD() const;
	int GetMM() const;
	int GetYY() const;
	//Date operator=(int d);
	operator int(); // conversion function which converts class to integer type
	operator SpecialDate();
};

#endif
