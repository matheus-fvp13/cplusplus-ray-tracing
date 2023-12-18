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
    std::vector<triangle> readObj(const std::string& filePath, const vec3 point) const {
        try {
            std::ifstream fileReader(filePath); //cria um leitor de arquivos
            if(!fileReader.is_open()) throw std::runtime_error("Error to open the file!"); //verifica se houve algum erro ao abrir o arquivo
            std::string line; //vai armazenar uma linha do arquivo
            std::vector<vec3> vertices;
            std::vector<vec3> normais;
            std::vector<Face> faces;

            //percorre todas as linhas do arquivo
            while (std::getline(fileReader, line)) {
                std::vector<std::string> tokens;
                if(line != "") {
                    split(line, tokens, ' ');
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

            vec3 objCenter = calculateObjCenter(vertices);
            vec3 translationDirection = point - objCenter;
            translationDirection[2] += -1.5;

            for(auto& vertex : vertices) {
                vertex = vertex + translationDirection;
            }
            
            fileReader.close();
            return facesToTriangles(faces, vertices, normais);

        }catch(const std::exception& e) {
            std::cerr << "Exceção capturada: " << e.what() << std::endl;
        }
        return std::vector<triangle>();
    }
private:
    void split(const std::string line, std::vector<std::string>& lineSplit, char delimiter) const {
        std::istringstream stream(line);
        std::string token;
        while(std::getline(stream, token, delimiter)) {
            lineSplit.push_back(token);
        }
    }

    //convert a split string to a vec3 object with represents a vertex or a normal in a 3D space
    vec3 parseVec3(std::vector<std::string> vertexCoordinates) const {
        vec3 v;
        for(int i = 1; i < vertexCoordinates.size(); ++i) {
            v[i - 1] = std::stod(vertexCoordinates[i]);
        }
        return v;
    }


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

    void resizingObj(std::vector<vec3>& vertices) const {
        double minX = std::numeric_limits<double>::max();
        double maxX = std::numeric_limits<double>::min();

        double minY = std::numeric_limits<double>::max();
        double maxY = std::numeric_limits<double>::min();

        double minZ = std::numeric_limits<double>::max();
        double maxZ = std::numeric_limits<double>::min();

        for(auto vertex: vertices) {
            maxX = std::max(maxX, vertex.x());
            minX = std::min(minX, vertex.x());

            maxY = std::max(maxY, vertex.y());
            minY = std::min(minY, vertex.y());

            maxZ = std::max(maxZ, vertex.z());
            minZ = std::min(minZ, vertex.z());
        }

        double biggerDif = std::max(std::max(maxX - minX, maxY - minY), maxZ - minZ);
        for(auto& vertex : vertices) {
            vertex[0] = (vertex.x() - minX) / biggerDif;
            vertex[1] = (vertex.y() - minY) / biggerDif;
            vertex[2] = (vertex.z() - minZ) / biggerDif;
        }
    }

    vec3 calculateObjCenter(std::vector<vec3>& vertices) const {
        vec3 center;

        for(auto vertex: vertices) {
            center = center + vertex;
        }

        return center / static_cast<double>(vertices.size());
    }
};



#endif