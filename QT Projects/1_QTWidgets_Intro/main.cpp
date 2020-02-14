#include "wmain.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Crea la aplicacion, el controller
    wmain w; // Clase main del proyecto
    w.show(); // Enseña

    return a.exec(); // Ejecuta la app
}
