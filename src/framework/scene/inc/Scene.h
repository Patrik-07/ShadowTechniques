#pragma once

#include <vector>

#include "../Grid.h"
#include "SceneObject.h"
#include "../Camera.h"

#include "../../opengl/shader/ShaderProgram.h"

class Scene  {
public:
    std::vector<SceneObject*> objects;
    Grid grid;

    int width, height;
    bool hasFocus;

    explicit Scene(int& w, int& h, Camera* camera) : grid(*camera), camera(camera) {
        hasFocus = true;
        resize(w, h);
    }

    void addSceneObject(SceneObject& sceneObject) {
        objects.push_back(&sceneObject);
    }

    void removeLast()
    {
        objects.pop_back();
    }

    SceneObject* getSceneObject(int idx) {
        return objects[idx];
    }

    void draw(bool isGridActive) {
        camera->updateShader();
        for (SceneObject* object : objects) {
            object->updateShader();
            object->draw();
        }
        if (isGridActive) {
            grid.draw(*camera);
        }
    }

    void resize(int w, int h) {
        width = w; height = h;
        camera->setAspectRatio(w / h);
    }


    void update(float deltaTime, bool updateCamera) {
        if (updateCamera)
            camera->update();
        for (SceneObject* object : objects) {
            object->update(deltaTime);
        }
    }

    Camera* camera;
};