//
// Created by stud-05 on 10/21/24.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MatrixLib.h"
TEST_SUITE("iNVERSEMATRIX") {
    TEST_CASE("testing inverse matrix function") {
        const vector<vector<double> >v {{1, 2},
                                        {3, 4}};
        const vector<vector<double> >v_inv {{-2, 1},
                                           {1.5, -0.5}};
        SquareMatrix<double>M(v);
        CHECK(M.reverse().get_matrix() == v_inv);



    }
    TEST_CASE("testing inverse matrix matrix2") {
        const vector<vector<double> >v {{1, 0, 0},
                                          {0, 1, 0},
                                          {0, 0, 1}};
        const vector<vector<double> >v_inv {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 1}};
        SquareMatrix<double>M(v);

        CHECK(M.reverse().get_matrix() == v_inv);
    }
    TEST_CASE("testing inverse matrix matrix3") {
        const vector<vector<double> >v {{0, 0, 0},
                                          {0, 1, 0},
                                          {0, 0, 1}};
        const vector<vector<double> >v_inv {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 1}};
        SquareMatrix<double>M(v);

        CHECK_THROWS_AS(M.reverse(), std::invalid_argument);
    }
    TEST_CASE("testing inverse matrix matrix4") {
        const vector<vector<double> >v;
        const vector<vector<double> >v_inv {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 1}};
        SquareMatrix<double>M(v);

        CHECK_THROWS_AS(M.reverse(), std::invalid_argument);
    }
}
TEST_SUITE("iNVERSEMATRIX2") {
    TEST_CASE("testing inverse matrix function") {
        const vector<vector<double> >v {{1, 2},
                                        {3, 4}};
        const vector<vector<double> >v_inv {{-2, 1},
                                           {1.5, -0.5}};
        SquareMatrix<double>M(v);
        CHECK(M.reverse().get_matrix() == v_inv);



    }
    TEST_CASE("testing inverse matrix matrix2") {
        const vector<vector<double> >v {{1, 0, 0},
                                          {0, 1, 0},
                                          {0, 0, 1}};
        const vector<vector<double> >v_inv {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 1}};
        SquareMatrix<double>M(v);

        CHECK(M.reverse().get_matrix() == v_inv);
    }
    TEST_CASE("testing inverse matrix matrix3") {
        const vector<vector<double> >v {{0, 0, 0},
                                          {0, 1, 0},
                                          {0, 0, 1}};
        const vector<vector<double> >v_inv {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 1}};
        SquareMatrix<double>M(v);

        CHECK_THROWS_AS(M.reverse(), std::invalid_argument);
    }
    TEST_CASE("testing inverse matrix matrix4") {
        const vector<vector<double> >v;
        const vector<vector<double> >v_inv {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 1}};
        SquareMatrix<double>M(v);

        CHECK_THROWS_AS(M.reverse(), std::invalid_argument);
    }
}