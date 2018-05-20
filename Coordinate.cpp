//
// Created by ehud on 19/05/18.
//

#include "Coordinate.h"
Coordinate::Coordinate(int x, int y) {
    this->m_x=x;
    this->m_y=y;
}
int Coordinate::get_y() const {
    return this->m_y;
}
int Coordinate::get_x() const {
    return this->m_x;

}