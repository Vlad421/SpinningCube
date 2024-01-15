#include "Renderer.h"

Renderer::Renderer(SDL_Window *window, SDL_Renderer *renderer,
		std::vector<Point3D> &points3D, std::vector<Vertex> &vertices) {

	SDL_GetWindowSize(window, &windowSizeX, &windowSizeY);
	this->renderer = renderer;
	this->points3D = points3D;
	this->vertices = vertices;
}

void Renderer::render() {
	auto time1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration(0);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);

	rotation += 1 * dTime;

	for (auto &vertex : vertices) {

		Point3D rotatedStartPoint = rotateX(rotateY(points3D[vertex.start]));

		Point3D rotatedEndPoint = rotateX(rotateY(points3D[vertex.end]));

		Point2D start = project(rotatedStartPoint);
		Point2D end = project(rotatedEndPoint);
		SDL_RenderDrawLine(renderer, start.x, start.y, end.x, end.y);

	}

	SDL_RenderPresent(renderer);
	auto time2 = std::chrono::high_resolution_clock::now();
	duration = time2 - time1;
	dTime = duration.count();
	time1 = time2;

}

Point3D Renderer::rotateX(Point3D point) {
	Point3D returnPoint;
	returnPoint.x = point.x;
	returnPoint.y = cos(rotation) * point.y - sin(rotation) * point.z;
	returnPoint.z = sin(rotation) * point.y + cos(rotation) * point.z;

	return returnPoint;
}

Point3D Renderer::rotateY(Point3D point) {
	Point3D returnPoint;
	returnPoint.x = cos(rotation) * point.x - sin(rotation) * point.z;
	returnPoint.y = point.y;
	returnPoint.z = sin(rotation) * point.x + cos(rotation) * point.z;

	return returnPoint;
}

Point2D Renderer::project(Point3D point) {

	return Point2D { windowSizeX / 2 + (FOV * point.x) / (FOV + point.z) * 100,
			windowSizeY / 2 + (FOV * point.y) / (FOV + point.z) * 100 };
}
