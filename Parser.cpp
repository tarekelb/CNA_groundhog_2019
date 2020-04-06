/*
** EPITECH PROJECT, 2020
** CNA_groundhog_2019
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(const int &clock)
{
    this->_clock = clock;
    this->_r = 0;
    this->_rTmp = 0;
    this->_checkFirst = false;
}

Parser::~Parser()
{
}

void Parser::rte() {
    if (this->_tempInput.size() <= this->_clock)
        return;
    
    double a = this->_tempInput[this->_tempInput.size() - this->_clock - 1];
    double b = this->_tempInput[this->_tempInput.size() - 1];

    this->_r = (int)(round((((b-a)/a) * 100)));
    this->_checkFirst = true;
}

void Parser::start() 
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    while (std::getline(std::cin, _buff)) {
        if (_buff == "STOP") {
            if (this->_tempInput.size() < _clock)
                exit (84);
            else {
                std::cout << "Global tendency switched " << nbSwitched << " times" << std::endl;
                exit (0);
            }
        }
        if (_buff == "")
            continue;
        try {
            _tempInput.push_back(std::stof(_buff));
        } catch (const std::exception& e) {
            std::cerr << "The value must be a décimal\n";
            exit (84);
        }
        Result();
    }
    std::cout << this->_tempInput.size() << std::endl;
    if (this->_tempInput.size() < _clock)
        exit (84);
    if (_buff != "STOP")
        exit (84);
}

void Parser::Result() 
{
    if (_tempInput.size() < _clock)
        std::cout << "g=nan\tr=nan%\ts=nan\n";
    else {
        this->_rTmp = _r;
        rte();
        GAvegerage();
        StandardDeviation();
        if (this->_checkFirst == true) {
            if ((this->_rTmp > 0 && this->_r < 0 && this->_checkFirst == true) || (this->_rTmp < 0 && this->_r > 0 && this->_checkFirst == true)) {
                std::cout << "g=" << _g << "\tr="<< this->_r << "%\ts=" << _sDeviation << "\ta switch occurs\n";
                nbSwitched += 1;
            }
            else
                std::cout << "g=" << _g << "\tr="<< this->_r << "%\ts=" << _sDeviation << "\n";
        } else
            std::cout << "g=nan\tr=nan%\ts=" << _sDeviation << "\n";
    }
}

void Parser::StandardDeviation()
{
    double sum = 0;
    double carrSum = 0;

    for (size_t a = _tempInput.size() - _clock; a < _tempInput.size(); a ++) {
        sum += _tempInput[a];
    }
    sum = sum / _clock;
    for (size_t a = _tempInput.size() - _clock; a < _tempInput.size(); a ++) {
        carrSum += pow((_tempInput[a] - sum), 2);
    }
    carrSum = carrSum / _clock;
    _sDeviation = sqrt(carrSum);
}

void Parser::GAvegerage()
{
    double result = 0;

    for (size_t a = _tempInput.size() - (this->_clock + 1); a < _tempInput.size(); a += 1)
        if (_tempInput[a + 1] - _tempInput[a] > 0)
            result += (_tempInput[a + 1] - _tempInput[a]);
    this->_g = (result / _clock);
}