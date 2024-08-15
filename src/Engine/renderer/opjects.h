
#define MAX_BONE_INFLUENCE 4

struct vertex
{
    glm::vec3 Pos;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Tangent;
    glm::vec3 Bitangent;
    int m_BoneIDs[MAX_BONE_INFLUENCE];
    float m_Weights[MAX_BONE_INFLUENCE];
};
struct transforms
{
    glm::vec3 Pos;
    glm::vec3 Scale;
    glm::vec3 Rotation;
};
struct texture
{
    unsigned int id;
    std::string path;
};
materials
{
    glm::vec4 value;
    std::vector<texture> textures;
    std::string type;
};
struct opject
{
    std::vector<vertex> mesh;
    transforms Transforms;
    materials Materials;
};
//TODO: MAKE A CLASS FOR ALLOCATE OPJECTS AND DRAW THEM
