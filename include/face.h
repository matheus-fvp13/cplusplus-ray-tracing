#ifndef FACE_H
#define FACE_H

class Face {
public:
    int v1;
    int v2;
    int v3;

    Face() {}

    Face(int v1, int v2, int v3) : v1(v1), v2(v2), v3(v3) {}

};

#endif