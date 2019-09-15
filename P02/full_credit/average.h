#ifndef __AVERAGE_H
#define __AVERAGE_H

#include <iostream>

//FINAL REVISION. READY FOR GRADING -William Anderson.

class Average {
public:
	Average();
	friend std::ostream& operator <<(std::ostream& ost, Average& average);
	friend std::istream& operator >>(std::istream& ist, Average& average);
	Average& operator+=(double value);
private:
	double _sum;
	int _values;
};

#endif
