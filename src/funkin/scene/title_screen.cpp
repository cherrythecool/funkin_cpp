#include "glad/glad.h"
#include <string.h>

#include "core/engine.h"
#include "core/input/input_server.h"

#include "assets/asset_server.h"
#include "core/audio/audio_server.h"

#include "funkin/audio.h"
#include "funkin/scene/title_screen.h"

namespace funkin {
    TitleScreen::TitleScreen() {}

    TitleScreen::~TitleScreen() {
        delete girlfriend;
        crystal::Sparrow::free_frame_names(anim_frames);
    }

    void TitleScreen::on_switch_dispose(void) {}

    void TitleScreen::init(void) {
        girlfriend = new crystal::Sprite(GAME_SIZE.x * 0.5, GAME_SIZE.y * 0.5, crystal::AssetServer::get_texture("assets/images/menus/title_screen/gf.png"));
        girlfriend->origin = glm::dvec2(0.0);
        anim_frames = crystal::Sparrow::load_from_path("assets/images/menus/title_screen/gf.xml");
        girlfriend->source_rect = crystal::Sparrow::get_frame(anim_frames, "gfDance0029").source_rect;
        // the rest of the list should be freed automatically by the stack and shit because this is on the stack :]

        if (Audio::streams.count("MUSIC") == 0) {
            crystal::AudioStreamPlayer *music = new crystal::AudioStreamPlayer();
            music->set_stream(crystal::AssetServer::get_audio_stream("assets/audio/music/freakyMenu.ogg"));
            music->play();
            Audio::streams["MUSIC"] = music;
        }
   }

    void TitleScreen::step(const double delta) {
        anim_timer += delta;
        double anim_delay = 1.0 / double(anim_fps);

        if (anim_timer >= anim_delay) {
            size_t added_frames = size_t(anim_timer / anim_delay);
            anim_timer = 0.0;
            anim_frame = (anim_frame + added_frames) % 30;

            char barnacles[256] = {0};
            sprintf(barnacles, "gfDance%04zd", anim_frame);
            crystal::sparrow_frame frame = crystal::Sparrow::get_frame(anim_frames, barnacles);
            girlfriend->source_rect = frame.source_rect;
            girlfriend->position = glm::dvec2(GAME_SIZE.x * 0.5 - 359.0, 24.0);
            girlfriend->position.x -= frame.offset_rect.x;
            girlfriend->position.y -= frame.offset_rect.y;
        }

        girlfriend->step(delta);
        Audio::step(delta);
    }

    void TitleScreen::draw(void) {
        girlfriend->draw();
    }
}
