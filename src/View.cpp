/**
 * @file View.cpp
 * @author user p4553d
 */



#include "View.h"
#include "Log.h"
#include "Controller.h"

#include "SDL.h"

//#include <GL/gl.h>		   // Open Graphics Library (OpenGL) header
//#include <GL/glut.h>	   // The GL Utility Toolkit (GLUT) Header
//TODO REMOVE

pthread_t View::viewTread;

View::View()
{

	LOG_INFO("View initialisation");

	m_zoom = 10.0f;
	m_xView = 0;
	m_yView = 0;
	m_width = 640;
	m_height = 480;

	const char* title="tanks2d2";



	//SDL init
	if (-1 == SDL_Init(SDL_INIT_EVERYTHING)) {
		LOG_INFO("Can't initialize SDL\n");
		throw 1; //TODO
	}

	atexit(SDL_Quit);

	screen = SDL_SetVideoMode(m_width,
	                          m_height,
	                          0,
	                          SDL_ANYFORMAT |
	                          //SDL_FULLSCREEN |
	                          SDL_SWSURFACE
	                         );

	if (NULL == screen) {
		LOG_INFO("Can't set video mode\n");
		throw 2; // TODO
	}

	pf = screen->format;

	m_background = SDL_MapRGB(pf, 0x00, 0x00, 0x00);

	SDL_WM_SetCaption(title, title);

}

View::~View()
{
	// intentional empty
}

View& View::getInstance()
{
	static View _instance;
	return _instance;
}

SDL_Surface* View::getScreen()
{
	return screen;
}

void View::set_zoom(float value)
{
	m_zoom = value;
	resize(m_width, m_height);
}

void View::set_xView(float value)
{
	m_xView = value;
}

void View::set_yView(float value)
{
	m_yView = value;
}

const float View::get_zoom() const
{
	return m_zoom;
}

const float View::get_xView() const
{
	return m_xView;
}

const float View::get_yView() const
{
	return m_yView;
}

const float View::get_width() const
{
	return m_width;
}

void View::set_width(float value)
{
	m_width = value;
}

const float View::get_height() const
{
	return m_height;
}

void View::set_height(float value)
{
	m_height = value;
}

void View::renderView()
{
	View &v = View::getInstance();
	v.render();
}

void View::render()
{
	bool done = false;
	while (!done)
	{
		while (!done && SDL_PollEvent(&event)) {	//TODO implement keyboard controller
			switch (event.type) {
	
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
				case SDLK_ESCAPE:
					done = true;
					break;
	
				default:
					break;
				}
				break;
	
			case SDL_QUIT:
				done = true;
				break;
			}
		}
		
		SDL_FillRect(screen, NULL, m_background);	//whipe old picture
		pthread_mutex_lock(&view_mutex);
		AbstractView::render();
		pthread_mutex_unlock(&view_mutex);
		SDL_Flip(screen);		// swap buffers
		SDL_Delay(10);			// 100 fps is pretty enough
	}
}

void View::registerRenderable(IRenderable * r)
{
	pthread_mutex_lock(&view_mutex);
	AbstractView::registerRenderable(r);
	pthread_mutex_unlock(&view_mutex);
}

void View::removeRenderable(IRenderable * r)
{
	pthread_mutex_lock(&view_mutex);
	AbstractView::removeRenderable(r);
	pthread_mutex_unlock(&view_mutex);
}

void View::resize(int w, int h)
{
	View &v = View::getInstance();

	v.set_width(w);
	v.set_height(h);

	float zoom = v.get_zoom();
	float xView = v.get_xView();
	float yView = v.get_yView();

	float nRange = 2*w/zoom;



	if (w <= h) {
		//glOrtho (xView-nRange, xView+nRange, yView-nRange*h/w, yView+nRange*h/w, -1, 1);
	} else {
		//glOrtho (xView-nRange*w/h, xView+nRange*w/h, yView-nRange, yView+nRange, -1, 1);
	}


}
