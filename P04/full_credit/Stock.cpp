#include "stock.h"
#include <cmath>
#include <iostream>

Stock::Stock () : _weight(NAN){ };
Stock::Stock (double weight) : _weight(weight){ };
std::string Stock::ascii_art(int row) {/*yet to be added*/};


// art = { // Locomotive     "      * # @  ",
//     "     . ______",
//     "   _()_||__||",
//     "  ( cse1325 |",
//     " /-OO----OO''",
//     "#############", };

// art = { // Autocar     "     , * o @ ~ ",
//     "   .  _________",
//     "  ()_|[] [] []|",
//     " |            |",
//     " 'OO--------OO'",
//     "###############", };

// art = { // Coalcar     "         ",
//     "   .ggg.  ",
//     " _@@@@@@_",
//     " |      |",
//     "='OO--OO'",
//     "#########",
// };
