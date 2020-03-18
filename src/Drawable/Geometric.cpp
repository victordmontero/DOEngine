#include "Geometric.h"

void DrawPoint(const Point &point, const Color& color, Window *window){
    SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(window->getRender(), point.x, point.y);
}
void DrawLine(const Point& p1, const Point& p2, const Color &color, Window *window){
     SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a);
     SDL_RenderDrawLine(window->getRender(), p1.x, p1.y, p2.x, p2.y);
}

void DrawRect(const Rect &rect, const Color& color, Window *window){
   SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a);
   SDL_RenderDrawRect(window->getRender(), &rect);
}
void DrawFillRect(const Rect &rect, const Color& color, Window *window){
  SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(window->getRender(), &rect);
}


void FillCircle(int x, int y, int radius, const Color& color, Window *window)
	{
		int x0 = 0;
		int y0 = radius;
		int d = 3 - 2 * radius;
		if (!radius) return;

		auto drawline = [&](int sx, int ex, int ny)
		{
			for (int i = sx; i <= ex; i++)
				DrawPoint({i, ny}, color, window);
		};

		while (y0 >= x0)
		{
			// Modified to draw scan-lines instead of edges
			drawline(x - x0, x + x0, y - y0);
			drawline(x - y0, x + y0, y - x0);
			drawline(x - x0, x + x0, y + y0);
			drawline(x - y0, x + y0, y + x0);
			if (d < 0) d += 4 * x0++ + 6;
			else d += 4 * (x0++ - y0--) + 10;
		}
	}


void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, const Color& p, Window *window)
	{
		DrawLine({x1, y1}, {x2, y2}, p, window);
		DrawLine({x2, y2}, {x3, y3}, p, window);
		DrawLine({x3, y3}, {x1, y1}, p, window);
	}