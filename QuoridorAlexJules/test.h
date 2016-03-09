#ifndef TEST
#define TEST
class Test{

public:

    static void runTest();
private:

    static void TestPlayerCase1();
    static void TestPlayerCase2();
    static void TestPlayerCase3();
    static void TestPlayerWallStock();
    static void TestPlayerPosition();
    static void TestFrameSide();
    static void TestFrameSide2();
    static void TestFramePrintContent();
    static void TestBoardCreateOK();
    static void TestBoardCreateKO();
    static void TestBoardIsFree();
    static void TestBoardIsFree2();
    static void TestFindPath();
    static void TestFindPathBlocked();
    static void TestFindPathFig4();
    static void TestEvalPosition();
    static void TestPlaceBoard();
    static void TestWinGame();
    static void TestBoardEmptyWall();
    static void TestBoardEmptyWallFail();
    static void TestGetlen();

    static void TestSideToString();

    static void TestPlayerConstrFail();
    static void TestPlayerConstrFail2();
    static void TestPlayerConstrOk();
    static void TestGetName();
   static void TestGetNum();

    static void TestPickWall();

};

#endif // TEST

