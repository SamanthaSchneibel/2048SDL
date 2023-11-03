/*
#include "gameObject.hpp"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::draw() {

	SDL_Rect oPosition;
	oPosition.x = 0;
	oPosition.y = 0;

	SDL_QueryTexture(pTexture, NULL, NULL, &oPosition.w, &oPosition.h);

	SDL_RenderCopy(Window::pRenderer, pTexture, NULL, &oPosition);

}
*/