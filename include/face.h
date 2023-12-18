#ifndef FACE_H
#define FACE_H

// Class representing a face in a 3D model
class Face {
public:
    // Indices of the three vertices of the face
    int v1;
    int v2;
    int v3;

    Face() {}

    Face(int v1, int v2, int v3) : v1(v1), v2(v2), v3(v3) {}

};

#endif