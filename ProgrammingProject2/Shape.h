#ifndef SHAPEHEAD
#define SHAPEHEAD

class Square;
class Circle;

//enum to identify which shapes are circles and which are squares
enum Shapetype {
	SHAPE_CIRCLE,
	SHAPE_SQUARE
};


class Shape
{
public:
	//Following two collisionDetected functions have been included in the third as a general one for any shape passed in
	//virtual bool collisionDetected(Circle* circ) = 0;
	//virtual bool collisionDetected(Square* squar) = 0;
	virtual bool collisionDetected(Shape* shape) = 0;
	virtual void move(float x, float y) = 0;
	virtual float getX() = 0;
	virtual float getY() = 0;
	virtual float getH() = 0;
	virtual Shapetype getType() = 0;

};

#endif