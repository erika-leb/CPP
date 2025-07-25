# include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// int main() {
//     std::cout << "===== TEST DES CONSTRUCTEURS =====" << std::endl;
//     Fixed a;               // constructeur par défaut
//     Fixed b(10);           // int
//     Fixed c(42.42f);       // float
//     Fixed d(b);            // constructeur de copie
//     a = Fixed(5.5f);       // opérateur d'affectation

//     std::cout << "a = " << a << std::endl;
//     std::cout << "b = " << b << std::endl;
//     std::cout << "c = " << c << std::endl;
//     std::cout << "d = " << d << std::endl;

//     std::cout << "\n===== TEST DES CONVERSIONS =====" << std::endl;
//     std::cout << "c toInt() = " << c.toInt() << std::endl;
//     std::cout << "c toFloat() = " << c.toFloat() << std::endl;

//     std::cout << "\n===== TEST DES OPERATEURS ARITHMETIQUES =====" << std::endl;
//     Fixed e = b + c;
//     Fixed f = c - b;
//     Fixed g = b * c;
//     Fixed h = c / b;

//     std::cout << "b + c = " << e << std::endl;
//     std::cout << "c - b = " << f << std::endl;
//     std::cout << "b * c = " << g << std::endl;
//     std::cout << "c / b = " << h << std::endl;

//     std::cout << "\n===== TEST DES COMPARAISONS =====" << std::endl;
//     std::cout << "b < c ? " << (b < c) << std::endl;
//     std::cout << "b > c ? " << (b > c) << std::endl;
//     std::cout << "b <= c ? " << (b <= c) << std::endl;
//     std::cout << "b >= c ? " << (b >= c) << std::endl;
//     std::cout << "b == c ? " << (b == c) << std::endl;
//     std::cout << "b != c ? " << (b != c) << std::endl;

//     std::cout << "\n===== TEST DES INCREMENTATIONS =====" << std::endl;
//     Fixed i;
//     std::cout << "i = " << i << std::endl;
//     std::cout << "++i = " << ++i << std::endl;
//     std::cout << "i++ = " << i++ << std::endl;
//     std::cout << "i = " << i << std::endl;
//     std::cout << "--i = " << --i << std::endl;
//     std::cout << "i-- = " << i-- << std::endl;
//     std::cout << "i = " << i << std::endl;

//     std::cout << "\n===== TEST DES FONCTIONS MIN/MAX =====" << std::endl;
//     Fixed x(1.5f);
//     Fixed y(2.5f);

//     std::cout << "min(x, y) = " << Fixed::min(x, y) << std::endl;
//     std::cout << "max(x, y) = " << Fixed::max(x, y) << std::endl;

//     const Fixed cx(3.3f);
//     const Fixed cy(4.4f);
//     std::cout << "const min(cx, cy) = " << Fixed::min(cx, cy) << std::endl;
//     std::cout << "const max(cx, cy) = " << Fixed::max(cx, cy) << std::endl;

//     return 0;
// }
