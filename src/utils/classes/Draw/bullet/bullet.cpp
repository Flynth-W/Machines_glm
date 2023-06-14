#include "bullet.hpp"
#include <iostream>

void DrawBullet::Init(){
    this->shader = new Shader("./shader/cube.vs" ,"./shader/cube.fs");
    this->translate=glm::vec3(0.0);
    this->angleHorizontal=0.0f;
    this->angleVertical=0.0f;
    
    //this->model = glm::mat4(1.0);
    //this->model = glm::translate(this->model,this->initialPosition );
    //this->model = glm::rotate(this->model, this->angleHorizontal, glm::vec3(0.0f, 1.0f, 0.0f));
    //this->model = glm::rotate(this->model, this->angleVertical, glm::vec3(1.0f, 0.0f, 0.0f));
    //this->model = glm::translate(this->model,this->translate );
    //
    //this->position= new glm::vec3(this->model[3][0],this->model[3][1],this->model[3][2]);
}
void DrawBullet::Render(){
    this->shader->use();
    //
    //this->model = glm::translate(this->model,this->initialPosition );
    //this->model = glm::rotate(this->model, this->angleHorizontal, glm::vec3(0.0f, 1.0f, 0.0f));
    //this->model = glm::rotate(this->model, this->angleVertical, glm::vec3(1.0f, 0.0f, 0.0f));
    this->model = glm::translate(this->model,this->translate );
    
    //*this->position=glm::vec3(this->model[3][0],this->model[3][1],this->model[3][2]);
    
    this->shader->setMat4("model", this->model);
    this->shader->setMat4("view", *this->camera->view);
    this->shader->setMat4("projection", *this->camera->projection);
    this->shader->setVec3("color", glm::vec3(1.0,1.0,0.0));
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
}


void DrawBullet::setVetices(float *vertex, unsigned int vertexSize){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexSize, vertex, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
void DrawBullet::move(double x, double y){
    this->translate= this->translate + glm::vec3(0.0,0.0,-y);
}
glm::vec3 DrawBullet::getPosition(){
    return *this->position;
} 

void DrawBullet::setPosition(glm::vec3 position){
    this->initialPosition=position;

}
void DrawBullet::rotateVertical(float angle){
    this->angleVertical += angle;
}
void DrawBullet::rotateHorizontal(float angle){
    this->angleHorizontal += angle;
}
void DrawBullet::setCamera(Camera *camera){
    this->camera = camera ;
}
void DrawBullet::setModel(glm::mat4 model){
    this->model =model;
};
