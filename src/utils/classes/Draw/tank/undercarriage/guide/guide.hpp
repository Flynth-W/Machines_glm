#pragma once
#include "../../../../shader.hpp"
#include "../../../../camera/camera.hpp"
#include "../../../../textures/textures.hpp"

class DrawGuideOfUndercarriage{
    private:
        unsigned int VBO, VAO;
        unsigned int texture;
        Camera *camera;
        Shader *shader;
        glm::vec3 position;
        glm::mat4 *modelBody;
    public:
        glm::mat4 model;
        
        DrawGuideOfUndercarriage();
        void Update();
        void Render();
        
        void setVetices();
        void setPosition(glm::vec3 position);
        void setCamera(Camera *camera);
        void setModel(glm::mat4 *modelBody);
        

};
