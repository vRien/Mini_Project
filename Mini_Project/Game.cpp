#include"Game.h"
#include"SDL_image.h"
#include <iostream>



bool Game::init(const char*title, int xpos, int ypos,

	int width, int height, bool fullscreen)

{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;


		SDL_Surface* pTempSurface = IMG_Load("./Assets/miro.png");
		SDL_Surface* character = IMG_Load("./Assets/carbi.png");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer,
			pTempSurface);
		m_cTexture = SDL_CreateTextureFromSurface(m_pRenderer,
			character);
		SDL_FreeSurface(pTempSurface);
		SDL_FreeSurface(character);

		m_sourceRectangle.w = 640;
		m_sourceRectangle.h = 640;
		CharRect.w = 18;
		CharRect.h = 18;

		m_destinationRectangle.x = m_sourceRectangle.x;
		m_destinationRectangle.y = m_sourceRectangle.y;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;

		Charactordestination.x = 65;
		Charactordestination.y = 50;
		Charactordestination.w = CharRect.w;
		Charactordestination.h = CharRect.h;

		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	}

	else {
		return false; // sdl could not initialize

	}

	return true;
}



void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pTexture,
		&m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderCopy(m_pRenderer, m_cTexture,
		&CharRect, &Charactordestination);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	//m_sourceRectangle.x = 128 * int(((SDL_GetTicks() / 100) % 6));
}



void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_bRunning = true;
		}
	}
}