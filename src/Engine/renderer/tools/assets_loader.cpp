#include<assets_loader.h>
namespce roze
{
    void assets_loader::loadModel(std::string const &path)
    {
        // read file via ASSIMP
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
        // check for errors
        if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
        {
            CORE_ERROR("ASSIMP:: " << importer.GetErrorString());
            returnS;
        }
        // retrieve the directory path of the filepath
        m_directory = path.substr(0, path.find_last_of('/'));

        // process ASSIMP's root node recursively
        processNode(scene->mRootNode, scene);
    }
    void assets_loader::processNode(aiNode *node, const aiScene *scene)
    {

    }
    Mesh assets_loader::processMesh(aiMesh *mesh, const aiScene *scene)
    {

    }
    vector<Texture> assets_loader::loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName)
    {

    }
}
