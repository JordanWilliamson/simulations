#ifndef SQUAREHEAD
#define SQUAREHEAD


#include "Shape.h"
class Circle;


class Square:public Shape
{
public:
	Square();
	Square(float x, float y, float h);
	~Square();
	

	//Get functions for center point of the circle
	float getX();
	float getY();

	//Get function for side length of square
	float getH();
	

	//Get function for ShapeType
	Shapetype getType();
	
	//Function to move each shape in the x and y directions
	void move(float x, float y);

	//Following two collisionDetected functions have been included in the third as a general one for any shape passed in
	//bool collisionDetected(Circle* circ);
	//bool collisionDetected(Square* squar);
	bool collisionDetected(Shape* shape);

private:
	//Center of square at point (x, y)
	float x;
	float y;

	//Side length of square
	float h;

	//Type of shape always set to SHAPE_SQUARE when creating a square
	Shapetype type = SHAPE_SQUARE;
};

//Inline get methods
inline float Square::getX()
{
	return x;
}
inline float Square::getY()
{
	return y;
}
inline float Square::getH()
{
	return h;
}
inline Shapetype Square::getType()
{
	return type;
}


#endif