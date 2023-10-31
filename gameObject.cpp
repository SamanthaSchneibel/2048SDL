#include "gameObject.hpp"

GameObject::GameObject()
{
	SDL_Surface* tmpSur = IMG_Load("img/");
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSur);
	SDL_FreeSurface(tmpSur);
}

GameObject::~GameObject()
{
}