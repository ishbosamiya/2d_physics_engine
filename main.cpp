#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#undef main
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "circle.h"
#include "Frame_Functions.h"

using namespace std;

int width = 500, height = 500;

void drawLineOnScreen(line m_line, float line_width = 2);

point getMousePostion()
{
    int mouse_position_X, mouse_position_Y;

    SDL_GetMouseState(&mouse_position_X, &mouse_position_Y);

    //cout << "Mouse Position: " << mouse_position_X << " " << mouse_position_Y << endl;

    point mouse_position;

    mouse_position.X = ((float)mouse_position_X - ((float)height / 2.0)) / ((float)height / 2);

    mouse_position.Y = -((float)mouse_position_Y - ((float)height / 2.0)) / ((float)height / 2);

    cout << "Mouse Position: " << mouse_position.X << " " << mouse_position.Y << endl;

    return mouse_position;
}

void setFps(int fps = 30)
{
    static Uint32 time_start = SDL_GetTicks();

    static int time_delay = 1000.0 / fps;

    SDL_Delay(time_delay - ((SDL_GetTicks() - time_start) % time_delay));
}

int main()
{
    int choice = 2;
    int move_to_sim = 0;
    int no_of_clicks = 0;
    SDL_Event event;

    //declaring the circles
    circle phycircle;

    //declaring the center of the circles
    point centre[1];
    centre[0].X = 0.0;
    centre[0].Y = 1;
    float radius = 0.2;

    line m_line[3];
    //line 1

    std::cout << "Input screen size: ";
    std::cin >> width;

    height = width;

    /*
    std::cout << "1) Input Line Points" << std::endl;
    std::cout << "2) Use Default Points" << std::endl;
    std:: cin >> choice;


    if(choice == 1) {
        std::cout << "Input Line Points: ";
        std::cin >> m_line[0].points[0].X >> m_line[0].points[0].Y >> m_line[0].points[1].X >> m_line[0].points[1].Y;
    }
    else {
        m_line[0].points[0].X = -1;
        m_line[0].points[0].Y = -0.7;
        m_line[0].points[1].X = 1;
        m_line[0].points[1].Y = -0.6;
    }
    m_line[0] = makeLineWith2Points(m_line[0].points[0], m_line[0].points[1]);
    fixedLine = m_line[0];
    //fixedLine.slope = 0;
    //fixedLine.intercept = -0.3;

    */

    m_line[0].points[0].X = -1.8;
    m_line[0].points[0].Y = -1.8;
    m_line[0].points[1].X = -1.8;
    m_line[0].points[1].Y = -1.8;

    phycircle.setInitValues(radius, centre[0]);

    Display display(width, height, "Hello World");

    Shader shader("./res/basicShader");

    bool mouse_click_1 = false;
    bool mouse_click_2 = false;

    //getting line input from user using clicks
    while(!display.isClosed()) {
        glClearColor(0, 0, 0.2, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.Bind();

        SDL_WaitEventTimeout(&event, 1000);

        if(mouse_click_1 == false) {
            m_line[0].points[0] = getMousePostion();
            m_line[0].points[1] = getMousePostion();
        }
        else {
            m_line[0].points[1] = getMousePostion();
        }

        switch(event.type) {
            case SDL_MOUSEBUTTONDOWN:
            case SDL_MOUSEBUTTONUP:
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        if(mouse_click_1 == false)
                            m_line[0].points[1] = getMousePostion();
                        m_line[0].points[0] = getMousePostion();
                        mouse_click_1 = true;
                        std::cout << "Click 1" << std::endl;
                        break;
                    case SDL_BUTTON_RIGHT:
                        m_line[0].points[1] = getMousePostion();
                        std::cout << "Click 2" << std::endl;
                        mouse_click_2 = true;
                        break;
                }
                break;
        }

        /*
        switch(event.type) {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_SPACE:
                        mouse_click_2 = true;
                }
        }
        */

        m_line[0] = makeLineWith2Points(m_line[0].points[0], m_line[0].points[1]);
        drawLineOnScreen(m_line[0]);

        display.update();

        setFps(30);

        if(mouse_click_2 == true)
            break;
    }

    fixedLine = m_line[0];

    std::cout << m_line[0].points[0].X << " " << m_line[0].points[0].Y << std::endl;
    std::cout << m_line[0].points[1].X << " " << m_line[0].points[1].Y << std::endl;

    while(!display.isClosed()) {
        glClearColor(0, 0, 0.2, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();

        circleStruct test = phycircle.getCircleInfo();

        m_drawCircle(phycircle.getCircleInfo());

        getMousePostion();

        drawLineOnScreen(m_line[0]);

        everyFrameForCircle(phycircle);
        //std::cout << phycircle.getCircleInfo().centre.X << " " << phycircle.getCircleInfo().centre.Y << std::endl;

        display.update();

        setFps(30);

        SDL_PollEvent(&event);
        switch(event.type) {
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        SDL_Quit();
                }
        }
    }

    return 0;
}

void drawLineOnScreen(line m_line, float line_width)
{
    m_line.points[0].Y;
    m_line.points[1].X;
    m_line.points[1].Y;

    glLineWidth(line_width);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(m_line.points[0].X, m_line.points[0].Y, 0.0);
    glVertex3f(m_line.points[1].X, m_line.points[1].Y, 0.0);
    glEnd();
}
