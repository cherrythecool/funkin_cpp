#include <cstdlib>

#include "crystal/core/engine.h"
#include "crystal/scene/startup_scene.h"

#include "funkin/scene/title_screen.h"
#include "funkin/debug/console_debug_info.h"

int main(void) {
    crystal::init_arguments arguments = {
        glm::uvec2(1280, 720),
        (char*)"Friday Night Funkin'",
        0,
        crystal::VSyncMode::OFF,
        crystal::Color(0.0, 0.0, 0.0),
        new crystal::StartupScene(new funkin::TitleScreen()),
    };

    crystal::Engine::init(arguments);
    crystal::Engine::current_debug_info = new funkin::ConsoleDebugInfo();
    crystal::RenderingServer::get_primary_window()->set_icon("assets/images/icon.png");

    while (!crystal::Engine::get_should_close()) {
        crystal::Engine::step();
        crystal::Engine::draw();
    }

    crystal::Engine::dispose();

    return EXIT_SUCCESS;
}
