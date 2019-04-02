#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#include "general_declarations.h"
#include <iostream>
using namespace std;

double getDistance(point p1, point p2)
{
	double distance = pow(p1.X - p2.X, 2) + pow(p1.Y - p2.Y, 2);
	distance = sqrt(distance);

	return distance;
}

double getSlope(point point1, point point2)
{
	if (point1.X == point2.X) return tan(PI / 2 - 0.00000001);
	else return (point1.Y - point2.Y) / (point1.X - point2.X);
}

line makeLineWith2Points(point point1, point point2)
{
	line line;
	line.points[0] = point1;
	line.points[1] = point2;
	line.slope = getSlope(point1, point2);
	line.intercept = point1.Y - line.slope * point1.X;
	return line;
}

point getFootOfPerpendicular(point p, line l)
{
	if ((l.slope*p.X + l.intercept - p.Y) == 0) return p;

	point foot;

	if (l.slope == 0) foot.X = p.X;
	else foot.X = (p.X / l.slope + p.Y - l.intercept)*l.slope / (l.slope*l.slope + 1);

	foot.Y = l.slope*foot.X + l.intercept;

	return foot;
}

circleStruct circle::getCircleInfo()
{
	return circle::circleInfo;
}

physProp circle::getCirclePhyInfo()
{
	return circle::circlePhyInfo;
}

bool circle::isCollidingWithLine(line plane)
{
	bool ans = false;
	point POI;
	POI = getFootOfPerpendicular(circle::circleInfo.centre, plane);

	double epsilon = 0.0000001;

    /*
	if (getDistance(circle::circleInfo.centre, POI) <= circle::circleInfo.radius)
		if (getDistance(plane.points[0], POI) + getDistance(plane.points[1], POI) == getDistance(plane.points[0], plane.points[1]))
			ans = true;
    */

    if (getDistance(circle::circleInfo.centre, POI) <= circle::circleInfo.radius)
		if ( fabs( (getDistance(plane.points[0], POI) + getDistance(plane.points[1], POI) ) - getDistance(plane.points[0], plane.points[1]) ) < epsilon)
			ans = true;

	if (ans == false)
	{
		point nCentre;
		nCentre = circle::circleInfo.centre;
		nCentre.X += circle::circlePhyInfo.velX;
		nCentre.Y += circle::circlePhyInfo.velY;

		if (getDistance(nCentre, POI) + getDistance(circle::circleInfo.centre, POI) == getDistance(nCentre, circle::circleInfo.centre))
			ans = true;
	}

	return ans;
}

void circle::setInitValues(float nRadius, point nCentre)
{
	circle::circleInfo.radius = nRadius;
	circle::circleInfo.centre = nCentre;
	circle::circlePhyInfo.velX = 0;
	circle::circlePhyInfo.velY = 0;
}

void circle::updateValues()
{
	circle::circleInfo.centre.X += circle::circlePhyInfo.velX;
	circle::circleInfo.centre.Y += circle::circlePhyInfo.velY;
}

void circle::setNewVelValuesIfColliding(point POI)
{
	double angle = getSlope(circle::circleInfo.centre, POI);
	if(angle == tan(PI / 2 - 0.00000001)) angle = PI/2;
	else angle = atan(angle);

	if(angle < 0) angle += PI;

	cout<<"Angle: " << angle * 180/ PI << endl;

	double mag = circle::circlePhyInfo.velX*circle::circlePhyInfo.velX + circle::circlePhyInfo.velY*circle::circlePhyInfo.velY;
	mag = sqrt(mag);

	circle::circlePhyInfo.velX = cos(angle)*mag;
	circle::circlePhyInfo.velY = sin(angle)*mag;

	//circle::circlePhyInfo.velY *= -1;

    std::cout << "Colliding" << std::endl;
	std::cout<<"VELOCITY "<<circle::circlePhyInfo.velY<<std::endl;
}

void circle::setNewVelValuesIfNotColliding()
{
	circle::circlePhyInfo.velY -= g;
}

#endif
