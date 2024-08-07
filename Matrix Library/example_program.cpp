#include <iostream>
#include <Eigen/Dense>

// int main() {
//     Eigen::MatrixXd m(3, 3);
//     m << 1, 2, 3,
//          4, 5, 6,
//          7, 8, 9;
//     std::cout << m << std::endl;
//     return 0;
// }

// int main() {
//     Eigen::Matrix3d p;
//     Eigen::Matrix3d q;

//     // Define two three−dimensional vectors
//     // The constructor provides initialisation
//     Eigen::Vector3d r(1,2,3);
//     Eigen::Vector3d s(4,5,6);

//     // Use the << operator to fill the matrices
//     p << 1,2,3,
//          4,5,6,
//          7,8,9;
//     q << 10, 11, 12,
//          13, 14, 15,
//          16, 17, 18;

//     // Output arithmetic operations for matrices
//     std::cout << "p+q =\n" << p + q << std::endl;
//     std::cout << "p-q =\n" << p - q << std::endl;

//     // Output arithmetic operations for matrices
//     std::cout << "r+s =\n" << r + s << std::endl;
//     std::cout << "r-s =\n" << r - s << std::endl;
// }

// int main() {
//     Eigen::Matrix3d p;
//     p << 1, 2, 3,
//          4, 5, 6,
//          7, 8, 9;
//     std::cout << "p * 3.14159 = \n" << p * 3.14159 << std::endl;
//     std::cout << "p / 2.71828 = \n" << p / 2.71828 << std::endl;
// }

// int main() {

//     // Declare a 3x3 matrix with random entries
//     Eigen:: Matrix3d p = Eigen::Matrix3d::Random(3 ,3);

//     // Output the transpose of p
//     std::cout << "p^T =\n" << p.transpose() << std::endl;

//     // In−place transposition
//     p.transposeInPlace();

//     // Output the in−place transpose of p
//     std::cout << "p^T =\n" << p << std::endl; 
// }

int main() {
    // Define a 3x3 matrix and two 3−dimensional vectors
    Eigen::Matrix3d p;
    p << 1,2,3,
         4,5,6,
         7,8,9;
    Eigen::Vector3d r(10, 11, 12); 
    Eigen::Vector3d s(13, 14, 15);

    // Matrix/matrix multiplication
    std::cout << "p*p:\n" << p*p << std::endl;

    // Matrix/vector multiplication
    std::cout << "p*r:\n" << p*r << std::endl;
    std::cout << "r^T*p:\n" << r.transpose()*p << std::endl;

    // Vector/vector multiplication (inner product)
    std::cout << "r^T*s:\n" << r.transpose()*s << std::endl;
}