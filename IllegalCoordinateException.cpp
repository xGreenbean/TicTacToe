//
// Created by ehud on 06/05/18.
//
#include <vector>
#include "IllegalCoordinateException.h"
/**
 * class "to_string"
 * @return string
 */
string IllegalCoordinateException::theCoordinate() const{
    string coordinates=to_string(this->x)+","+to_string(this->y);
    return coordinates;
}
/**
 * builder
 * @param xx x coordinate (row)
 * @param yy y coordinate (column)
 */
IllegalCoordinateException::IllegalCoordinateException(int xx,int yy) {
    this->x=xx;
    this->y=yy;

}