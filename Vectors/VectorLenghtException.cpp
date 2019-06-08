#include <iostream>
#include <exception>
#include "VectorLenghtException.h"

	const char * VectorLenghtException::what() const throw ()
	{
		return "Vector Lenght Exception";
	}

