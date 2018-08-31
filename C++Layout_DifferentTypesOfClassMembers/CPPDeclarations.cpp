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
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 */

#include "CPPDeclarations.h"
#include "stdio.h"
#include <iostream>
#include <string.h>

// static variables must be defined once, outside the class.
int CPPDeclarations::iStatic = 10;

// Manager Methods
CPPDeclarations::CPPDeclarations()
			:
			 iReference(iProtected), // reference must be intialized
			  iPrivate(0),
			  iProtected(10),
			  iConst(10), // must be initialzied
			  iMutable(0),
			  iPublic(0)     // True Initialization
{
	//iReference = iProtected;
	//iConst = 20; // This gives an error as it is an assignment not an intialization
	iSize = 10;
	iPointer = new int[iSize];	
	memset(iPointer, 55, 10*sizeof(int));
	std::cout<<"Default Constructor "<<__LINE__<<":"<<__FUNCTION__<<std::endl;
}

CPPDeclarations::CPPDeclarations(const int Private, const int Const, const int Protected, const int Mutable, const int Public)
			: iReference(iProtected),
			  iConst(Const),
			  iPrivate(Private),
			  iProtected(Protected),
			  iMutable(Mutable),
			  iPublic(Public)
{
	std::cout<<"Overloaded Constructor "<<__LINE__<<":"<<__FUNCTION__<<std::endl;
	iSize = 10;
	iPointer = new int[iSize];	
	memset(iPointer, 65, 10*sizeof(int));
}
CPPDeclarations::CPPDeclarations(const CPPDeclarations &existingObject)
			: iReference(iProtected),
			  iConst(existingObject.iConst)
{
	std::cout<<"Copy Constructor "<<__LINE__<<":"<<__FUNCTION__<<std::endl;
	this->iPublic = existingObject.iPublic;
	this->iPrivate = existingObject.iPrivate;
	this->iProtected = existingObject.iProtected;
	this->iMutable = existingObject.iMutable;
	this->iSize = existingObject.iSize;
#if SHALLOW
	this->iPointer = existingObject.iPointer;
	//if we do this->iPointer = existingObject.iPointer then it is shallow copy.
	//  This behavior is same as default copy constructor (provided by compiler)
#else
	this->iPointer = new int[this->iSize];// this results into performing DEEP copy
	bcopy(this->iPointer, existingObject.iPointer, this->iSize*sizeof(int));
#endif
}
CPPDeclarations::~CPPDeclarations(){
	std::cout<<"Destructor "<<__LINE__<<":"<<__FUNCTION__<<std::endl;
	std::cout<<"Address of iPointer is "<<iPointer<<std::endl;
	delete[] iPointer;
}
		
// Accessor / Getter Methods	
// constant function, modification of class data members not allowed.
// this const results into making "this" as a pointer pointing to 
// constant data
int CPPDeclarations::GetPrivate() const{
	return iPrivate;
}
 
const int CPPDeclarations::GetConstant() const{
	return iConst;
}

int CPPDeclarations::GetProtected() const{
	return iProtected;
}

int CPPDeclarations::GetByReference() const{
	return iReference;
}

int CPPDeclarations::GetMutable() const{
	//CPPDeclarations const * const this = &calling_object
	return this->iMutable;
}

// Mutator / Setter Methods
void CPPDeclarations::SetPrivate(const int Private){
	this->iPrivate = Private;// this is a const pointer.
   //i.e CPPDeclarations * const this = &calling_object (address of calling object)
	/*CPPDeclarations Object;
	this = &Object;*/ // Not allowed as this is a constant pointer
}

void CPPDeclarations::SetProtected(const int Protected){
	this->iProtected = Protected;
}

void CPPDeclarations::SetByReference(const int Reference){
	this->iReference = Reference;
}
		
// mutable specifies modification allowed in 
// constant function. Deliberately made this function constant.	
void CPPDeclarations::SetMutable(const int Mutable) const{
	this->iMutable = Mutable;
	int i = 20;
	//this->iPrivate = 100; // members other than mutable cannot be modified inside constant function
}
