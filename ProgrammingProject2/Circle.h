#ifndef CIRCLEHEAD
#define CIRCLEHEAD


#include "Shape.h"
#include "Square.h"


class Circle: public Shape
{
public:
	Circle();
	Circle(float x, float y, float h);
	~Circle();

	//Get methods for center point of the circle
	float getX();
	float getY();

	//Get the diameter of the circle
	float getH();

	//Gets the radius of the circle
	float getR();

	//Get function for ShapeType
	Shapetype getType();

	//Function to move each shape in the x and y directions
	void move(float x, float y);

	//Following two collisionDetected functions have been included in the third as a general one for any shape passed in
	//bool collisionDetected(Circle* circ);
	//bool collisionDetected(Square* squar);
	bool collisionDetected(Shape* shape);

private:
	
	//Center of circle at point (x, y)
	float x;
	float y;

	//Radius of circle
	float r;

	//Diameter of circle
	float h;

	//Type of shape always set to SHAPE_CIRCLE when creating a circle
	Shapetype type = SHAPE_CIRCLE;

};

//Inline get methods
inline float Circle::getX()
{
	return x;
}
inline float Circle::getY()
{
	return y;
}
inline float Circle::getH()
{
	return h;
}
inline float Circle::getR()
{
	return r;
}
inline Shapetype Circle::getType()
{
	return type;
}

#endif