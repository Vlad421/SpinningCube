#include <SDL2/SDL.h>
#include "Renderer.h"
#include <stdlib.h>
#include <vector>

#define WIDTH 500
#define HEIGHT 500

// cube

std::vector<Point3D> pointsCube { Point3D { -1.0f, -1.0f, -1.0f }, Point3D {
		-1.0f, -1.0f, 1.0f }, Point3D { 1.0f, -1.0f, -1.0f }, Point3D { -1.0f,
		1.0f, -1.0f }, Point3D { -1.0f, 1.0f, 1.0f }, Point3D { 1.0f, -1.0f,
		1.0f }, Point3D { 1.0f, 1.0f, -1.0f }, Point3D { 1.0f, 1.0f, 1.0f, } };

std::vector<Vertex> verticesCube { Vertex { 0, 1 }, Vertex { 0, 2 }, Vertex { 0,
		3 }, Vertex { 2, 5 }, Vertex { 3, 6 }, Vertex { 3, 4 }, Vertex { 4, 7 },
		Vertex { 6, 7 }, Vertex { 7, 5 }, Vertex { 5, 1 }, Vertex { 4, 1 },
		Vertex { 2, 6 } };
// pyramid
std::vector<Point3D> pointsPyramid { Point3D { 1.0f, 1.0f, 1.0f }, Point3D {
		-1.0f, -1.0f, 1.0f }, Point3D { -1.0f, 1.0f, -1.0f }, Point3D { 1.0f,
		-1.0f, -1.0f } };
std::vector<Vertex> verticesPyramid { Vertex { 0, 1 }, Vertex { 0, 2 }, Vertex {
		0, 3 }, Vertex { 1, 2 }, Vertex { 1, 3 }, Vertex { 2, 3 } };

int main(int argc, char *args[]) {
	// INITIALISE EVENT, RENDER, AND WINDOW VARS

	SDL_Window *window = SDL_CreateWindow("Cube", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED);
	// CREATE WINDOW

	// CLEARING SCREEN TO BLACK
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	// THE DISPLAY LOOP
	bool running = true;
	Renderer render(window, renderer, pointsCube, verticesCube);
	while (running) {
		// EXITING
		if (SDL_QuitRequested()) {
			running = false;
			break;
		}
		render.render();
	}
	// CLEAN UP
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}
