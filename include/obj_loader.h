#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "face.h"
#include "triangle.h"
#include "vec3.h"

#include <fstream>
#include <sstream>
#include <vector>

class ObjLoader {
public:

    // Reads an OBJ file, adjusts its size, and returns a vector of triangles
    std::vector<triangle> readObj(const std::string& filePath, const vec3 point) const {
        try {
            // Open the OBJ file
            std::ifstream fileReader(filePath); //created a file reader
            if(!fileReader.is_open()) throw std::runtime_error("Error to open the file!"); //check if there were any error to open the file  
            std::string line; //it will store the line of file
            std::vector<vec3> vertices;
            std::vector<vec3> normais;
            std::vector<Face> faces;

            // Iterate through all lines in the file
            while (std::getline(fileReader, line)) {
                std::vector<std::string> tokens;
                if(line != "") {
                    split(line, tokens, ' ');
                    // Parse vertices, normals, and faces from the OBJ file
                    if(tokens[0] == "v") {
                        vertices.push_back(parseVec3(tokens));
                    }else if(tokens[0] == "vn") {
                        normais.push_back(parseVec3(tokens));
                    }else if(tokens[0] == "f") {
                        faces.push_back(parseFace(tokens, vertices));
                    }

                    tokens.clear();
                }
                
            }

            // Resize the object to fit within a normalized bounding box
            resizingObj(vertices);

            // Calculate the center of the object and translate it to the specified point
            vec3 objCenter = calculateObjCenter(vertices);
            vec3 translationDirection = point - objCenter;

            for(auto& vertex : vertices) {
                vertex = vertex + translationDirection;
            }
            
            fileReader.close();
            // Convert faces to triangles and return the result
            return facesToTriangles(faces, vertices, normais);

        }catch(const std::exception& e) {
            std::cerr << "Exceção capturada: " << e.what() << std::endl;
        }
        return std::vector<triangle>();
    }
private:
    // Split a string into tokens using a specified delimiter
    void split(const std::string line, std::vector<std::string>& lineSplit, char delimiter) const {
        std::istringstream stream(line);
        std::string token;
        while(std::getline(stream, token, delimiter)) {
            lineSplit.push_back(token);
        }
    }

    // Convert a split string to a vec3 object representing a vertex or normal in 3D space
    vec3 parseVec3(std::vector<std::string> vertexCoordinates) const {
        vec3 v;
        for(int i = 1; i < vertexCoordinates.size(); ++i) {
            v[i - 1] = std::stod(vertexCoordinates[i]);
        }
        return v;
    }

    // Parse a face from tokens and return a Face object
    Face parseFace(std::vector<std::string> tokens, std::vector<vec3> vertices) const {
        std::vector<std::string> faceTokens;
        int v[3];

        for(int i = 1; i < tokens.size(); ++i) {
            split(tokens[i], faceTokens, '/'); //obter o indice dos vertices
            v[i-1] = std::stoi(faceTokens[0]) - 1;
            faceTokens.clear();
        }
        
        return Face(v[0], v[1], v[2]);
    }

    // Convert a vector of faces, vertices, and normals to a vector of triangles
    std::vector<triangle> facesToTriangles(std::vector<Face> faces, std::vector<vec3> vertices, std::vector<vec3> normais) const {
        std::vector<triangle> triangles;
        for(auto& face : faces) {
            triangle t(vertices[face.v1], vertices[face.v2], vertices[face.v3]);
            t.n0 = normais[face.v1];
            t.n1 = normais[face.v2];
            t.n2 = normais[face.v3];
            triangles.push_back(t);
        }
        return triangles;
    }

    // Resize the object to fit within a normalized bounding box
    void resizingObj(std::vector<vec3>& vertices) const {
        double minX = std::numeric_limits<double>::max();
        double maxX = std::numeric_limits<double>::min();

        double minY = std::numeric_limits<double>::max();
        double maxY = std::numeric_limits<double>::min();

        double minZ = std::numeric_limits<double>::max();
        double maxZ = std::numeric_limits<double>::min();

        // Find the minimum and maximum coordinates of the object
        for(auto vertex: vertices) {
            maxX = std::max(maxX, vertex.x());
            minX = std::min(minX, vertex.x());

            maxY = std::max(maxY, vertex.y());
            minY = std::min(minY, vertex.y());

            maxZ = std::max(maxZ, vertex.z());
            minZ = std::min(minZ, vertex.z());
        }

        // Calculate the biggest difference among the dimensions
        double biggerDif = std::max(std::max(maxX - minX, maxY - minY), maxZ - minZ);

        // Normalize the coordinates
        for(auto& vertex : vertices) {
            vertex[0] = (vertex.x() - minX) / biggerDif;
            vertex[1] = (vertex.y() - minY) / biggerDif;
            vertex[2] = (vertex.z() - minZ) / biggerDif;
        }
    }

    // Calculate the center of the object
    vec3 calculateObjCenter(std::vector<vec3>& vertices) const {
        vec3 center;

        for(auto vertex: vertices) {
            center = center + vertex;
        }

        return center / static_cast<double>(vertices.size());
    }
};



#endif