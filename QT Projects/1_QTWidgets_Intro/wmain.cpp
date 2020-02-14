#include "wmain.h"
#include "ui_wmain.h"

// Inicializar la Ventana
wmain::wmain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wmain)
{
    ui->setupUi(this);

    // Conectar Signals to slots
    // connect( ui-> "Objeto" ,
    //          SIGNAL ("la funcion del objeto"()),
    //          this (la clase a la que se referira),
    //          SLOT( "funcion que se llamara"(*argumentos = retorno de la funcion signal*)));

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(onButton1Pressed()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(onButton2Pressed()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(onButton3Pressed()));
}

// Destruir la Ventana
wmain::~wmain()
{
    delete ui;
}

void wmain::onButton1Pressed()
{
    ui->label->clear();
}

void wmain::onButton2Pressed()
{
    ui->label->setText("Pringado");
}

void wmain::onButton3Pressed()
{
    (ui->label->isHidden()) ? ui->label->show() : ui->label->hide();
}
