# ObjLoader Class Documentation

The `ObjLoader` class is designed to read OBJ files, adjust the size of the loaded object, and return a vector of triangles representing the object. This class is particularly useful in computer graphics applications for loading 3D models.

## Public Member Functions

### `std::vector<triangle> readObj(const std::string& filePath, const vec3 point) const`

- Reads an OBJ file specified by `filePath`.
- Adjusts the size of the loaded object to fit within a normalized bounding box.
- Translates the object to the specified `point`.
- Returns a vector of triangles representing the object.

## Private Member Functions

### `void split(const std::string line, std::vector<std::string>& lineSplit, char delimiter) const`

- Splits a string into tokens using the specified `delimiter`.

### `vec3 parseVec3(std::vector<std::string> vertexCoordinates) const`

- Converts a split string representing vertex or normal coordinates to a `vec3` object.

### `Face parseFace(std::vector<std::string> tokens, std::vector<vec3> vertices) const`

- Parses a face from tokens, obtaining indices of vertices, and returns a `Face` object.

### `std::vector<triangle> facesToTriangles(std::vector<Face> faces, std::vector<vec3> vertices, std::vector<vec3> normals) const`

- Converts a vector of faces, vertices, and normals to a vector of triangles.

### `void resizingObj(std::vector<vec3>& vertices) const`

- Resizes the object to fit within a normalized bounding box.

### `vec3 calculateObjCenter(std::vector<vec3>& vertices) const`

- Calculates the center of the object based on its vertices.
