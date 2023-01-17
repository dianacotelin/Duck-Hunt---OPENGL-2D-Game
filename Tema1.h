#pragma once

#include "components/simple_scene.h"

namespace m1
{
    class Tema1 : public gfxc::SimpleScene
    {
    public:
        Tema1();
        ~Tema1();

        void Init() override;

    private:
        void FrameStart() override;
        void StartGame();
        void EndGame();
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        float cx, cy;
        glm::mat3 modelMatrix;
        glm::mat3 wingLMatrix;
        glm::mat3 wingRMatrix;
        glm::mat3 mouseMatrix;
        glm::mat3 heartMatrix;
        glm::mat3 grassMatrix;
        glm::mat3 treeMatrix;

        float translateX, translateY;
        float scaleX, scaleY;
        float angularStep;

        float windowHeight;
        float windowWidth;

        float duckX;
        float duckY;

        float position;

        float angleL;
        float verifL;

        float verifR;
        float angleR;

        float down;
        float right;

        float first;

        float angle;
        float direccion;

        float state;
        float timeAlive;

        float myMouseX;
        float myMouseY;
        float alive;
        float lives;
        float bullets;
        float ducks;
        float speed;
        float score;
        float yInit;

        float red;
        float green;
        float blue;

        std::string colorDuck;

    };
}