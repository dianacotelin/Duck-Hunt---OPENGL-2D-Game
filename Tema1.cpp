#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/Duck2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
    red = 0;
    green = 0.4;
    blue = 0.2;
}


Tema1::~Tema1()
{
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float triagleSide = 100;
    ducks = 0;
    speed = 1;

    windowHeight = resolution.y;
    windowWidth = resolution.x;
    lives = 3;
    yInit = 0;
    StartGame();
    right = 0;
    angle = 0;
    score = 0;


    string meshName[] = { "duckB", "duckG", "duckR" };
    glm::vec3 meshColors[] = { glm::vec3(0.34, 0.27, 0.1), glm::vec3(0, 0.4, 0.2), glm::vec3(1, 1, 102 / 255) };

    for (int i = 0; i < 3; i++) {
        Mesh* body = Duck2D::CreateBody(meshName[i], corner, meshColors[i], true);
        AddMeshToList(body);
    }

    // Duck
    Mesh* head = Duck2D::CreateCircle("head", corner + glm::vec3(190, 200, 0), glm::vec3(0, 0.4, 0.2),30, true);
    AddMeshToList(head);
    Mesh* eye1 = Duck2D::CreateCircle("eye1", corner + glm::vec3(185, 210, 0), glm::vec3(0, 0, 0), 5, true);
    AddMeshToList(eye1);
    Mesh* eye1w = Duck2D::CreateCircle("eye1w", corner + glm::vec3(185, 210, 0), glm::vec3(1, 1, 1), 7, true);
    AddMeshToList(eye1w);
    Mesh* wing_right = Duck2D::CreateWingR("wing_right", corner, glm::vec3(0, 0.4, 0.2), true);
    AddMeshToList(wing_right);
    Mesh* wing_left = Duck2D::CreateWingL("wing_left", corner, glm::vec3(0, 0.4, 0.2), true);
    AddMeshToList(wing_left);
    Mesh* tail = Duck2D::CreateTail("tail", corner, glm::vec3(1, 1, 1), true);
    AddMeshToList(tail);
    Mesh* tail1 = Duck2D::CreateTail1("tail1", corner, glm::vec3(0.34, 0.27, 0.1), true);
    AddMeshToList(tail1);
    Mesh* tail2 = Duck2D::CreateTail2("tail2", corner, glm::vec3(0.34, 0.27, 0.1), true);
    AddMeshToList(tail2);
    Mesh* beak = Duck2D::CreateBeak("beak", corner, glm::vec3(1, 1, 102/255), true);
    AddMeshToList(beak);
    Mesh* rectangl = Duck2D::CreateSquare("rectangl", corner, glm::vec3(1, 1, 1), true);
    AddMeshToList(rectangl);
    Mesh* center = Duck2D::CreateSquare2("center", corner, glm::vec3(0.4, 0.6, 0), true);
    AddMeshToList(center);
    Mesh* mouse = Duck2D::CreateSquare3("mouse", corner, 10, glm::vec3(0.6, 0, 0.4), true);
    AddMeshToList(mouse);


    // Hearts 
    Mesh* heart1L = Duck2D::CreateCircle("heart1L", corner + glm::vec3(1000, 600, 0), glm::vec3(1, 0.58, 0.9), 20, true);
    AddMeshToList(heart1L);
    Mesh* heart1R = Duck2D::CreateCircle("heart1R", corner + glm::vec3(1035, 600, 0), glm::vec3(1, 0.58, 0.9), 20, true);
    AddMeshToList(heart1R);
    Mesh* heart1 = Duck2D::CreateTrian("heart1", corner, glm::vec3(1, 0.58, 0.9), true);
    AddMeshToList(heart1);

    Mesh* heart2L = Duck2D::CreateCircle("heart2L", corner + glm::vec3(1000, 600, 0) + glm::vec3(100, 0, 0), glm::vec3(1, 0.58, 0.9), 20, true);
    AddMeshToList(heart2L);
    Mesh* heart2R = Duck2D::CreateCircle("heart2R", corner + glm::vec3(1035, 600, 0) + glm::vec3(100, 0, 0), glm::vec3(1, 0.58, 0.9), 20, true);
    AddMeshToList(heart2R);
    Mesh* heart2 = Duck2D::CreateTrian("heart2", corner + glm::vec3(100, 0, 0), glm::vec3(1, 0.58, 0.9), true);
    AddMeshToList(heart2);

    Mesh* heart3L = Duck2D::CreateCircle("heart3L", corner + glm::vec3(1000, 600, 0) + glm::vec3(200, 0, 0), glm::vec3(1, 0.58, 0.9), 20, true);
    AddMeshToList(heart3L);
    Mesh* heart3R = Duck2D::CreateCircle("heart3R", corner + glm::vec3(1035, 600, 0) + glm::vec3(200, 0, 0), glm::vec3(1, 0.58, 0.9), 20, true);
    AddMeshToList(heart3R);
    Mesh* heart3 = Duck2D::CreateTrian("heart3", corner + glm::vec3(200, 0, 0), glm::vec3(1, 0.58, 0.9), true);
    AddMeshToList(heart3);

    // Bullets
    Mesh* bullet1 = Duck2D::CreateSquare3("bullet1", corner + glm::vec3(1000, 500, 0), 40, glm::vec3(0, 0.9, 0.4), true);
    AddMeshToList(bullet1);
    Mesh* bullet2 = Duck2D::CreateSquare3("bullet2", corner + glm::vec3(1100, 500, 0), 40, glm::vec3(0, 0.9, 0.4), true);
    AddMeshToList(bullet2);
    Mesh* bullet3 = Duck2D::CreateSquare3("bullet3", corner + glm::vec3(1200, 500, 0), 40, glm::vec3(0, 0.9, 0.4), true);
    AddMeshToList(bullet3);

    // Score
    Mesh* score1 = Duck2D::CreateSquare3("score1", corner + glm::vec3(900, 650, 0), 50, glm::vec3(0.9, 0, 0.4), true);
    AddMeshToList(score1);

    // Tree
    Mesh* tree = Duck2D::CreateTree("tree", corner, 50, glm::vec3(0.34, 0.27, 0.14), true);
    AddMeshToList(tree);
    Mesh* treeCircle = Duck2D::CreateCircle("circle1", corner + glm::vec3(600, 400, 0), glm::vec3(0.4, 0.8, 0.5), 60, true);
    AddMeshToList(treeCircle);
    Mesh* treeCircle2 = Duck2D::CreateCircle("circle2", corner + glm::vec3(550, 450, 0), glm::vec3(0.4, 0.7, 0.1), 60, true);
    AddMeshToList(treeCircle2);
    Mesh* treeCircle3 = Duck2D::CreateCircle("circle3", corner + glm::vec3(600, 500, 0), glm::vec3(0.4, 0.8, 0.5), 60, true);
    AddMeshToList(treeCircle3);
    Mesh* treeCircle4 = Duck2D::CreateCircle("circle4", corner + glm::vec3(680, 525, 0), glm::vec3(0.4, 0.7, 0.1), 60, true);
    AddMeshToList(treeCircle4);
    Mesh* treeCircle5 = Duck2D::CreateCircle("circle5", corner + glm::vec3(750, 450, 0), glm::vec3(0.4, 0.8, 0.5), 60, true);
    AddMeshToList(treeCircle5);
    Mesh* treeCircle6 = Duck2D::CreateCircle("circle6", corner + glm::vec3(700, 400, 0), glm::vec3(0.4, 0.7, 0.1), 60, true);
    AddMeshToList(treeCircle6);
    Mesh* treeCircle7 = Duck2D::CreateCircle("circle7", corner + glm::vec3(650, 450, 0), glm::vec3(0.4, 0.8, 0.5), 50, true);
    AddMeshToList(treeCircle7);
    Mesh* grass1 = Duck2D::CreateGrass1("grass1", corner, 50, glm::vec3(0.1, 0.6, 0), true);
    AddMeshToList(grass1);
    Mesh* grass2 = Duck2D::CreateGrass2("grass2", corner, 50, glm::vec3(0.1, 0.8, 0.3), true);
    AddMeshToList(grass2);

    //clouds
    Mesh* cloud1 = Duck2D::CreateCircle("cloud1", corner + glm::vec3(400, 610, 0), glm::vec3(1, 1, 1), 30, true);
    AddMeshToList(cloud1);
    Mesh* cloud2 = Duck2D::CreateCircle("cloud2", corner + glm::vec3(400, 575, 0), glm::vec3(1, 1, 1), 30, true);
    AddMeshToList(cloud2);
    Mesh* cloud3 = Duck2D::CreateCircle("cloud3", corner + glm::vec3(370, 590, 0), glm::vec3(1, 1, 1), 30, true);
    AddMeshToList(cloud3);
    Mesh* cloud4 = Duck2D::CreateCircle("cloud4", corner + glm::vec3(430, 590, 0), glm::vec3(1, 1, 1), 30, true);
    AddMeshToList(cloud4);
}

void Tema1::StartGame() {
    duckX = 100;
    duckY = 100;

    angleL = 0;
    angleR = 0;

    translateX = 0;
    translateY = 0;

    scaleX = 1;
    scaleY = 1;

    angularStep = 0;
    verifL = 0;
    verifR = 0;

    down = 0;
    right = 0;
 
    if (rand() % 2 == 0) {
        angle = 0;
        right = 0;
    }
    else {
        angle = - 1.57;
        right = 1;
    }
    
    duckX = (rand() % 7 + 2) * 100;
    
    state = 1;
    timeAlive = 0;
    myMouseX = 0;
    myMouseY = 0;
    alive = 1;
    bullets = 3;
    ducks++;
    if ((int)ducks % 3 == 0) {
        speed += 50;
    }

    colorDuck = "duck";
    float random = rand() % 3;
    if (random == 0) {
        colorDuck.append("B");
    }
    if (random == 1) {
        colorDuck.append("G");
    }
    if (random == 2) {
        colorDuck.append("R");
    }
    

}

void Tema1::FrameStart()
{
    // Se modifica fundalul ecranului
    if (state == 2) {
        glClearColor(1, 1, 0.8, 0.5);
    }
    else if (state == 1) {
        glClearColor(0.4, 0.7, 1, 0.5);
    }
    else {
        glClearColor(1, 0.6, 0.5, 1);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}


void Tema1::Update(float deltaTimeSeconds)
{
    glm::ivec2 resolution = window->GetResolution();


    modelMatrix = glm::mat3(1);
    wingLMatrix = glm::mat3(1);
    wingRMatrix = glm::mat3(1);
    mouseMatrix = glm::mat3(1);
    heartMatrix = glm::mat3(1);
    grassMatrix = glm::mat3(1);


    timeAlive += deltaTimeSeconds;

    
    // vieti

    if (lives >= 3) {
        RenderMesh2D(meshes["heart1L"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["heart1R"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["heart1"], shaders["VertexColor"], heartMatrix);
    }

    if (lives >= 2) {
        RenderMesh2D(meshes["heart2L"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["heart2R"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["heart2"], shaders["VertexColor"], heartMatrix);
    }

    if (lives >= 1) {
        RenderMesh2D(meshes["heart3L"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["heart3R"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["heart3"], shaders["VertexColor"], heartMatrix);
    }

    // scapa rata
    if (timeAlive > 5) {
        state = 2;
        lives--;
    }
    
    // gloante
    if (bullets == 3) {
        RenderMesh2D(meshes["bullet1"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["bullet3"], shaders["VertexColor"], heartMatrix);
    }

    if (bullets == 2) {
        RenderMesh2D(meshes["bullet2"], shaders["VertexColor"], heartMatrix);
        RenderMesh2D(meshes["bullet3"], shaders["VertexColor"], heartMatrix);
    }

    if (bullets == 1) {
        RenderMesh2D(meshes["bullet3"], shaders["VertexColor"], heartMatrix);
    }

    if (bullets == 0) {
        timeAlive = 5;
    }

    if (lives == 0) {
        score = 0;
        lives = 3;
        speed = 1;
    }

    // bara scor
    for (int i = 0; i < score && score < 17; i++) {
        heartMatrix = glm::mat3(1);
        heartMatrix *= transform2D::Translate(i*20, 0);
        RenderMesh2D(meshes["score1"], shaders["VertexColor"], heartMatrix);
    }
    // scor maxim
    if (score == 16) {
        score = 0;
        lives = 3;
        speed = 1;
    }
    
    // se afiseaza mouse-ul
    mouseMatrix *= transform2D::Translate(0, 0);
    mouseMatrix *= transform2D::Translate(myMouseX, myMouseY);
    RenderMesh2D(meshes["mouse"], shaders["VertexColor"], mouseMatrix);
    
    // Se verifica coliziuni si se schimba directia si unghiul 
    if (state == 1) {
        if (duckX >= (resolution.x - 150)) {
            if (down == 0) {
                right = 1;
                angle -= 1.575;
            }
            else {
                right = 1;
                angle += 1.575;
                
            }
        } else if (duckY >= (resolution.y - 250)) {
            if (right == 0) {
                angle = 1.575;
            }
            else {
                angle = 3.14;
            }
            down = 1;
        } else if (duckY < 100) {
            if (right == 0) {
                angle -= 1.575;
            }
            else {
                angle += 1.575;
            }
            down = 0;

        } else if (duckX < 100) {
            if (down == 0) {
                right = 0;
                angle += 1.575;
                
            }
            else {
                right = 0;
                angle -= 1.575;
                
            }
            
        }

        // cum se misca rata pe x si y in functie de directia pe care merge
        if (down == 0) {
            duckY += deltaTimeSeconds * (200 + speed);
        }
        if (down == 1) {
            duckY -= deltaTimeSeconds * (200 + speed);
        }
        if (right == 0) {
            duckX += deltaTimeSeconds * (200 + speed);
        }
        if (right == 1) {
            duckX -= deltaTimeSeconds * (200 + speed);
        }
    }


    // rata scapa
    if (state == 2) {
        angle = -0.75;
        duckY += deltaTimeSeconds * (200 + speed);
        timeAlive = 0;
        if (duckY >= resolution.y - 150) {
            StartGame();
        }
    }

    // rata e moarta
    if (state == 3) {
        angle = 2.35;
        duckY -= deltaTimeSeconds * (200 + speed);
        if (duckY <= 0) {
            score++;
            StartGame();
        } 

    }
    

    // Se roteste si se muta toata rata
    modelMatrix *= transform2D::Translate(duckX, duckY);
    wingLMatrix *= transform2D::Translate(duckX, duckY);
    wingRMatrix *= transform2D::Translate(duckX, duckY);

    modelMatrix *= transform2D::Rotate(angle);
    wingLMatrix *= transform2D::Rotate(angle);
    wingRMatrix *= transform2D::Rotate(angle);

    //se seteaza un interval pentru aripi intre 0 si 0.4 radiani si se roteste aripa stanga
    if  (verifL == 0) {
        angleL -= 0.015;
    }

    if (angleL <= -0.4) {
        verifL = 1;
    }

    if (verifL == 1) {
        angleL += 0.015;
    }

    if (angleL >= 0) {
        verifL = 0;
    }
    wingLMatrix *= transform2D::Translate(90, 170);
    wingLMatrix *= transform2D::Rotate(angleL);
    wingLMatrix *= transform2D::Translate(-90, -170);
    

    // la fel
    if (verifR == 0) {
        angleR += 0.015;
    }

    if (angleR >= 0.4) {
        verifR = 1;
    }

    if (verifR == 1) {
        angleR -= 0.015;
    }

    if (angleR <= 0) {
        verifR = 0;
    }

    // se roteste aripa dreapta 
    wingRMatrix *= transform2D::Translate(170, 90);
    wingRMatrix *= transform2D::Rotate(angleR);
    wingRMatrix *= transform2D::Translate(-170, -90);

    // iarba
    for (int i = 0; i < resolution.x; i+=50) {
        grassMatrix = glm::mat3(1);
        grassMatrix *= transform2D::Translate(i, 0);
        RenderMesh2D(meshes["grass1"], shaders["VertexColor"], grassMatrix);
    }

    // rata

    
    

    RenderMesh2D(meshes["rectangl"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["eye1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["eye1w"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["head"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes[colorDuck], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["beak"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["wing_left"], shaders["VertexColor"], wingLMatrix);
    RenderMesh2D(meshes["wing_right"], shaders["VertexColor"], wingRMatrix);
    RenderMesh2D(meshes["tail1"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["tail2"], shaders["VertexColor"], modelMatrix);
    RenderMesh2D(meshes["tail"], shaders["VertexColor"], modelMatrix);

    
    // copac
    treeMatrix = glm::mat3(1);
    treeMatrix *= transform2D::Translate(-500, -50);
    RenderMesh2D(meshes["circle2"], shaders["VertexColor"], treeMatrix);
    RenderMesh2D(meshes["circle6"], shaders["VertexColor"], treeMatrix);
    RenderMesh2D(meshes["circle4"], shaders["VertexColor"], treeMatrix);
    RenderMesh2D(meshes["circle7"], shaders["VertexColor"], treeMatrix);
    RenderMesh2D(meshes["circle1"], shaders["VertexColor"], treeMatrix); 
    RenderMesh2D(meshes["circle3"], shaders["VertexColor"], treeMatrix);
    RenderMesh2D(meshes["circle5"], shaders["VertexColor"], treeMatrix);
    RenderMesh2D(meshes["tree"], shaders["VertexColor"], treeMatrix);

    
    // iarba

    for (int i = -25; i < resolution.x; i += 50) {
        grassMatrix = glm::mat3(1);
        grassMatrix *= transform2D::Translate(i, 0);
        RenderMesh2D(meshes["grass2"], shaders["VertexColor"], grassMatrix);
    }

    // norisori

    heartMatrix = glm::mat3(1);
    RenderMesh2D(meshes["cloud1"], shaders["VertexColor"], heartMatrix);
    RenderMesh2D(meshes["cloud2"], shaders["VertexColor"], heartMatrix);
    RenderMesh2D(meshes["cloud3"], shaders["VertexColor"], heartMatrix);
    RenderMesh2D(meshes["cloud4"], shaders["VertexColor"], heartMatrix);

    heartMatrix *= transform2D::Translate(300, 0);
    RenderMesh2D(meshes["cloud1"], shaders["VertexColor"], heartMatrix);
    RenderMesh2D(meshes["cloud2"], shaders["VertexColor"], heartMatrix);
    RenderMesh2D(meshes["cloud3"], shaders["VertexColor"], heartMatrix);
    RenderMesh2D(meshes["cloud4"], shaders["VertexColor"], heartMatrix);
   
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    glm::ivec2 resolution = window->GetResolution();
    myMouseX = mouseX;
    myMouseY = resolution.y - mouseY;
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    glm::ivec2 resolution = window->GetResolution();
  
    if (state == 1) {
        // Se incadreaza rata intr-un patrat si se verifica cum este mouse-ul fata de acel patrat
        if ((down == 0) && (right == 0)) {
            if ((duckX - 50 < mouseX) && (200 + duckX > mouseX) && (duckY - 50 < resolution.y - mouseY) && (duckY + 200 > resolution.y - mouseY)) {
                state = 3;
            }
        }
        if ((down == 1) && (right == 0)) {
            if ((duckX - 50 < mouseX) && (200 + duckX > mouseX) && (duckY - 200 < resolution.y - mouseY) && (duckY + 50 > resolution.y - mouseY)) {
                state = 3;
            }
        }
        if ((right == 1) && (down == 0)) {
            if ((duckX + 50 > mouseX) && (duckX - 200 < mouseX) && (duckY - 50 < resolution.y - mouseY) && (duckY + 200 > resolution.y - mouseY)) {
                state = 3;
            }

        }
        if ((right == 1) && (down == 1)) {
            if ((duckX + 50 > mouseX) && (duckX - 200 < mouseX) && (duckY - 200 < resolution.y - mouseY) && (duckY + 50 > resolution.y - mouseY)) {
                state = 3;
            }

        }
    }
        if (state != 3) {
            bullets--;
        }
        
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}