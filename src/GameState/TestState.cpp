#include <TestState.h>
#include <vector>
#include <Event.h>
#include <time.h>
#include <stdlib.h>

#include <Window.h>
struct Cloud {
	SDL_Rect rect;
	int speed;
	Window* window;
	Cloud(Window *wp) {
		window = wp;
		Reset();
		
	}
	
	Cloud* Reset() {
		speed = rand() % 3 + 1;
		rect.x = window->getW();
		rect.y = rand() % (window->getH() - 30) + 20;
		rect.w = rand() % 200 + 30;
		rect.h = rand() % 100 + 30;
		return this;
	}
	void Update() {
		rect.x += -speed;
		if (rect.x < 0) {
			Reset();
		}
	}
	void Draw() {
		SDL_SetRenderDrawColor(window->getRender(), 200, 200, 200, 255);
		SDL_RenderFillRect(window->getRender(), &rect);
	}
};


const char tileset[10][10] =
{
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
	{'1','2','3','4','5','6','7','8','9','A'},
};


std::vector<Cloud*> clouds;
void  TestState::OnEnter()
{
	srand(time(NULL));
	for (int i = 0; i < 4;i++) {
		clouds.push_back(new Cloud(this->window) );
	}
}
void  TestState::OnExit(){}
void  TestState::Update(float elapsed)
{
	for (auto it : clouds)
		it->Update();
}
void  TestState::Render()
{
	this->window->clearWindow({ 244,244,244,255 });
	int cx=0;
	int cy=0;
	
	for (int row=0;row < 10;row++)
	{
		for (int col = 0;col < 10;col++)
		{
			cx += 32;
			if (cx >= window->getW())
			{
				cy += 32;
				cx = 0;
			}
			if (cy >= window->getH())
			{

			}
			switch (tileset[row][col])
			{
		    	case '1':
				{
					this->window->setColor({ 255,0,0,255 });

					break;
				}
				default:
					this->window->setColor({ 255,255,0,255 });

					break;
			}
		}
		
	}

	for (auto it : clouds)
		it->Draw();
}