


class drawing_place
{
    public:
        drawing_place()
        {
            glViewport(m_x, m_y, m_width, m_height);
        }
    privats:
    int m_x,m_y,m_width,m_height;


}
//Specify the lower left corner of the viewport rectangle, in pixels. The initial value is (0,0).
