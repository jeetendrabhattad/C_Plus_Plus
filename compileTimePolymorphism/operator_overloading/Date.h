#ifndef _DATE_H
#define _DATE_H

class Date
{
	int dd;
	int mm;
	int yy;
	public:
	Date() ;
	Date(int d, int m, int y) ;
	void setDate(const int d);
	void setMonth(const int m);
	void setYear(const int y);
	int getDate() const;
	int getMonth() const;
	int getYear() const;
	Date operator+(const int d);	// Date d1;
		// d1 + 10;
		// d1.operator+(10);
	bool operator==(const Date& obj)const ;
	bool operator<(const Date& obj)const ;
//	Date& operator++();
//	Date operator++(); // operator overloading is dependent on number/types/sequence of parameters. Not on return type. Hence in above scenario it will result into conflict as pre & post have no arguments.

	Date& operator++();
	Date operator++(int);// int is dummy parameter, it is just a place holder.
	Date& operator--();
	bool operator!=(const Date&obj)	const;
	Date operator=(const Date& obj);
};


#endif //_DATE_H
