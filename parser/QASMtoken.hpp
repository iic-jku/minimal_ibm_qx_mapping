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

#ifndef TOKEN_H_
#define TOKEN_H_

#include <map>

class Token {
 public:

	enum class Kind {include, none, identifier, number, plus, semicolon, eof, lpar, rpar, lbrack, rbrack, lbrace, rbrace, comma, minus, times, nninteger, real, qreg, creg, ugate, cxgate, gate, pi, measure, openqasm, probabilities, sin, cos, tan, exp, ln, sqrt, div, power, string, gt, barrier, opaque, _if, eq, reset, snapshot};

	Token(Kind kind, int line, int col) {
		this->kind = kind;
		this->line = line;
		this->col = col;
		this->val = 0;
		this->valReal = 0.0;
	}

	Token() : Token(Kind::none, 0, 0) {
	}

	static std::map<Kind, std::string> KindNames;
	Kind kind;
	int line;
	int col;
	int val;
	double valReal;
	std::string str;

 };

#endif /* TOKEN_H_ */
