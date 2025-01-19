#include "all_component.h"

all_component::all_component(QWidget *parent)
    : QWidget(parent){
    //600 400
    this->resize(540, 300);
    this->setStyleSheet(""
                        "background-color: #cecccc;");
}

all_component::~all_component() {}
