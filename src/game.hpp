#include "pipe.hpp"
#include "window.hpp"
#include "renderer.hpp"
#include "player.hpp"

class Game {
public:
    Game();
    void Loop();
    void Update(Keyboard &keyboard, double delta_time);
    void Render();
private:
    Window window;
    Renderer renderer;
    Keyboard keyboard;
    Player player;
    PipeManager pipe_manager;
    bool looping;
};
