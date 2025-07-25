# include "Point.hpp"

int main(void)
{
    Point a(-3.0f, -1.0f);
    Point b(4.0f, -2.0f);
    Point c(1.0f, 6.0f);

    // Points à tester
    Point inside(0.0f, 1.0f);
    Point on_edge(1.0f, 6.0f);       // sur le sommet C
    Point on_vertex(-3.0f, -1.0f);   // sur le sommet A
    Point outside(4.0f, 5.0f);
    Point edge_mid(-1.0f, 2.5f);     // au milieu de AC
    Point far_outside(10.0f, 10.0f);

    std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point on edge: " << bsp(a, b, c, edge_mid) << std::endl;
    std::cout << "Point on vertex: " << bsp(a, b, c, on_vertex) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Point far outside: " << bsp(a, b, c, far_outside) << std::endl;
    std::cout << "Point on C vertex: " << bsp(a, b, c, on_edge) << std::endl;

    return 0;
}
