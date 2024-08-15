#include<renderer.h>

namespce rose
{
        std::vector<Opject> Renderer::m_seen;
        std::vector<Camera> Renderer::m_camera;
        std::vector<TexCam> Renderer::m_texture_camera;

        void Renderer::add_seen(std::vector<Opject> seen)
        {
            m_seen = seen;
        }
        void Renderer::add_opject_to_the_seen(int ID,std::string name, Model model)
        {//INFO: {opject id , opject name , the opject model , should it be ignored}
            m_seen.pull_back({ID,name,model,false});
        }
        void Renderer::rm_opject_by_id(int ID)
        {
            for(int i=0;i<m_seen.size();i++)
            {
                if(m_seen.at(i).ID == ID)
                {
                    m_seen.erase(i);
                }
            }
        }
        void Renderer::rm_opject_by_name(std::string name)
        {
            for(int i=0;i<m_seen.size();i++)
            {
                if(m_seen.at(i).name == name)
                {
                    m_seen.erase(i);
                }
            }
        }
        void Renderer::rm_seen()
        {
            m_seen.clear();
        }
        void Renderer::ignore_by_id_status(int ID ,bool ignore)
        {
            for(int i=0;i<m_seen.size();i++)
            {
                if(m_seen.at(i).ID == ID)
                {
                    m_seen.at(i).ignore = ignore;
                }
            }
        }
        void Renderer::ignore_by_name_status(std::string name,bool ignore)
        {
            for(int i=0;i<m_seen.size();i++)
            {
                if(m_seen.at(i).name == name)
                {
                    m_seen.at(i).ignore = ignore;
                }
            }
        }
        void Renderer::add_camera(int ID, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f))
        {

        }
        void Renderer::make_camera_current(int ID)
        {}
        void Renderer::add_texture_camera(unsigned int *texture,glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f))
        {}
        void Renderer::draw()
        {}
        int command(std::function<int(Renderer_Args)> Fn)
        {
            return Fn({m_seen, m_camera, m_texture_camera})
        }
}
