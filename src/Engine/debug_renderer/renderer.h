//TODO: headers

namespce rose
{
    struct Opject
    {
        int ID;
        std::string name;
        Model model;
        bool ignore = false;
    };
    struct Renderer_Args
    {
        std::vector<Opject> seen;
        std::vector<Camera> camera;
        std::vector<TexCam> texture_camera;
    }
    class Renderer
    {
    public:
        Renderer();
        void add_seen(std::vector<Opject> seen);
        void add_opject_to_the_seen(int ID,std::string name, Model model);
        void rm_opject_by_id(int ID);
        void rm_opject_by_name(std::string name);
        void rm_seen();
        void ignore_by_id_status(int ID ,bool ignore);
        void ignore_by_name_status(std::string name,bool ignore);
        void add_camera(int ID, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
        void make_camera_current(int ID);
        void add_texture_camera(unsigned int *texture,glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
        void draw();
        int command(std::function<int(Renderer_Args)> Fn)
        ~Renderer()=defult;
    private:
        struct TexCam
        {
            Camera camera;
            unsigned int *texture;
        };
        std::vector<Opject> m_seen;
        std::vector<Camera> m_camera;
        std::vector<TexCam> m_texture_camera; //TODO:add a texture_camera class insted of the normal camera class.
    };
}
