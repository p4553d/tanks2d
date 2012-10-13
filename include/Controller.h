/**
 * @file Controller.h
 * @author user p4553d
 * @section DESCRIPTION
 *
 */

#ifndef _CONTROLLER_H
#define _CONTROLLER_H

class Controller {
public:
    static Controller& getInstance();

    static void keyboard(unsigned char key, int posX, int posY);
    static void keyboardSpecial(int key, int poX, int posY);

private:
    Controller();
    Controller(const Controller&){}
    Controller & operator= (const Controller&);
};
#endif
