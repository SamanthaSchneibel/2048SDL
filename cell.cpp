#include "cell.hpp"
#include "window.hpp"

Cell::Cell()
{
	value = 0;
}

/*
void Cell::setTextures(std::vector<SDL_Texture*>* textures) 
{
	this->textures = textures;
}
*/

Cell::~Cell()
{
}

int Cell::getValue() {

	return this->value;
}

void Cell::doubleValue() 
{
	setValue(value * 2);
}

void Cell::resetValue()
{
	setValue(0);
}

bool Cell::isEmpty() {

	return this->value == 0;
}

void Cell::setValue(int value)
{
	this->value = value;

	/*
	if (value == 0) 
	{
		pTexture = (*textures)[0];
	}
	else
	if( value == 2)
	{
		pTexture = (*textures)[1];
	}
	*/
	
}

void Cell::setValue(Cell& oCell) {

	this->value = oCell.getValue();
}