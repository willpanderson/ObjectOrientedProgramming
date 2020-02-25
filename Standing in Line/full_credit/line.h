#ifndef __LINE_H
#define __LINE_H


#include <string>



class Line {
public:
	Line(double x1,double y1, double x2, double y2);
	std::string to_string();
	double length();

private:
	double _x1,_y1,_x2,_y2;
};

#endif
