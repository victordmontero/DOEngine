
GCCPARAMS= -I./includes

WINPARAMS = 
# WINPARAMS = -lwsock32 -lws2_32 -lMingw32 -lSDL2Main

LIBS=-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer


objects = obj/FPSManager.o \
		  obj/Window.o \
		  obj/Event.o \
		  obj/Texture.o \
		  obj/TTFText.o \
		  obj/Geometric.o \
		  obj/UDPPacket.o \
		  obj/Tilemap.o \
		  obj/GameObject.o \
		  obj/BackgroundObject.o \
		  obj/GameStateManager.o \
		  obj/TestState.o \
		  obj/main.o

all: $(objects)
	g++ $(objects) -ogm1 $(WINPARAMS) $(LIBS)

obj/%.o: Network/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<
obj/%.o: Tilemap/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<
obj/%.o: GameObject/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<
obj/%.o: Drawable/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<
obj/%.o: GameState/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<
obj/%.o: Font/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<
obj/%.o: Event/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<

obj/%.o: Timer/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<

obj/%.o: Window/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<
obj/%.o: Texture/%.cpp
	g++ $(GCCPARAMS) -c -o $@ $<
obj/%.o: %.cpp
	g++ $(GCCPARAMS) -c -o $@ $<

clean:
	del $(objects)