/*
Minimal Mapping of Quantum Circuits to IBM QX Architectures by JKU Linz, Austria

Developer: Robert Wille, Lukas Burgholzer, Alwin Zulehner

For more information, please visit http://iic.jku.at/eda/research/ibm_qx_mapping

If you have any questions feel free to contact us using
robert.wille@jku.at, lukas.burgholzer@jku.at or alwin.zulehner@jku.at

If you use the compiler for your research, we would be thankful if you referred to it
by citing the following publication:

@inproceedings{wille2019mapping,
    title={Mapping Quantum Circuits to {IBM QX} Architectures Using the Minimal Number of {SWAP} and {H} Operations},
    author={Wille, Robert and Burgholzer, Lukas and Zulehner, Alwin},
    booktitle={Design Automation Conference},
    year={2019}
}
*/

#ifndef QASMSCANNER_HPP_
#define QASMSCANNER_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <sstream>
#include <stack>
#include <string>

#include <QASMtoken.hpp>

class QASMscanner {


public:
    explicit QASMscanner(std::istream& in_stream);
    Token next();
    void addFileInput(const std::string& fname);

private:
  	std::istream& in;
  	std::stack<std::istream*> streams;
  	char ch;
  	std::map<std::string, Token::Kind> keywords;
  	int line;
    int col;
    void nextCh();
    void readName(Token& t);
    void readNumber(Token& t);
    void readString(Token& t);
    void skipComment();

    class LineInfo {
    public:
    	char ch;
    	int line, col;

    	LineInfo(char ch, int line, int col) {
    		this->ch = ch;
    		this->line = line;
    		this->col = col;
    	}
    };

  	std::stack<LineInfo> lines;

};

#endif /* QASMSCANNER_HPP_ */
