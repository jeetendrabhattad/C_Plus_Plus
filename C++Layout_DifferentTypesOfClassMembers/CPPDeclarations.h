/* C++ Basics
 * Copyright (C) 2013 Jeetendra Bhattad <bhattad.jeetendra@gmail.com>
 *
 * Demo of different types of members that can be declared in class.
 * i) Initialization.
 * ii) Overloaded constructors.
 * iii) Copy Constructor.
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *i
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 */

#ifndef CPPDECLARATIONS_H // header-footer guards, handles multiple re-definition error
#define CPPDECLARATIONS_H

// can be written as struct as well.
// Only difference is in struct default access specifier is public. In class it is private.
class CPPDeclarations
{
	public:
		int iPublic; // accessible directly by object 
		static int iStatic; // is property of a class
	private:
        int iPrivate;
		const int iConst; // must be initalized while defining
		int &iReference; // alias to an existing memory
		// Pointer variable to understand shallow copy v/s deep copy
		int *iPointer; 
		int iSize;
	protected: 
		int iProtected; // accessible only within class & inherited by immediate child class
		mutable int iMutable; // modification allowed in const function
	public:
		// Manager Methods
		CPPDeclarations(); //default constructor
		CPPDeclarations(const int Private, const int Const, const int Protected, const int Mutable, const int Public);
		~CPPDeclarations(); // destructor
		//Copy Constructor
		CPPDeclarations(const CPPDeclarations &existingObject);
		// Accessor / Getter Methods
		
		// constant function, modification of class data members not allowed.
		// this const results into making "this" as a pointer pointing to 
		// constant data
		int GetPrivate() const;
		// const CPPDeclarations * const this = &obj
		
		// obj.GetPrivate()
		// CPPDeclarations * const this = &obj
		// this->iPrivate = 10;
		const int GetConstant() const;
		int GetProtected() const;
		int GetByReference() const;
		int GetMutable() const;

		// Mutator / Setter Methods
		void SetPrivate(const int Private);
		void SetProtected(const int Protected);
		void SetByReference(const int Reference);
		
		// mutable specifies modification allowed in 
		// constant function. Deliberately made this function constant.	
		void SetMutable(const int Mutable) const; 

};
#endif
/*
parent scope-- public     private     protected
inheritance

public         public     private NA. protected

private        private    private NA. private

protected      protected  private NA. protected */

//class Derived : Base
