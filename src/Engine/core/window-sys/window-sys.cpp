#include<window-sys.h>
#include<iostream>
namespace rose
{
window_sys::window_sys(window_data data)
{
    rose::log::init();
    glfwInit();
    if(data.Graphics_API)
    {
        std::cout<<"we dosent support vulkan yet\n";
    }
    else
    {
        glfwWindowHint(GLFW_CENTER_CURSOR, data.CenterCursor);
        glfwWindowHint(GLFW_MAXIMIZED, data.maximized);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        if (glfwPlatformSupported(GLFW_PLATFORM_WAYLAND))
        {
            CORE_INFO("runs in wayland");
            glfwWindowHint(GLFW_PLATFORM,GLFW_PLATFORM_WAYLAND);
        }
        else
        {
            CORE_INFO("runs in Xorg or Xwayland");
        }
    }
    if(data.window_mode == 0)
    {
        CORE_TRACE("draw in a windowed window");
        m_window = glfwCreateWindow(data.width, data.hight, data.window_name.c_str(), NULL, NULL);
    }
    if(data.window_mode == 1)
        {
            CORE_TRACE("draw in full secreen");
            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
            m_window = glfwCreateWindow(mode->width, mode->height, data.window_name.c_str(), glfwGetPrimaryMonitor(), NULL);
        }
    if(data.window_mode == 2)
        {
            CORE_TRACE("draw in a borderless window");
            m_window = glfwCreateWindow(data.width, data.hight, data.window_name.c_str(), glfwGetPrimaryMonitor(), NULL);
        }
        
    if (!m_window)
    {
        CORE_ERROR("window system failure: recomed opengl version 4.2.x or higher");
    }
        glfwSwapInterval(data.VSync_mode);
        glfwMakeContextCurrent(m_window);
        if(data.Graphics_API)
        {
            std::cout<<"we dosent support vulkan yet\n";
        }
        else
        {
            glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int hight)
            {
                glViewport(0, 0, width, hight);
            });
        }
    }
}
