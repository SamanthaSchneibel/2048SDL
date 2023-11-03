#pragma once
//#include "gameObject.hpp"
 
//#include <vector>

class Cell //: GameObject
{
private:
	int value;

public:
	Cell();
	~Cell();

	//void setTextures(std::vector<SDL_Texture*>* textures);

	int getValue();
	void doubleValue();
	void resetValue();
	bool isEmpty();
	void setValue(int value);
	void setValue(Cell& oCell);

	//void draw() override;

private:
	//std::vector<SDL_Texture*>* textures;

};