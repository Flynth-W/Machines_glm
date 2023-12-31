#include "tank.hpp"
void Tank::events(){
    float translationSpeed = 0.5 * *this->deltaTime;
    float rotationSpeed = 0.5 * *this->deltaTime;

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
    // head rotate
    // left
    if( Event::getIfStateKey(keys, GLFW_KEY_J,ButtonState::Pressed ,ButtonState::Repeat) ){
        this->drawTank.headRotate(rotationSpeed);
    }
    // right
    if( Event::getIfStateKey(keys, GLFW_KEY_L,ButtonState::Pressed ,ButtonState::Repeat) ){
        this->drawTank.headRotate(-rotationSpeed);
    }
    // gun rotate
    // left
    if( Event::getIfStateKey(keys, GLFW_KEY_I,ButtonState::Pressed ,ButtonState::Repeat) ){
        this->drawTank.gunRotate(rotationSpeed);
    }
    // right
    if( Event::getIfStateKey(keys, GLFW_KEY_K,ButtonState::Pressed ,ButtonState::Repeat) ){
        this->drawTank.gunRotate(-rotationSpeed);
    }
    //shoot
    if( Event::getIfStateKey(keys, GLFW_KEY_O,ButtonState::Released) ){
        this->drawTank.shootGun();
    }
}

void Tank::view(){


    glm::mat4 model = this->drawTank.getModel();

    glm::mat4 front = glm::mat4(model);
              front = glm::translate(front, glm::vec3(0.0,0,0.0));
    glm::vec3 cameraFront = glm::vec3(front[3][0],front[3][1],front[3][2]);
    
    glm::mat4 position  = glm::mat4(model);
              position  = glm::translate(position, glm::vec3( -3.0 , 1.5 , 2.5));
    glm::vec3 cameraPos = glm::vec3(position[3][0] , position[3][1] , position[3][2]);

    glm::vec3 cameraUp = glm::vec3(0.0,1.0,0.0);
    *camera->view = glm::lookAt(cameraPos,  cameraFront, cameraUp);
}

void Tank::Init(){
    this->position=glm::vec3(0.0,-0.35,0.0);

    this->drawTank.setCamera(this->camera);
    this->drawTank.setDeltaTime(this->deltaTime);
    this->drawTank.Init(&this->position);
    Event::setKey(keys, GLFW_KEY_J);
    Event::setKey(keys, GLFW_KEY_L);
    Event::setKey(keys, GLFW_KEY_I);
    Event::setKey(keys, GLFW_KEY_K);
    Event::setKey(keys, GLFW_KEY_O);
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

