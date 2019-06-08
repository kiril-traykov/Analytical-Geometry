#include <iostream>
#include <exception>
#include "TriangleException.h"

const char * TriangleException::what() const throw ()
{
	return "Vector Lenght Exception";
}

