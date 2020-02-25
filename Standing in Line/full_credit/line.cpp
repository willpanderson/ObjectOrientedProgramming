#include "line.h"
#include <string>
#include <cmath>


Line::Line(double x1,double y1, double x2, double y2) : _x1(x1),_y1(y1),_x2(x2),_y2(y2){}

std::string Line::to_string()
{
	return "(" + std::to_string(_x1) + "," + std::to_string(_y1) + ")-(" + std::to_string(_x2) + "," + std::to_string(_y2) + ")";
}

double Line::length()
{
	return sqrt((((_x1)-(_x2))*((_x1)-(_x2))+((_y1)-(_y2))*((_y1)-(_y2))));
}



