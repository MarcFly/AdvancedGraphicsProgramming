#ifndef WMAIN_H
#define WMAIN_H

#include <QMainWindow>

namespace Ui {
class wmain;
}

// La clase en si guarda los callbacks que se ejecutan y tal

class wmain : public QMainWindow
{
    Q_OBJECT // MACRO SUPER IMPORTANTE, cosas de QT necesarias en cada clase que creas

public:
    explicit wmain(QWidget *parent = nullptr); //
    ~wmain();

private:
    Ui::wmain *ui; // Es la struct que te guarda los widgets hechos con el designer

public slots: // Aqui van las funciones respecto las cosas
    //Ensenyar texto, funcion de tipo requiere un signal del tipo
    void onButton1Pressed();
    void onButton2Pressed();
    void onButton3Pressed();
};

#endif // WMAIN_H
