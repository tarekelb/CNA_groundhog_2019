/*
** EPITECH PROJECT, 2020
** CNA_groundhog_2019
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cmath>

class Parser {
    public:
        Parser(const int &clock);
        ~Parser();
        void rte();
        void start();
        void Result();
        void StandardDeviation();
        void GAvegerage();
    protected:
    private:
        bool _checkFirst;
        unsigned int _clock;
        long double _g;
        long double _s;
        long double _r;
        long double _rTmp;
        std::vector <double> _tempInput;
        std::vector <double> _weirdValue;
        std::string _buff;
        long int nbSwitched;
        long double _sDeviation;
};

#endif /* !PARSER_HPP_ */
