#include <QtTest>

#include "test/testcsvloader.h"
#include "test/testellipsisproximityalgorithm.h"
#include "test/testgraph.h"
#include "test/testneighborhood.h"
#include "test/testpointofinterest.h"
#include "test/testuser.h"

int main(int argc, char** argv) {
    TestPointOfInterest test_poi;
    TestCsvLoader test_csv_loader;
    TestEllipsisProximityAlgorithm test_ellipsis_algorithm;
    TestGraph test_graph;
    TestUser test_user;
    TestNeighborhood test_neighborhood;

    return QTest::qExec(&test_poi, argc, argv) |
           QTest::qExec(&test_csv_loader, argc, argv) |
           QTest::qExec(&test_ellipsis_algorithm, argc, argv) |
           QTest::qExec(&test_graph, argc, argv) |
           QTest::qExec(&test_user, argc, argv) |
           QTest::qExec(&test_neighborhood, argc, argv);
}
