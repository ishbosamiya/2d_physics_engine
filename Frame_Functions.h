#ifndef FRAME_FUNCTIONS_H
#define FRAME_FUNCTIONS_H

#include "general_declarations.h"
#include "general_functions.h"
#include <iostream>

void everyFrameForCircle(circle &circ)
{
	circleStruct circInfo = circ.getCircleInfo();

	if (circInfo.centre.Y + circInfo.radius < -1) return;

	if (circ.isCollidingWithLine(fixedLine))
		circ.setNewVelValuesIfColliding(getFootOfPerpendicular(circInfo.centre, fixedLine));
	else circ.setNewVelValuesIfNotColliding();

	circ.updateValues();
}

#endif
