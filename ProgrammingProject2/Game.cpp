#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>

float RandomInt(float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float difference = max - min;
	float rand = random * difference;
	return min + rand;
}
int RandomInt() {
	float max = rand();
	float min = 1;
	float random = ((float)rand()) / (float)RAND_MAX;
	float difference = max - min;
	float rand = random * difference;
	return min + rand;
}
asdasfvdasvsdavssdvsvdasvdvdvsdsdasdvsddasvsdvaasdvasdvsdvsdsdvvsd

int main()
{
	//Number of shapes to create
	const int numShapes = 11;
	//Variable number of shapes remaining
	int numShapesRemaining = numShapes;
	//Size of grid
	int squareGridSize = 400;

	//Creating a vector list of shapes
	std::vector<Shape*> listShapes;

	//Randomly generates spheres and circles with randomly generated x, y and h values
	for (int i = 0; i < numShapes; i++)
	{
		if (RandomInt() % 2 == 0)
		{
			listShapes.push_back(new Circle(RandomInt(1, squareGridSize), RandomInt(1, squareGridSize), RandomInt(1, 10)));
		}
		else
		{
			listShapes.push_back(new Square(RandomInt(1, squareGridSize), RandomInt(1, squareGridSize), RandomInt(1, 10)));
		}
	}

	//Prints out the x, y and h values of all circles and squares created and the type 
	for (int i = 0; i < numShapes; i++)
	{
		if (listShapes.at(i)->getType() == SHAPE_CIRCLE)
		{
			std::cout << "Circle values x: " << listShapes.at(i)->getX() << " y: " << listShapes.at(i)->getY() << " diameter of shape: " << listShapes.at(i)->getH() << std::endl;
		}
		else
		{
			std::cout << "Square values x: " << listShapes.at(i)->getX() << " y: " << listShapes.at(i)->getY() << " length of side of shape: " << listShapes.at(i)->getH() << std::endl;
		}
	}
	
	
	std::cout << "\nShapes to be removed before the start of the game:" << std::endl;
	//Loops through the list of shapes and searches to see if any collide already and removes them
	for (int i = 0; i < numShapesRemaining; i++)
	{
		for (int j = i + 1; j < numShapesRemaining; j++)
		{
			if (listShapes.at(i)->collisionDetected(listShapes.at(j)))
			{
				std::cout << "Shape " << i << " and shape " << j << " collided and will be removed" << std::endl;
				if (listShapes.at(i)->getType() == SHAPE_CIRCLE)
				{
					std::cout << "Circle values x: " << listShapes.at(i)->getX() << " y: " << listShapes.at(i)->getY() << " diameter of shape: " << listShapes.at(i)->getH() << std::endl;
				}
				else
				{
					std::cout << "Square values x: " << listShapes.at(i)->getX() << " y: " << listShapes.at(i)->getY() << " length of side of shape: " << listShapes.at(i)->getH() << std::endl;
				}
				if (listShapes.at(j)->getType() == SHAPE_CIRCLE)
				{
					std::cout << "Circle values x: " << listShapes.at(j)->getX() << " y: " << listShapes.at(j)->getY() << " diameter of shape: " << listShapes.at(j)->getH() << std::endl;
				}
				else
				{
					std::cout << "Square values x: " << listShapes.at(j)->getX() << " y: " << listShapes.at(j)->getY() << " length of side of shape: " << listShapes.at(j)->getH() << std::endl;
				}

				listShapes.erase(listShapes.begin() + j);
				listShapes.erase(listShapes.begin() + i);
				numShapesRemaining = numShapesRemaining - 2;
				i = 0;
				j = i + 1;

			}
		}
	}

	std::cout << "\n\nStarting game" << std::endl;
	std::cout << "\n\nShapes removed during the game:" << std::endl;
	while (numShapesRemaining > 1)
	{
		for (int i = 0; i < numShapesRemaining; i++)
		{
			//Shapes will move either -1, 1 or 0 in the x and y directions
			int moveX = (rand() % 3) - 1;
			int moveY = (rand() % 3) - 1;
			//rand using different seed
			srand(time(NULL));

			//If moving the shape moves it off the grid then reverse the random movement
			if (listShapes.at(i)->getX() + listShapes.at(i)->getH() /2 + moveX  > squareGridSize)
			{
				moveX = 0 - moveX;
			}
			if (listShapes.at(i)->getY() + listShapes.at(i)->getH() / 2 + moveY > squareGridSize)
			{
				moveY = 0 - moveY;
			}
			if ((listShapes.at(i)->getX() - listShapes.at(i)->getH() / 2) + moveX < 0)
			{
				moveX = 0 - moveX;
			}
			if ((listShapes.at(i)->getY() - listShapes.at(i)->getH() / 2) + moveY < 0)
			{
				moveY = 0 - moveY;
			}

			//Moving the shape should keep it on the grid
			listShapes.at(i)->move(moveX, moveY);
			//Checks if the movement of a shape causes any collisions
			for (int j = i + 1; j < numShapesRemaining; j++)
			{
				if (listShapes.at(i)->collisionDetected(listShapes.at(j)))
				{
					std::cout << "Shape " << i << " and shape " << j << " collided and will be removed" << std::endl;
					if (listShapes.at(i)->getType() == SHAPE_CIRCLE)
					{
						std::cout << "Circle values x: " << listShapes.at(i)->getX() << " y: " << listShapes.at(i)->getY() << " diameter of shape: " << listShapes.at(i)->getH() << std::endl;
					}
					else
					{
						std::cout << "Square values x: " << listShapes.at(i)->getX() << " y: " << listShapes.at(i)->getY() << " length of side of shape: " << listShapes.at(i)->getH() << std::endl;
					}
					if (listShapes.at(j)->getType() == SHAPE_CIRCLE)
					{
						std::cout << "Circle values x: " << listShapes.at(j)->getX() << " y: " << listShapes.at(j)->getY() << " diameter of shape: " << listShapes.at(j)->getH() << std::endl;
					}
					else
					{
						std::cout << "Square values x: " << listShapes.at(j)->getX() << " y: " << listShapes.at(j)->getY() << " length of side of shape: " << listShapes.at(j)->getH() << std::endl;
					}
					listShapes.erase(listShapes.begin() + j);
					listShapes.erase(listShapes.begin() + i);
					numShapesRemaining = numShapesRemaining - 2;
					i = 0;
					j = 1;
				}
			}
		}
	}
	//One shape remains, game ends
	std::cout << "\n\nGame has finished!\n\n" << std::endl;

	if (numShapesRemaining > 0)
	{
		if (listShapes.at(0)->getType() == SHAPE_CIRCLE)
		{
			std::cout << "The winner was a CIRCLE with these values \nx: " << listShapes.at(0)->getX() << " \ny: " << listShapes.at(0)->getY() << " \ndiameter of shape: " << listShapes.at(0)->getH() << std::endl;
		}
		else
		{
			std::cout << "The winner was a SQUARE with these values \nx: " << listShapes.at(0)->getX() << " \ny: " << listShapes.at(0)->getY() << " \nlength of side of shape: " << listShapes.at(0)->getH() << std::endl;
		}
	}
	else
	{
		std::cout << "There were no winners here today" << std::endl;
	}
	
	int x;
	std::cin >> x;
	return 0;
}