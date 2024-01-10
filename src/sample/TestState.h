
#include <Window.h>
#include <GameState.h>


class TestState : public GameState
{
public:
	TestState(Window* w) : GameState(w) {
	}
	virtual void OnEnter();
	virtual void OnExit();
	virtual void Update(float elapsed);
	virtual void Render();

};
