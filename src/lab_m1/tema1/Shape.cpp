//
// Created by Alexia Stefan on 11.11.2023.
//

#include "Shape.h"

using namespace m1;

Shape::Shape(const string &name, const glm::vec3 &center, float length, const glm::vec3 &color, float z, bool fill)
        : name(name), center(center), length(length), color(color), z(z), fill(fill) {}

const string &Shape::getName() const {
    return name;
}

void Shape::setName(const string &name) {
    Shape::name = name;
}

const glm::vec3 &Shape::getCenter() const {
    return center;
}

void Shape::setCenter(const glm::vec3 &center) {
    Shape::center = center;
}

float Shape::getLength() const {
    return length;
}

void Shape::setLength(float length) {
    Shape::length = length;
}

const glm::vec3 &Shape::getColor() const {
    return color;
}

void Shape::setColor(const glm::vec3 &color) {
    Shape::color = color;
}

float Shape::getZ() const {
    return z;
}

void Shape::setZ(float z) {
    Shape::z = z;
}


bool Shape::isFill() const {
    return fill;
}

void Shape::setFill(bool fill) {
    Shape::fill = fill;
}







