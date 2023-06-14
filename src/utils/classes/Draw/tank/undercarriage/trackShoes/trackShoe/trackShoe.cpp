#include "trackShoe.hpp"
#include <iostream>

DrawTrackShoe::DrawTrackShoe(){
    this->model = glm::mat4(1.0);   
    this->angle = glm::radians(90.0);
    this->vibrationAngle= 0.0;
    this->phase=Phases::top;
    this->revertVibration=false;
    this->fading=true;
}
void DrawTrackShoe::Update(){
    this->vibration();
    glm::mat4 modelTmp = glm::mat4(*this->modelBody);
    modelTmp = glm::translate(modelTmp,this->position );
    float rot = this->angle - glm::radians(90.0);
    modelTmp = glm::rotate(modelTmp, rot, glm::vec3(-1.0,0.0,0.0) );
    modelTmp = glm::rotate(modelTmp, 0.05f, glm::vec3(0.0,1.0,0.0) );
    modelTmp = glm::rotate(modelTmp, this->vibrationAngle, glm::vec3(0.0,0.0,1.0) );
    this->model = modelTmp;   

}
void DrawTrackShoe::Render(){
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


void DrawTrackShoe::setVetices(){
    float vertex[] = {
        -0.064f, -0.01f, -0.04f,  0.0f, 0.0f,
         0.064f, -0.01f, -0.04f,  1.0f, 0.0f,
         0.064f,  0.01f, -0.04f,  1.0f, 1.0f,
         0.064f,  0.01f, -0.04f,  1.0f, 1.0f,
        -0.064f,  0.01f, -0.04f,  0.0f, 1.0f,
        -0.064f, -0.01f, -0.04f,  0.0f, 0.0f,

        -0.064f, -0.01f,  0.04f,  0.0f, 0.0f,
         0.064f, -0.01f,  0.04f,  1.0f, 0.0f,
         0.064f,  0.01f,  0.04f,  1.0f, 1.0f,
         0.064f,  0.01f,  0.04f,  1.0f, 1.0f,
        -0.064f,  0.01f,  0.04f,  0.0f, 1.0f,
        -0.064f, -0.01f,  0.04f,  0.0f, 0.0f,

        -0.064f,  0.01f,  0.04f,  1.0f, 0.0f,
        -0.064f,  0.01f, -0.04f,  1.0f, 1.0f,
        -0.064f, -0.01f, -0.04f,  0.0f, 1.0f,
        -0.064f, -0.01f, -0.04f,  0.0f, 1.0f,
        -0.064f, -0.01f,  0.04f,  0.0f, 0.0f,
        -0.064f,  0.01f,  0.04f,  1.0f, 0.0f,

         0.064f,  0.01f,  0.04f,  1.0f, 0.0f,
         0.064f,  0.01f, -0.04f,  1.0f, 1.0f,
         0.064f, -0.01f, -0.04f,  0.0f, 1.0f,
         0.064f, -0.01f, -0.04f,  0.0f, 1.0f,
         0.064f, -0.01f,  0.04f,  0.0f, 0.0f,
         0.064f,  0.01f,  0.04f,  1.0f, 0.0f,

        -0.064f, -0.01f, -0.04f,  0.0f, 1.0f,
         0.064f, -0.01f, -0.04f,  1.0f, 1.0f,
         0.064f, -0.01f,  0.04f,  1.0f, 0.0f,
         0.064f, -0.01f,  0.04f,  1.0f, 0.0f,
        -0.064f, -0.01f,  0.04f,  0.0f, 0.0f,
        -0.064f, -0.01f, -0.04f,  0.0f, 1.0f,

        -0.064f,  0.01f, -0.04f,  0.0f, 1.0f,
         0.064f,  0.01f, -0.04f,  1.0f, 1.0f,
         0.064f,  0.01f,  0.04f,  1.0f, 0.0f,
         0.064f,  0.01f,  0.04f,  1.0f, 0.0f,
        -0.064f,  0.01f,  0.04f,  0.0f, 0.0f,
        -0.064f,  0.01f, -0.04f,  0.0f, 1.0f
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

    this->texture= Textures::loadTexture("./img/dark.png");
    
    this->shader= new Shader("./shader/turtle/turtle.vs" ,"./shader/turtle/turtle.fs");
    this->shader->use();
    this->shader->setInt("texture1", 0);
}

void DrawTrackShoe::move(glm::vec3 translate){
    
    switch(this->phase){
        case Phases::top:
            if( -0.35 < this->position.z  && this->position.z < 0.35 ){
                this->position.z -= translate.z; 
            }else{
                if( this->position.z < -0.35 ){
                    this->phase=Phases::left;
                    this->angle=glm::radians(90.0);
                }
                if( this->position.z > 0.35 ){
                    this->phase=Phases::right;
                    this->angle=glm::radians(450.0);
                }
            }
            break;
        case Phases::bottom:
            if( -0.35 < this->position.z  && this->position.z < 0.35){
                this->position.z += translate.z; 
            }else{
                if( this->position.z > 0.35 ){
                    this->phase=Phases::right;
                    this->angle=glm::radians(270.1);
                }else{
                    this->phase=Phases::left;
                    this->angle=glm::radians(269.9);
                }
            }
            break;
        case Phases::left:
            if( glm::radians(90.0) <= angle && angle <= glm::radians(270.0) ){
                float radio=0.14;
                double S_arco= translate.z ;
                float angulo=S_arco / radio ;
                this->angle += angulo;
                this->position.y = ( glm::sin(angle) * radio )  ;
                this->position.z = ( glm::cos(angle) * radio )  -0.35 ;
            }else{
                if(this->angle > glm::radians(270.0)){
                    this->phase=Phases::bottom;
                    this->angle=glm::radians(270.0);
                }
                if(this->angle < glm::radians(90.0)){
                    this->phase=Phases::top;
                    this->angle=glm::radians(90.0);
                }
            }
            break;
        case Phases::right:
            if( glm::radians(270.0) <= angle && angle <= glm::radians(450.0) ){
                float radio=0.14;
                double S_arco= translate.z ;
                float angulo=S_arco / radio ;
                this->angle += angulo;
                this->position.y = ( glm::sin(angle) * radio )  ;
                this->position.z = ( glm::cos(angle) * radio )  + 0.35 ;
            }else{
                if(this->angle > glm::radians(450.0)){
                    this->phase=Phases::top;
                    this->angle=glm::radians(450.0);
                }
                if(this->angle < glm::radians(270.0)){
                    this->phase=Phases::bottom;
                    this->angle=glm::radians(270.0);
                }
            }
            break;
    }
    
}

void DrawTrackShoe::setPosition(Phases phase, float angle, glm::vec3 position){
    this->phase=phase;
    this->angle=angle;
    this->position = position;
    this->vibrationAngle = position.z /10  ;
    if(  position.z   > 0.2 ){
        this->revertVibration=true;
        this->fading=false;
    }
    
}
void DrawTrackShoe::setCamera(Camera *camera){
    this->camera = camera ;
}
void DrawTrackShoe::setModel(glm::mat4 *modelBody){
    this->modelBody=modelBody;
}

void DrawTrackShoe::show(){
    std::string fase;
    switch(this->phase){
        case Phases::top:
            fase ="top";
            break;
        case Phases::bottom:
            fase ="bottom";
            break;
        case Phases::left:
            fase ="left";
            break;
        case Phases::right:
            fase ="right";
            break;
    }

    std::cout <<fase << " :: "<< angle<< " :: " << position.y << " :: " <<position.z <<std::endl; 
}

void DrawTrackShoe::vibration(){
    float limit=0.03;

    if(this->phase != Phases::bottom){
        if(revertVibration){
            if(this->vibrationAngle < limit){
                this->vibrationAngle +=0.002;
            }else{ this->revertVibration=!this->revertVibration; }
        }else{
            if(this->vibrationAngle > -limit){
                this->vibrationAngle -=0.002;
            }else{ this->revertVibration=!this->revertVibration; }
        }
        
        float fadi =0.002;
        if(this->fading){
            this->position.y +=fadi;
        }else{
            this->position.y -=fadi;
        }
        this->fading=!this->fading;

    }

}
