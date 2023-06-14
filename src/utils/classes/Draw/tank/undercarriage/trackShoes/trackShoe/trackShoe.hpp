#pragma once
#include "../../../../../shader.hpp"
#include "../../../../../camera/camera.hpp"
#include "../../../../../textures/textures.hpp"


enum class Phases{
    top,
    bottom,
    left,
    right
};

class DrawTrackShoe{
    private:
        unsigned int VBO, VAO;
        unsigned int texture;
        Camera *camera;
        Shader *shader;
        glm::mat4 *modelBody;
        float vibrationAngle;
        bool revertVibration;
        bool fading;
    public:
        float angle;
        Phases phase;
        glm::mat4 model;
        glm::vec3 position;
        
        DrawTrackShoe();
        void Update();
        void Render();
        
        void setVetices();
        void setPosition(Phases phase, float angle , glm::vec3 position);
        void setCamera(Camera *camera);
        void setModel(glm::mat4 *modelBody);
        
        void move(glm::vec3 translate);
        void show();
        void vibration();
};
