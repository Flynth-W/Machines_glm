#pragma once

#include "../../shader.hpp"
#include "../../camera/camera.hpp"


class DrawBullet{
    private:
        Shader *shader;
        unsigned int VBO, VAO;
        glm::mat4 model;
        glm::vec3 translate=glm::vec3(0.0);
        glm::vec3 initialPosition;
        Camera *camera;
        float angleHorizontal;
        float angleVertical;
    public:
        glm::vec3 *position;
    public:
        void Init();
        void Render();
        void setVetices(float * vertex , unsigned int vertexSize);
        void setPosition(glm::vec3  position);
        void setCamera(Camera *camera);
        void setModel(glm::mat4 model);
        glm::vec3 getPosition();
        
        void move(double x , double y);
        void rotateHorizontal(float angle);
        void rotateVertical(float angle);
};
