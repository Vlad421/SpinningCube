#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <chrono>
#include <math.h>

struct Point2D {
	float x, y;
};
struct Point3D {
	float x, y, z;
};
struct Vertex {
	int start, end;
};
class Renderer {
public:
	Renderer(SDL_Window *window, SDL_Renderer *renderer,
			std::vector<Point3D> &points3D, std::vector<Vertex> &vertices);
	void render();
private:
	float FOV = 10.0f;
	float rotation = 0.0f;
	float dTime = 0.0f;

	int windowSizeX, windowSizeY;
	SDL_Renderer *renderer;
	std::vector<Point3D> points3D;
	std::vector<Vertex> vertices;

	Point3D rotateX(Point3D point);
	Point3D rotateY(Point3D point);
	Point2D project(Point3D point);

};

