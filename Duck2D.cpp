#include "Duck2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"

Mesh* Duck2D::CreateSquare3(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(length, 0, 0), color),
        VertexFormat(corner + glm::vec3(length, length, 0), color),
        VertexFormat(corner + glm::vec3(0, length, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* Duck2D::CreateTree(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(600, 100, 0), color),
        VertexFormat(corner + glm::vec3(600, 500, 0), color),
        VertexFormat(corner + glm::vec3(700, 500, 0), color),
        VertexFormat(corner + glm::vec3(700, 100, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* Duck2D::CreateGrass1(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner, color),
        VertexFormat(corner + glm::vec3(0, 100, 0), color),
        VertexFormat(corner + glm::vec3(100, 0, 0), color),
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        
        indices.push_back(0);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* Duck2D::CreateGrass2(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, 0), color),
        VertexFormat(corner + glm::vec3(100, 150, 0), color),
        VertexFormat(corner + glm::vec3(100, 0, 0), color),
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {

        indices.push_back(0);
    }

    square->InitFromData(vertices, indices);
    return square;
}


Mesh* Duck2D::CreateSquare2(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(130, 130, 0), color),
        VertexFormat(corner + glm::vec3(130, 150, 0), color),
        VertexFormat(corner + glm::vec3(150, 150, 0), color),
        VertexFormat(corner + glm::vec3(150, 130, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* Duck2D::CreateSquare(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(150, 175, 0), color),
        VertexFormat(corner + glm::vec3(163, 185, 0), color),
        VertexFormat(corner + glm::vec3(178, 173, 0), color),
        VertexFormat(corner + glm::vec3(170, 160, 0), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* Duck2D::CreateCircle(
    const std::string& name,
    glm::vec3 circleOrigin,
    glm::vec3 color,
    float radius,
    bool fill) {
    std::vector<VertexFormat> vertices;
    std::vector<unsigned int> indices;

    
    Mesh* circle = new Mesh(name);
    glm::vec3 center = circleOrigin;

    for (int i = 0; i < 360; i++) {
        float i_rad = i * 3.14159 / 180;
        vertices.push_back(VertexFormat(center + glm::vec3(radius * cos(i_rad), radius * sin(i_rad), 0), color));
    }
    indices.push_back(0);
    for (unsigned short i = 1; i < 360; i++)
        indices.push_back(i);

    if (!fill) {
        circle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(0);
        indices.push_back(2);
    }
    circle->InitFromData(vertices, indices);
    circle->SetDrawMode(GL_TRIANGLE_FAN);
    return circle;
}

Mesh* Duck2D::CreateBody(
    const std::string& name,
    glm::vec3 leftBottomCorner,

    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(40, 100, 0), color),
        VertexFormat(corner + glm::vec3(200, 210, 0), color),
        VertexFormat(corner + glm::vec3(100, 40, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* Duck2D::CreateWingL(
    const std::string& name,
    glm::vec3 leftBottomCorner,

    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(50, 180, 0), color),
        VertexFormat(corner + glm::vec3(140, 150, 0), color),
        VertexFormat(corner + glm::vec3(90, 120, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* Duck2D::CreateWingR(
    const std::string& name,
    glm::vec3 leftBottomCorner,

    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(180, 50, 0), color),
        VertexFormat(corner + glm::vec3(140, 140, 0), color),
        VertexFormat(corner + glm::vec3(110, 90, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* Duck2D::CreateTail(
    const std::string& name,
    glm::vec3 leftBottomCorner,

    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(30, 30, 0), color),
        VertexFormat(corner + glm::vec3(50, 108, 0), color),
        VertexFormat(corner + glm::vec3(110, 52, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}


Mesh* Duck2D::CreateTail2(
    const std::string& name,
    glm::vec3 leftBottomCorner,

    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(20, 50, 0), color),
        VertexFormat(corner + glm::vec3(50, 100, 0), color),
        VertexFormat(corner + glm::vec3(75, 75, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* Duck2D::CreateTail1(
    const std::string& name,
    glm::vec3 leftBottomCorner,

    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(50, 20, 0), color),
        VertexFormat(corner + glm::vec3(100, 50, 0), color),
        VertexFormat(corner + glm::vec3(75, 75, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}


Mesh* Duck2D::CreateBeak(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(200, 220, 0), color),
        VertexFormat(corner + glm::vec3(235, 235, 0), color),
        VertexFormat(corner + glm::vec3(220, 200, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}

Mesh* Duck2D::CreateTrian(
    const std::string& name,
    glm::vec3 leftBottomCorner,

    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(982, 590, 0), color),
        VertexFormat(corner + glm::vec3(1053, 590, 0), color),
        VertexFormat(corner + glm::vec3(1018, 550, 0), color),
    };

    Mesh* triangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        triangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
    }

    triangle->InitFromData(vertices, indices);
    return triangle;
}