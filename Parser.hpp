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
        double _g;
        double _s;
        double _r;
        double _rTmp;
        std::vector <double> _tempInput;
        std::vector <double> _weirdValue;
        std::string _buff;
        int nbSwitched;
        double _sDeviation;
};

#endif /* !PARSER_HPP_ */
