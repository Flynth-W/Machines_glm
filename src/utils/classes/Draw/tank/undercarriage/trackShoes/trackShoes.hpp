#pragma once
#include "../../../../shader.hpp"
#include "../../../../camera/camera.hpp"
#include "../../../../textures/textures.hpp"
#include "./trackShoe/trackShoe.hpp"

class DrawTrackShoes{
    private:
        Camera *camera;
        Shader *shader;
        glm::vec3 position;
        glm::mat4 *modelBody;
        DrawTrackShoe trackShoes[26];
        float time;
    public:
        void Init();
        void Update();
        void Render();
        
        void move(float translate);

        void setPosition(glm::vec3 position);
        void setCamera(Camera *camera);
        void setModel(glm::mat4 *modelBody);
        
};
