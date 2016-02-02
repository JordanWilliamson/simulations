#include "Square.h"
#include "Circle.h"
#include <math.h>

Square::Square()
{
}

Square::Square(float newx, float newy, float newh)
{
	x = newx;
	y = newy;
	h = newh;
}

Square::~Square()
{
}

//Function for moving the shape in the x and y directions
void Square::move(float addx, float addy)
{
	x = x + addx;
	y = y + addy;
}
/*

The two collisionDetected functions below were intially created for detection of each individual shape.
Rather than have two functions, they were both put into one, using whichever one is necessary depending on the shape.

bool Square::collisionDetected(Circle* circ)
{
	float circleDistanceX = abs(circ->getX() - x);
	float circleDistanceY = abs(circ->getY() - y);

	if (circleDistanceX > (h / 2 + circ->getR())) { return false; }
	if (circleDistanceY > (h / 2 + circ->getR())) { return false; }

	if (circleDistanceX <= (h / 2)) { return true; }
	if (circleDistanceY <= (h / 2)) { return true; }

	float cornerDistance_sq = ((circleDistanceX - h / 2) * (circleDistanceX - h / 2)) +
		(circleDistanceY - h / 2) * (circleDistanceY - h / 2);

	return (cornerDistance_sq <= (circ->getR() * circ->getR()));
}

bool Square::collisionDetected(Square* squar)
{
	if (x < squar->x + squar->h && x + h > squar->x && y < squar->y + squar->h && h + y > squar->y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/
bool Square::collisionDetected(Shape* shape)
{
	if (shape->getType() == SHAPE_CIRCLE)
	{
		Circle* circ = static_cast<Circle*>(shape);
		float circleDistanceX = abs(circ->getX() - x);
		float circleDistanceY = abs(circ->getY() - y);

		if (circleDistanceX > (h / 2 + circ->getR())) { return false; }
		if (circleDistanceY > (h / 2 + circ->getR())) { return false; }

		if (circleDistanceX <= (h / 2)) { return true; }
		if (circleDistanceY <= (h / 2)) { return true; }

		float cornerDistance_sq = ((circleDistanceX - h / 2) * (circleDistanceX - h / 2)) +
			(circleDistanceY - h / 2) * (circleDistanceY - h / 2);

		return (cornerDistance_sq <= (circ->getR() * circ->getR()));
	}
	else
	{
		Square* squar = static_cast<Square*>(shape);
		if (x < squar->x + squar->h && x + h > squar->x && y < squar->y + squar->h && h + y > squar->y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
