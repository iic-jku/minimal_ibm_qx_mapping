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

#include <QASMtoken.hpp>

std::map<Token::Kind, std::string> Token::KindNames = {
			{Kind::none,"none"},
			{Kind::include,"include"},
			{Kind::identifier,"<identifier>"},
			{Kind::number,"<number>"},
			{Kind::plus,"+"},
			{Kind::semicolon,";"},
			{Kind::eof,"EOF"},
			{Kind::lpar,"("},
			{Kind::rpar,")"},
			{Kind::lbrack,"["},
			{Kind::rbrack,"]"},
			{Kind::lbrace,"{"},
			{Kind::rbrace,"}"},
			{Kind::comma,","},
			{Kind::minus,"-"},
			{Kind::times,"*"},
			{Kind::nninteger,"<nninteger>"},
			{Kind::real,"<real>"},
			{Kind::qreg,"qreg"},
			{Kind::creg,"creg"},
			{Kind::ugate,"U"},
			{Kind::cxgate,"CX"},
			{Kind::gate,"gate"},
			{Kind::pi,"pi"},
			{Kind::measure,"measure"},
			{Kind::openqasm,"openqasm"},
			{Kind::probabilities,"probabilities"},
			{Kind::opaque,"opaque"},
			{Kind::sin,"sin"},
			{Kind::cos,"cos"},
			{Kind::tan,"tan"},
			{Kind::exp,"exp"},
			{Kind::ln,"ln"},
			{Kind::sqrt,"sqrt"},
			{Kind::div,"/"},
			{Kind::power,"^"},
			{Kind::string,"string"},
			{Kind::gt,">"},
			{Kind::barrier,"barrier"},
			{Kind::_if,"if"},
			{Kind::eq,"=="},
			{Kind::reset,"reset"}
	};
