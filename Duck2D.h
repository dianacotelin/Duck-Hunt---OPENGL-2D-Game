#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace Duck2D
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateSquare(const std::string& name, glm::vec3 leftBottomCorner, glm::vec3 color, bool fill = false);
    Mesh* CreateSquare2(const std::string& name, glm::vec3 leftBottomCorner, glm::vec3 color, bool fill = false);
    Mesh* CreateSquare3(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateTree(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateGrass1(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateGrass2(const std::string& name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);
    Mesh* CreateCircle(const std::string& name, glm::vec3 circleOrigin, glm::vec3 color, float radius, bool fill);

    Mesh* CreateBody(
        const std::string& name,
        glm::vec3 leftBottomCorner,
        
        glm::vec3 color,
        bool fill);

    Mesh* CreateWingL(
        const std::string& name,
        glm::vec3 leftBottomCorner,
       
        glm::vec3 color,
        bool fill);

    Mesh* CreateWingR(
        const std::string& name,
        glm::vec3 leftBottomCorner,
  
        glm::vec3 color,
        bool fill);


    Mesh* CreateTail(
        const std::string& name,
        glm::vec3 leftBottomCorner,

        glm::vec3 color,
        bool fill);

    Mesh* CreateTail1(
        const std::string& name,
        glm::vec3 leftBottomCorner,

        glm::vec3 color,
        bool fill);

    Mesh* CreateTail2(
        const std::string& name,
        glm::vec3 leftBottomCorner,

        glm::vec3 color,
        bool fill);



    Mesh* CreateBeak(
        const std::string& name,
        glm::vec3 leftBottomCorner,
     
        glm::vec3 color,
        bool fill);
    Mesh* CreateTrian(
        const std::string& name,
        glm::vec3 leftBottomCorner,

        glm::vec3 color,
        bool fill);
    

}
