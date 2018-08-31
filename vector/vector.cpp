#include "vector.h"
#include "stdlib.h"

Vector::Vector(int size): max_size(size), actual_size(0){
	array = new int[max_size];
}
Vector::~Vector(){
	delete[] array;
}
Vector::Vector(const Vector& obj) :
	   	max_size(obj.max_size),
	   	actual_size(obj.actual_size)
{
	array = new int[max_size];
	for( int i = 0  ; i < actual_size ; i++ )
			array[i] = obj.array[i];
}

void Vector::Display()
{
	for( int i = 0  ; i < actual_size ; i++ )
			std::cout<<array[i]<<":";
	std::cout<<std::endl;
}
int Vector::GetValue(int index){
	if (index < actual_size)
			return array[index];
	return -1;
}

int Vector::SetValue(int value){
	if(actual_size == max_size)
	{
		max_size *= 2;
		array = (int*)realloc(array, max_size*sizeof(int));
	}
	int i ;
	for( i = 0 ; i < actual_size ; i++ )
	{
		if(value > array[i])
				continue;
		break;
	}
	if( i == actual_size )
	{
		array[i] = value;
		actual_size++;
	}
	else
	{
		for(int j = actual_size-1 ; j >= i ; j--)
				array[j+1] = array[j];
		array[i] = value;
		actual_size++;
	}
}

bool Vector::IsPresent(int value)
{
	int i = 0;
	while(i < actual_size)
	{
		if( value == array[i] )
				return true;
		i++;
	}
	return false;
}

Vector Union(Vector &v1, Vector &v2)
{
	Vector result(v1);
	int iV2 = 0;

	for( iV2 = 0 ; iV2 < v2.actual_size ; iV2++ )
	{
		std::cout<<"checking:"<<v2.array[iV2]<<std::endl;
		if( !result.IsPresent(v2.array[iV2]) )
			result.SetValue(v2.array[iV2]);
	}
	return result;
}

Vector Intersect(Vector &v1, Vector &v2)
{
	Vector result;
	int iV1 = 0, iV2 = 0, iVR = 0;
	while( iV2 < v2.actual_size )
	{
		if( v1.IsPresent(v2.array[iV2]) )
				result.SetValue(v2.array[iV2]);
		iV2++;
	}
	return result;
}
