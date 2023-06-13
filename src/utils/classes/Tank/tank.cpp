#include "tank.hpp"
void Tank::events(){
    float translationSpeed = 1.5 * *this->deltaTime;
    float rotationSpeed = 2.0 * *this->deltaTime;

    // up
    if( Event::getIfStateKey(keys, GLFW_KEY_W,ButtonState::Pressed ,ButtonState::Repeat) ){
        this->drawTank.move(translationSpeed);
        // left
        if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
            this->drawTank.rotate(rotationSpeed);
        }
        // right
        if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
            this->drawTank.rotate(-rotationSpeed);
        }
    }
    // down
    if( Event::getIfStateKey(keys, GLFW_KEY_S,ButtonState::Pressed ,ButtonState::Repeat) ){
        this->drawTank.move(-translationSpeed);
        // left
        if( Event::getIfStateKey(keys, GLFW_KEY_A,ButtonState::Pressed ,ButtonState::Repeat) ){
            this->drawTank.rotate(-rotationSpeed);
        }
        // right
        if( Event::getIfStateKey(keys, GLFW_KEY_D,ButtonState::Pressed ,ButtonState::Repeat) ){
            this->drawTank.rotate(rotationSpeed);
        }
    }
}

void Tank::view(){
    glm::mat4 model = this->drawTank.getModel();

    glm::mat4 front = glm::mat4(model);
              front = glm::translate(front, glm::vec3(0.0,1.5,-2.0));
    glm::vec3 cameraFront = glm::vec3(front[3][0],front[3][1],front[3][2]);
    
    glm::mat4 position  = glm::mat4(model);
              position  = glm::translate(position, glm::vec3( 0.0 , 5.0 , 8.0));
    glm::vec3 cameraPos = glm::vec3(position[3][0] , position[3][1] , position[3][2]);

    glm::vec3 cameraUp = glm::vec3(0.0,1.0,0.0);
    *camera->view = glm::lookAt(cameraPos,  cameraFront, cameraUp);
}

void Tank::Init(){
    this->position=glm::vec3(0.0,0.0,0.0);

    this->drawTank.setCamera(this->camera);
    this->drawTank.Init(&this->position);
}
void Tank::Update(){
    this->events();
    this->drawTank.Update();
}
void Tank::Render(){
    this->view();
    this->drawTank.Render();
}

void Tank::setKeys(std::unordered_map<int, ButtonKey> *keys){
    this->keys=keys;
}
void Tank::setDeltaTime(double *deltaTime){
    this->deltaTime=deltaTime;
}
void Tank::setCamera(Camera *camera){
    this->camera=camera;
}

