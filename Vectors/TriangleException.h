#pragma once
#include <exception>

class TriangleException : public std::exception {

	const char * what() const throw();

};
