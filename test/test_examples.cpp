#include <BasicLinearAlgebra.h>
#include <gtest/gtest.h>

using namespace BLA;

namespace References
{
#include "../examples/References/References.ino"
}

TEST(Examples, References)
{
    References::setup();

    EXPECT_STREQ(Serial.buf.str().c_str(),
                 "bigMatrix(4,2): 45.67\n"
                 "bigMatrixRef: "
                 "[[-0.00,0.01,-0.17,0.01],[0.03,-0.01,0.08,-0.01],[-0.01,0.00,-0.05,0.02],[-0.00,0.00,0.13,-0.01]]\n"
                 "result of convoluted operation: [[1.11,1.12,0.95,1.12],[1.14,1.10,1.20,1.10]]\n"
                 "bigMatrix: "
                 "[[0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00],"
                 "[0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00],"
                 "[0.00,1.11,1.12,0.95,1.12,0.00,0.00,0.00],"
                 "[0.00,1.14,1.10,1.20,1.10,0.00,0.00,0.00],"
                 "[0.00,0.00,-0.00,0.01,-0.17,0.01,0.00,0.00],"
                 "[0.00,0.00,0.03,-0.01,0.08,-0.01,0.00,0.00],"
                 "[0.00,0.00,-0.01,0.00,-0.05,0.02,0.00,0.00],"
                 "[0.00,0.00,-0.00,0.00,0.13,-0.01,0.00,0.00]]");
}

namespace SolveLinearEquations
{
#include "../examples/SolveLinearEquations/SolveLinearEquations.ino"
}

TEST(Examples, SolveLinearEquations)
{
    SolveLinearEquations::setup();

    std::cout << Serial.buf.str();

    EXPECT_STREQ(Serial.buf.str().c_str(),
                 "P: [[0.00,0.00,1.00,0.00,0.00,0.00],[1.00,0.00,0.00,0.00,0.00,0.00],"
                 "[0.00,0.00,0.00,0.00,0.00,1.00],[0.00,0.00,0.00,1.00,0.00,0.00],"
                 "[0.00,0.00,0.00,0.00,1.00,0.00],[0.00,1.00,0.00,0.00,0.00,0.00]]\n"
                 "L: [[1.00,0.00,0.00,0.00,0.00,0.00],[0.17,1.00,0.00,0.00,0.00,0.00],"
                 "[0.55,-0.75,1.00,0.00,0.00,0.00],[0.90,-0.63,0.57,1.00,0.00,0.00],"
                 "[0.46,0.68,0.13,0.41,1.00,0.00],[0.02,0.49,0.17,-0.09,-0.04,1.00]]\n"
                 "U: [[96.00,98.00,50.00,80.00,78.00,27.00],[0.00,61.67,41.67,70.67,57.00,58.50],"
                 "[0.00,0.00,67.55,105.67,40.55,118.83],[0.00,0.00,0.00,-77.31,-15.08,41.02],"
                 "[0.00,0.00,0.00,0.00,-57.71,-25.19],[0.00,0.00,0.00,0.00,0.00,-30.08]]\n"
                 "reconstructed A: "
                 "[[53.00,8.00,64.00,97.00,41.00,90.00],[96.00,98.00,50.00,80.00,78.00,27.00],"
                 "[2.00,32.00,33.00,61.00,40.00,17.00],[86.00,49.00,57.00,10.00,42.00,96.00],"
                 "[44.00,87.00,60.00,67.00,16.00,59.00],[16.00,78.00,50.00,84.00,70.00,63.00]]\n"
                 "x (via LU decomposition): [[-0.34],[-1.24],[8.40],[-1.96],[1.05],[-3.55]]\n"
                 "x (via inverse A): [[-0.34],[-1.24],[8.40],[-1.96],[1.05],[-3.55]]");
}

namespace Tensor
{
#include "../examples/Tensor/Tensor.ino"
}

TEST(Examples, Tensor)
{
    Tensor::setup();

    EXPECT_STREQ(Serial.buf.str().c_str(),
                 "Hyper B: "
                 "[[[[6.00,10.00],[10.00,18.00]],[[10.00,14.00],[18.00,26.00]]],[[[10.00,18.00],[14.00,26.00]],[[18.00,"
                 "26.00],[26.00,38.00]]]]");
}

namespace CustomMatrix
{
#include "../examples/CustomMatrix/CustomMatrix.ino"
}

TEST(Examples, CustomMatrix)
{
    CustomMatrix::setup();

    EXPECT_STREQ(
        Serial.buf.str().c_str(),
        "still ones: [[1.00,1.00,1.00,1.00],[1.00,1.00,1.00,1.00],[1.00,1.00,1.00,1.00],[1.00,1.00,1.00,1.00]]\n"
        "scaled rows: [[1.00,1.00,1.00,1.00],[2.00,2.00,2.00,2.00],[3.00,3.00,3.00,3.00],[4.00,4.00,4.00,4.00]]");
}

namespace HowToUse
{
#include "../examples/HowToUse/HowToUse.ino"
}

TEST(Examples, HowToUse)
{
    HowToUse::setup();

    EXPECT_STREQ(Serial.buf.str().c_str(),
                 "v(1): 43.67\n"
                 "B: [[9.79,9.33,11.62],[7.77,14.77,14.12],[11.33,15.72,12.12]]\n"
                 "identity matrix: [[1.00,-0.00,-0.00],[0.00,1.00,-0.00],[0.00,0.00,1.00]]");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
