#include "Geometric.h"
#include "Window.h"
#include "Canvas.h"


#if 0 
namespace {
    SDL_Color _color={0,0,0,255};
    SDL_Rect  _offset={0,0,800,800};
}
void begin(Window *window){
    
}
void end(Window *window){
    
}

void setCurrentCanvasPosition(int x, int y){
   _offset.x = x;
   _offset.y = y;
}
void setCurrentCanvasSize(int w, int h){
    _offset.w = w;
    _offset.h = h;
}

void fillStyle(SDL_Color color){
    _color.r = color.r;
    _color.g = color.g;
    _color.b = color.b;
    _color.a = color.a;
}
void fillRect(Window *window, int x, int y, int w, int h){
    SDL_Rect rect{_offset.x + x, _offset.y+ y,w,h};
    DrawFillRect(rect,_color,window);
}

void DrawRect(Window *window, int x, int y, int w, int h){
    SDL_Rect rect{_offset.x + x, _offset.y+ y,_offset.w,_offset.h};
    DrawRect(rect,_color,window);
}
void arc(Window *window, int x, int y, int radius, double startAngle, double endAngle ) {
    
  
    const int NUM_SEGMENTS = 100; // Number of line segments to approximate the arc
    SDL_SetRenderDrawColor(window->getRender(), _color.r, _color.g, _color.b, _color.a);
 
    for (int i = 0; i <= NUM_SEGMENTS; ++i) 
    {
        double angle = startAngle + (endAngle - startAngle) * i / NUM_SEGMENTS;
        int x1 = x + static_cast<int>(radius * cos(angle));
        int y1 = y + static_cast<int>(radius * sin(angle));
        
          SDL_RenderDrawPoint(window->getRender(), _offset.x+x1, _offset.y+ y1);
 
    }
 
}

void DrawPoint(const Point &point, const Color& color, Window *window){
   /// SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(window->getRender(), point.x, point.y);
}
void DrawLine(const Point& p1, const Point& p2, const Color &color, Window *window){
    /// SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a);
     SDL_RenderDrawLine(window->getRender(), p1.x, p1.y, p2.x, p2.y);
}

void DrawRect(const Rect &rect, const Color& color, Window *window){
 ///  SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a);
   SDL_RenderDrawRect(window->getRender(), &rect);
}
void DrawFillRect(const Rect &rect, const Color& color, Window *window){
  ///SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a);
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

 


void DrawRect(SDL_Renderer *render, SDL_Rect rect){
    SDL_RenderDrawRect(render, &rect);
}

void DrawRect(Window *window, SDL_Rect rect){
    SDL_RenderDrawRect(window->getRender(), &rect);
}
#endif
void DrawSinglePoint(const Rect &rect, const Color& color, Window *window){
   SDL_SetRenderDrawColor(window->getRender(), color.r, color.g, color.b, color.a); 
   SDL_RenderDrawPoint(window->getRender(), rect.x, rect.y);
}
void DrawNotFillRect(const Rect &rect, const Color& color, Window *window){
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
				DrawSinglePoint({i, ny}, color, window);
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


void CanvasCircleCommand::Draw(Window *window)
{
 FillCircle(where.x, where.y,  radius, color, window);
}


void CanvasRectCommand::Draw(Window *window)
{
  // SDL_Log("Render Rect [%ld, %ld, %ld %ld](%02x %02x %02x %02x)", offset.x, offset.y, offset.w, offset.h, color.r, color.g, color.b, color.a);
     SDL_Log("Canvas Draw[%ld, %ld, %ld, %ld]",  offset.x, offset.y,  offset.w, offset.h);
 
   DrawNotFillRect(offset, color, window);
}


void CanvasPointDrawCommand::Draw(Window *window)
{
   DrawSinglePoint(offset, color, window);
}

Canvas* Canvas::setCanvasBackgroundColor(SDL_Color color)
{ 
    _bg.r = color.r;
    _bg.g = color.g;
    _bg.b = color.b;
    _bg.a = color.a;
    return this;
}

Canvas::Canvas(Window *window)
{
    this->window = window;
    setCanvasBackgroundColor({255,255,255,255});
    fillColor({0,0,0,255});
    setRect({0,0,window->getW(), window->getH()});
}  

Canvas* Canvas::fillColor(SDL_Color color)
{
    _filler.r = color.r;
    _filler.g = color.g;
    _filler.b = color.b;
    _filler.a = color.a;
    return this;
}
   
Canvas* Canvas::setRect(SDL_Rect rect)
{
   _offset.x = rect.x;
   _offset.y = rect.y;
   _offset.w = rect.w;
   _offset.h = rect.h;
   return this;
}
Canvas* Canvas::DrawPoint(int x, int y)
{
    CanvasPointDrawCommand* rect = new CanvasPointDrawCommand();
    rect->offset.x =  this->_offset.x + x;
    rect->offset.y =  this->_offset.y + y;
    rect->offset.w =  1;
    rect->offset.h =  1; 
    rect->color.r =   _filler.r;
    rect->color.g =   _filler.g;
    rect->color.b =  _filler.b;
    rect->color.a =  _filler.a;

    this->commands_to_draw.push_back(rect);
}

 Canvas* Canvas::FillCircle(int x, int y, double rsize)
 {
    CanvasCircleCommand *cmd = new CanvasCircleCommand();
    cmd->color = _filler;
    cmd->radius = rsize;
    cmd->where.x = x;
    cmd->where.y = y;
        this->commands_to_draw.push_back(cmd);
    return this;
 }

Canvas* Canvas::DrawRect(int x, int y, int w, int h)
{
    CanvasRectCommand* rect = new CanvasRectCommand();
    rect->offset.x =  this->_offset.x + x;
    rect->offset.y =  this->_offset.y + y;
    rect->offset.w =  w;
    rect->offset.h =  h;
    rect->color.r =   _filler.r;
    rect->color.g =   _filler.g;
    rect->color.b =  _filler.b;
    rect->color.a =  _filler.a;

    this->commands_to_draw.push_back(rect);

    return this;
}

 Canvas* Canvas::update()
 {
 
    setCanvasBackgroundColor(_bg);
 
    ::DrawFillRect(_offset, _bg,  window);
   
    for(auto it : commands_to_draw)
    {  
         it->Draw(window);
    }
   return this;
 }

Canvas* Canvas::clearCanvas(){
    ///for(auto it : commands_to_draw)
    commands_to_draw.erase(commands_to_draw.begin(), commands_to_draw.end());
    commands_to_draw.clear();
    return this;
}