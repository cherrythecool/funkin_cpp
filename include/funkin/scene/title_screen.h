#pragma once

#include "assets/sparrow.h"

#include "scene/scene.h"
#include "scene/sprite.h"
#include "scene/batched_sprites.h"

namespace funkin {
    class TitleScreen : public crystal::Scene {
        private:
            double anim_timer = 0.0;
            unsigned int anim_fps = 24;
            size_t anim_frame = 0;
            std::list<crystal::sparrow_frame> anim_frames;
        public:
            crystal::Sprite *girlfriend;

            TitleScreen();
            virtual ~TitleScreen();

            virtual void init(void);
            virtual void step(const double delta);
            virtual void draw(void);

            virtual void on_switch_dispose(void);
    };
}