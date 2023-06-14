#include "guide.hpp"
#include <iostream>

DrawGuideOfUndercarriage::DrawGuideOfUndercarriage(){
    this->model = glm::mat4(1.0);    
}
void DrawGuideOfUndercarriage::Update(){
    glm::mat4 modelTmp = glm::mat4(*this->modelBody);
    modelTmp = glm::translate(modelTmp,this->position );
    this->model = modelTmp;    
}
void DrawGuideOfUndercarriage::Render(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    this->shader->use();
    
    this->shader->setMat4("model", this->model);
    this->shader->setMat4("view", *this->camera->view);
    this->shader->setMat4("projection", *this->camera->projection);
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}


void DrawGuideOfUndercarriage::setVetices(){
    float vertex[] = {
        -0.05f, -0.10f, -0.4f,  0.0f, 0.0f,
         0.05f, -0.10f, -0.4f,  1.0f, 0.0f,
         0.05f,  0.10f, -0.4f,  1.0f, 1.0f,
         0.05f,  0.10f, -0.4f,  1.0f, 1.0f,
        -0.05f,  0.10f, -0.4f,  0.0f, 1.0f,
        -0.05f, -0.10f, -0.4f,  0.0f, 0.0f,

        -0.05f, -0.10f,  0.4f,  0.0f, 0.0f,
         0.05f, -0.10f,  0.4f,  1.0f, 0.0f,
         0.05f,  0.10f,  0.4f,  1.0f, 1.0f,
         0.05f,  0.10f,  0.4f,  1.0f, 1.0f,
        -0.05f,  0.10f,  0.4f,  0.0f, 1.0f,
        -0.05f, -0.10f,  0.4f,  0.0f, 0.0f,

        -0.05f,  0.10f,  0.4f,  1.0f, 0.0f,
        -0.05f,  0.10f, -0.4f,  1.0f, 1.0f,
        -0.05f, -0.10f, -0.4f,  0.0f, 1.0f,
        -0.05f, -0.10f, -0.4f,  0.0f, 1.0f,
        -0.05f, -0.10f,  0.4f,  0.0f, 0.0f,
        -0.05f,  0.10f,  0.4f,  1.0f, 0.0f,

         0.05f,  0.10f,  0.4f,  1.0f, 0.0f,
         0.05f,  0.10f, -0.4f,  1.0f, 1.0f,
         0.05f, -0.10f, -0.4f,  0.0f, 1.0f,
         0.05f, -0.10f, -0.4f,  0.0f, 1.0f,
         0.05f, -0.10f,  0.4f,  0.0f, 0.0f,
         0.05f,  0.10f,  0.4f,  1.0f, 0.0f,

        -0.05f, -0.10f, -0.4f,  0.0f, 1.0f,
         0.05f, -0.10f, -0.4f,  1.0f, 1.0f,
         0.05f, -0.10f,  0.4f,  1.0f, 0.0f,
         0.05f, -0.10f,  0.4f,  1.0f, 0.0f,
        -0.05f, -0.10f,  0.4f,  0.0f, 0.0f,
        -0.05f, -0.10f, -0.4f,  0.0f, 1.0f,

        -0.05f,  0.10f, -0.4f,  0.0f, 1.0f,
         0.05f,  0.10f, -0.4f,  1.0f, 1.0f,
         0.05f,  0.10f,  0.4f,  1.0f, 0.0f,
         0.05f,  0.10f,  0.4f,  1.0f, 0.0f,
        -0.05f,  0.10f,  0.4f,  0.0f, 0.0f,
        -0.05f,  0.10f, -0.4f,  0.0f, 1.0f
    };
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture cords attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    this->texture= Textures::loadTexture("./img/gold.jpg");
    
    this->shader= new Shader("./shader/turtle/turtle.vs" ,"./shader/turtle/turtle.fs");
    this->shader->use();
    this->shader->setInt("texture1", 0);
}

void DrawGuideOfUndercarriage::setPosition(glm::vec3 position){
    this->position = position;
}
void DrawGuideOfUndercarriage::setCamera(Camera *camera){
    this->camera = camera ;
}
void DrawGuideOfUndercarriage::setModel(glm::mat4 *modelBody){
    this->modelBody=modelBody;
}
