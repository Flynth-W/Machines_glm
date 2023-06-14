#pragma once
#include "../../../shader.hpp"
#include "../../../camera/camera.hpp"
#include "../../../textures/textures.hpp"
#include "./guide/guide.hpp"
#include "./trackShoes/trackShoes.hpp"

class DrawUndercarriage{
    private:
        glm::mat4 *modelBody;
        Camera *camera;
        DrawGuideOfUndercarriage guide;
        DrawTrackShoes trackShoes;
    public:
        glm::vec3 initPosition;
        void Init();
        void Update();
        void Render();
        
        void setPosition(glm::vec3 initPosition);
        void setCamera(Camera *camera);
        void setModel(glm::mat4 *modelBody);
        
        void move(double translate);
        void rotate(double angle);
};
