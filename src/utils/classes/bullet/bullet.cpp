#include "bullet.hpp"

Bullet::Bullet(){
    float vertexBullet[] = {
        -0.03f, -0.03f, -0.03f,  
         0.03f, -0.03f, -0.03f,  
         0.03f,  0.03f, -0.03f,  
         0.03f,  0.03f, -0.03f,  
        -0.03f,  0.03f, -0.03f,  
        -0.03f, -0.03f, -0.03f, 

        -0.03f, -0.03f,  0.03f,  
         0.03f, -0.03f,  0.03f,  
         0.03f,  0.03f,  0.03f,  
         0.03f,  0.03f,  0.03f,  
        -0.03f,  0.03f,  0.03f,  
        -0.03f, -0.03f,  0.03f, 

        -0.03f,  0.03f,  0.03f,  
        -0.03f,  0.03f, -0.03f,  
        -0.03f, -0.03f, -0.03f,  
        -0.03f, -0.03f, -0.03f,  
        -0.03f, -0.03f,  0.03f,  
        -0.03f,  0.03f,  0.03f, 

         0.03f,  0.03f,  0.03f,  
         0.03f,  0.03f, -0.03f,  
         0.03f, -0.03f, -0.03f,  
         0.03f, -0.03f, -0.03f,  
         0.03f, -0.03f,  0.03f,  
         0.03f,  0.03f,  0.03f, 

        -0.03f, -0.03f, -0.03f,  
         0.03f, -0.03f, -0.03f,  
         0.03f, -0.03f,  0.03f,  
         0.03f, -0.03f,  0.03f,  
        -0.03f, -0.03f,  0.03f,  
        -0.03f, -0.03f, -0.03f, 

        -0.03f,  0.03f, -0.03f,  
         0.03f,  0.03f, -0.03f,  
         0.03f,  0.03f,  0.03f,  
         0.03f,  0.03f,  0.03f,  
        -0.03f,  0.03f,  0.03f,  
        -0.03f,  0.03f, -0.03f,  
    };
    square.setVetices(vertexBullet, sizeof(vertexBullet));
    this->radius=0.05;
}
void Bullet::Init(glm::mat4 model){
    square.setCamera(this->camera);
    square.setModel(model);
    square.Init();
    square.move(0.0,0.05);
    this->position=square.position;
    this->run=true;
}
void Bullet::Update(){
    if( run ){
        float limit=5.0;
        double speed = *deltaTime * 0.00;
        square.move(0.0,0.0);

    }
}
void Bullet::Render(){
    if (run){
        square.Render();
    }
}
void Bullet::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Bullet::setRadius(unsigned int radius){
    this->radius=radius;
}

glm::vec3 Bullet::getPosition(){
    return this->square.getPosition();
}
double Bullet::getRadio(){
    return this->radius;
}
bool Bullet::getRun(){
    return this->run;
}
void Bullet::setCamera(Camera *camera){
    this->camera=camera;
}
