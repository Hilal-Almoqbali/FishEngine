#include<TexturesTools.h>
namespcae rose{
    class assets_loader
    {
    public:
        //TODO: CHANGE THE POINTER TO A SHARED POINTER IN CASE OF MULTITHRIDED CASE :/
        opject load_3d_opject(std::string path)
        {

        }
    private:
        opject m_opject;
        std::string m_directory;
    private:
        void loadModel(string const &path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
    };
}


