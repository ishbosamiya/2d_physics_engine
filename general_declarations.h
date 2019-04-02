#ifndef GENERAL_DECLERATIONS_H
#define GENERAL_DECLERATIONS_H

#include <math.h>

struct physProp
{
	float velX;
	float velY;
};

struct point
{
	float X;
	float Y;
};

struct line
{
	float slope;
	float intercept;
	point points[2];
};

struct circleStruct
{
	float radius;
	point centre;
};

const long double PI = 3.1415926535897932384626433832795;
const double g = 0.001;

line fixedLine;

class circle
{
private:
	circleStruct circleInfo;
	physProp circlePhyInfo;

public:
	circleStruct getCircleInfo();
	physProp getCirclePhyInfo();

	bool isCollidingWithLine(line);

	void setInitValues(float, point);
	void updateValues();
	void setNewVelValuesIfColliding(point);
	void setNewVelValuesIfNotColliding();
};

#endif
