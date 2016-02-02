
#include "Circle.h"
#include <math.h>

Circle::Circle()
{
}

Circle::Circle(float newx, float newy, float newh)
{
	x = newx;
	y = newy;
	h = newh;
	r = newh / 2;
}

Circle::~Circle()
{
}

//Moving the shape function
void Circle::move(float addx, float addy)
{
	x = x + addx;
	y = y + addy;
}

//Function replaces the two below and combines them into one
bool Circle::collisionDetected(Shape* shape)
{
	//Check if collision for circle and circle
	if (shape->getType() == SHAPE_CIRCLE)
	{
		Circle* circ = static_cast<Circle*>(shape);
		float distance = sqrt((x - circ->getX()) * (x - circ->getX()) + (y - circ->getY()) * (y - circ->getY()));
		if (distance < r + circ->getR())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	//Check if collision for circle and square
	else
	{
		Square* squar = static_cast<Square*>(shape);
		float circleDistanceX = abs(x - squar->getX());
		float circleDistanceY = abs(y - squar->getY());

		if (circleDistanceX > (squar->getH() / 2 + r)) { return false; }
		if (circleDistanceY > (squar->getH() / 2 + r)) { return false; }

		if (circleDistanceX <= (squar->getH() / 2)) { return true; }
		if (circleDistanceY <= (squar->getH() / 2)) { return true; }

		float cornerDistance_sq = ((circleDistanceX - squar->getH() / 2) * (circleDistanceX - squar->getH() / 2)) +
			(circleDistanceY - squar->getH() / 2) * (circleDistanceY - squar->getH() / 2);

		return (cornerDistance_sq <= (r * r));
	}
}

/*

The two collisionDetected functions below were intially created for detection of each individual shape.
Rather than have two functions, they were both put into one, using whichever one is necessary depending on the shape.


bool Circle::collisionDetected(Circle* circ)
{
	float distance = sqrt((x - circ->x) * (x - circ->x) + (y - circ->y) * (y - circ->y));
	if (distance < r + circ->r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Circle::collisionDetected(Square* squar)
{
	float circleDistanceX = abs(x - squar->getX());
	float circleDistanceY = abs(y - squar->getY());

	if (circleDistanceX > (squar->getH() / 2 + r)) { return false; }
	if (circleDistanceY > (squar->getH() / 2 + r)) { return false; }

	if (circleDistanceX <= (squar->getH() / 2)) { return true; }
	if (circleDistanceY <= (squar->getH() / 2)) { return true; }

	float cornerDistance_sq = ((circleDistanceX - squar->getH() / 2) * (circleDistanceX - squar->getH() / 2)) +
		(circleDistanceY - squar->getH() / 2) * (circleDistanceY - squar->getH() / 2);

	return (cornerDistance_sq <= (r * r));
}
*/

